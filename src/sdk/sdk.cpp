/*
 * Copyright 2012 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Flora License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://floralicense.org/license/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "scleventcallback.h"
#include "ise.h"
#include "sdk.h"
#include "option.h"
#include "common.h"

using namespace scl;

/*
 * This callback class will receive all response events from SCL
 * So you should perform desired tasks in this class.
 */

class CSDKISE : public ISCLUIEventCallback, public ILanguageCallback
{
public :
    CSDKISE() {
        /* Our CSDKISE instance will handle the following input modes... */
        sclint loop;

        for (loop = 0;loop < get_lang_table_size();loop++) {
            INPUT_MODE_INFO input_mode_QTY;
            input_mode_QTY.name = get_lang_table()[loop].inputmode_QTY;
            input_mode_QTY.display_name = get_lang_table()[loop].inputmode_QTY_name;
            LANGUAGE_INFO language;
            language.name = get_lang_table()[loop].language;
            language.display_name = get_lang_table()[loop].language_name;
            language.callback = this;
            language.input_modes.push_back(input_mode_QTY);
            language.priority = LANGAUGE_PRIORITY_DEFAULT;
            language.resource_file = MAIN_ENTRY_XML_PATH;
            language.is_latin_language = get_lang_table()[loop].is_latin_language;
            language.accepts_caps_mode = get_lang_table()[loop].accepts_caps_mode;

            /* These variable should be read from stored setting values */
            language.enabled = TRUE;
            language.selected_input_mode = input_mode_QTY.name;

            ISELanguageManager::add_language(language);
        }
    }
    SCLEventReturnType on_event_key_clicked(SclUIEventDesc event_desc);

    sclboolean on_language_selected(const sclchar *language, const sclchar *input_mode);
    sclboolean on_language_unselected(const sclchar *language, const sclchar *input_mode);

    sclboolean flush_imengine(const sclchar *language);
    private:
        SCLEventReturnType process_key_type_char(const SclUIEventDesc&);
};

static CSDKISE ise_instance;

extern CSCLUI *gSCLUI;
extern CISECommon *g_ise_common;
extern CONFIG_VALUES g_config_values;
extern KEYBOARD_STATE g_keyboard_state;

SCLEventReturnType
CSDKISE::process_key_type_char(const SclUIEventDesc& event_desc)
{
    // patch for Chinese symbol ^
    // Chinese engine will regards ^ as ……
    // this patch is to avoid this
    if (0 == strcmp(ISELanguageManager::get_current_language(), "Chinese")) {
        if (event_desc.key_event == '^') {
            ise_forward_key_event(event_desc.key_event);
            return SCL_EVENT_DONE;
        }
    }
    // patch for Chinese symbol ^ end
    /* If longkey symbol was pressed, let's flush the preedit buffer */
    if (event_desc.key_modifier == KEY_MODIFIER_LONGKEY) {
        flush_imengine(ISELanguageManager::get_current_language());
    }


    return SCL_EVENT_PASS_ON;
}

SCLEventReturnType CSDKISE::on_event_key_clicked(SclUIEventDesc event_desc)
{
    SCLEventReturnType ret = SCL_EVENT_PASS_ON;

    switch (event_desc.key_type) {
        case KEY_TYPE_CHAR:
            ret = process_key_type_char(event_desc);
            break;
        case KEY_TYPE_STRING:
            flush_imengine(ISELanguageManager::get_current_language());
            break;
        case KEY_TYPE_MODECHANGE:
            {
                flush_imengine(ISELanguageManager::get_current_language());
            }
            break;
        case KEY_TYPE_CONTROL:
        /* Do not flush when the entered key is one of : BACKSPACE / SHIFT / CAPSLOCK / SHIFTLOCK */
        if (event_desc.key_event != MVK_BackSpace &&
            event_desc.key_event != MVK_Shift_L &&
            event_desc.key_event != MVK_Caps_Lock &&
            event_desc.key_event != MVK_Shift_Lock &&
            event_desc.key_event != MVK_space &&
            event_desc.key_event != MVK_Return) {
            flush_imengine(ISELanguageManager::get_current_language());
        }
        if (event_desc.key_event == MVK_space) {
            if (ISELanguageManager::get_enabled_languages_num() > 1) {
                if (event_desc.key_modifier == KEY_MODIFIER_DIRECTION_LEFT) {
                    /* If flick event upon space key was detected, perform a language change and don't proceed anymore */
                    ISELanguageManager::select_previous_language();
                    ret = SCL_EVENT_DONE;
                }
                if (event_desc.key_modifier == KEY_MODIFIER_DIRECTION_RIGHT) {
                    /* If flick event upon space key was detected, perform a language change and don't proceed anymore */
                    ISELanguageManager::select_next_language();
                    ret = SCL_EVENT_DONE;
                }
            } else {
                if (event_desc.key_modifier == KEY_MODIFIER_DIRECTION_LEFT ||
                    event_desc.key_modifier == KEY_MODIFIER_DIRECTION_LEFT_RETURN) {
                        /* If flick event upon space key was detected, perform a cursor movement and don't proceed anymore */
                        ise_send_event(MVK_Left, 0);
                        ret = SCL_EVENT_DONE;
                }
                if (event_desc.key_modifier == KEY_MODIFIER_DIRECTION_RIGHT ||
                    event_desc.key_modifier == KEY_MODIFIER_DIRECTION_RIGHT_RETURN) {
                        /* If flick event upon space key was detected, perform a cursor movement and don't proceed anymore */
                        ise_send_event(MVK_Right, 0);
                        ret = SCL_EVENT_DONE;
                }
            }
        }
        break;
    default:
        break;
    }

    return ret;
}

sclboolean CSDKISE::on_language_selected(const sclchar *language, const sclchar *input_mode)
{
    sclboolean ret = FALSE;

    /* We have to change these url postfixes with corresponding language-specific ones */
    const char *url_postfixes[] = {".co.us", ".or.us", ".ac.us", ".go.us"};
    const char *replace_target = "us";

    if (language) {
        sclint loop;
        for (loop = 0;loop < get_lang_table_size();loop++) {
            if (strcmp(language, get_lang_table()[loop].language) == 0) {
                if (g_ise_common) {
                    if (get_lang_table()[loop].keyboard_ise_uuid) {
                        g_ise_common->set_keyboard_ise_by_uuid(get_lang_table()[loop].keyboard_ise_uuid);
                        g_ise_common->send_imengine_event(-1, get_lang_table()[loop].keyboard_ise_uuid,
                            get_lang_table()[loop].language_command, get_lang_table()[loop].language_code);
                    }
                }
                if (gSCLUI) {
                    /* This is to update the screen only for once, not everytime we request a UI update  */
                    gSCLUI->set_update_pending(TRUE);
                    gSCLUI->set_input_mode(input_mode);
                    /* Check if we need to turn on the shift key */
                    if (g_keyboard_state.caps_mode) {
                        LANGUAGE_INFO *info = ISELanguageManager::get_language_info(language);
                        if (info) {
                            if (info->accepts_caps_mode) {
                                gSCLUI->set_shift_state(SCL_SHIFT_STATE_ON);
                            }
                        }
                    }
                    /* And set the url postfixes */
                    for (sclint inner_loop = 0;inner_loop < (sizeof(url_postfixes) / sizeof (const char *));inner_loop++) {
                        std::string postfix = url_postfixes[inner_loop];
                        std::string::size_type offset = postfix.find(replace_target, 0);

                        if(offset != postfix.npos) {
                            postfix.replace(offset, strlen(replace_target), get_lang_table()[loop].country_code_URL);
                        }

                        gSCLUI->set_string_substitution(url_postfixes[inner_loop], postfix.c_str());
                    }

                    /* Replace LANGUAGE_STRING with localized language name */
                    gSCLUI->set_string_substitution(LANGUAGE_STRING, get_lang_table()[loop].language_name);

                    /* Now we update the whole screen */
                    gSCLUI->set_update_pending(FALSE);
                }

                ret = TRUE;
            }
        }
    }

    if (ret) {
        g_ise_common->update_input_context(ECORE_IMF_INPUT_PANEL_LANGUAGE_EVENT, 0);
    }

    return ret;
}

sclboolean CSDKISE::on_language_unselected(const sclchar *language, const sclchar *input_mode)
{
    sclboolean ret = FALSE;

    if (language) {
        sclint loop;
        for (loop = 0;loop < get_lang_table_size();loop++) {
            if (strcmp(language, get_lang_table()[loop].language) == 0) {
                flush_imengine(language);
                ret = TRUE;
            }
        }
    }

    return ret;
}

static inline int get_lang_id(const sclchar* language) {
    if (language == NULL) return -1;

    for (int loop = 0;loop < get_lang_table_size();loop++) {
        if (strcmp(language, get_lang_table()[loop].language) == 0) {
            if (get_lang_table()[loop].keyboard_ise_uuid) {
                return loop;
            }
        }
    }
    return -1;
}

sclboolean CSDKISE::flush_imengine(const sclchar *language)
{
    bool bRet = false;

    sclint loop;
    if (g_ise_common) {
        int lang_id = get_lang_id(language);
        if (lang_id != -1) {
            if (get_lang_table()[lang_id].flush_code != 0) {
                g_ise_common->send_imengine_event(-1, get_lang_table()[lang_id].keyboard_ise_uuid,
                        get_lang_table()[lang_id].flush_command, get_lang_table()[lang_id].flush_code);
                bRet = true;
            } else {
                g_ise_common->reset_keyboard_ise();
                bRet = true;
            }

        }
    }

    return bRet;
}