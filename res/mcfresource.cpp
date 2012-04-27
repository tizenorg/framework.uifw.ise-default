/*
Copyright (c) 2000-2012 Samsung Electronics Co., Ltd All Rights Reserved

This file is part of ise-default
Written by Ashish Malhotra <a.malhotra@samsung.com>

PROPRIETARY/CONFIDENTIAL

This software is the confidential and proprietary information of
SAMSUNG ELECTRONICS ("Confidential Information"). You shall not
disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered
into with SAMSUNG ELECTRONICS.

SAMSUNG make no representations or warranties about the suitability
of the software, either express or implied, including but not limited
to the implied warranties of merchantability, fitness for a particular
purpose, or non-infringement. SAMSUNG shall not be liable for any
damages suffered by licensee as a result of using, modifying or
distributing this software or its derivatives.
*/

#include <stdio.h>
#include "mcftypes.h"
#include "mcfconfig.h"
#include "mcfstructs.h"
#include "mcfresource.h"

McfLayout mcf_layout[MAX_LAYOUT] = {
    /* base layout */
    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_4X4_DEFAULT", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_4X4_SYM", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_4X4_IPv6_123", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_4X4_IPv6_ABC", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_4X4_NUMONLY", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_4X4_MONTH", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_QTY_DEFAULT", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_AZT_DEFAULT", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE}, 

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_QTY_URL", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_QTY_EMAIL", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "PORTRAIT_QTY_RUSSIAN", 0, 0, 480, 360,
    {PORTRAIT_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_QTY_RUSSIAN", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_QTY_DEFAULT", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},	

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_AZT_FRENCH", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},	

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_QTY_URL", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},		

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_QTY_EMAIL", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, TRUE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},		

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_4X4_NUM", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},		

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_4X4_PASSWD", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_4X4_IPv6_123", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_4X4_IPv6_ABC", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_BASE, "LANDSCAPE_4X4_NUMONLY", 0, 0, 800, 288,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_POPUP, "POPUP_4X4_DEFAULT", 0, 0, 126, 410,
    {LANDSCAPE_DEFAULT_BG_IMG, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_PORTRAIT, FALSE},

    {USED, LAYOUT_STYLE_POPUP, "POPUP_PUNCTUATION", 0, 0, 358, 268,
    {POPUP_BG_IMG_1, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_POPUP, "POPUP_EMOTICON", 0, 0, 358, 188,
    {POPUP_BG_IMG_2, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},

    {USED, LAYOUT_STYLE_POPUP, "POPUP_URL", 0, 0, 290, 252,
    {POPUP_BG_IMG_3, NULL}, FALSE, FALSE, TRUE, FALSE, NOT_USED, MCFDISPLAY_LANDSCAPE, FALSE},
};

McfInputModeConfigure mcf_input_mode_configure[MAX_INPUT_MODE] = {
    /* name, fUseScreenRotation, layoutId[] */
    /* base input mode */
    {"ENGLISH_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"NUM_4X4",				FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_4X4_NUM}},
    {"SYM_4X4_1",			FALSE, {LYT_PORTRAIT_4X4_SYM,			LYT_PORTRAIT_4X4_SYM}},
    {"SYM_4X4_2",			FALSE, {LYT_PORTRAIT_4X4_SYM,			LYT_PORTRAIT_4X4_SYM}},
    {"SYM_4X4_3",			FALSE, {LYT_PORTRAIT_4X4_SYM,			LYT_PORTRAIT_4X4_SYM}},
    {"SYM_4X4_4",			FALSE, {LYT_PORTRAIT_4X4_SYM,			LYT_PORTRAIT_4X4_SYM}},
    {"SYM_4X4_5",			FALSE, {LYT_PORTRAIT_4X4_SYM,			LYT_PORTRAIT_4X4_SYM}},
    {"PHONE_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_4X4_NUM}},
    {"URL_4X4",				FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_URL}},
    {"EMAIL_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_EMAIL}},
    {"PASSWD_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_4X4_PASSWD}},
    {"IPv6_4X4_123",		FALSE, {LYT_PORTRAIT_4X4_IPv6_123,		LYT_LANDSCAPE_4X4_IPv6_123}},
    {"IPv6_4X4_ABC",		FALSE, {LYT_PORTRAIT_4X4_IPv6_ABC,		LYT_LANDSCAPE_4X4_IPv6_ABC}},
    {"NUMONLY_4X4",			FALSE, {LYT_PORTRAIT_4X4_NUMONLY,		LYT_LANDSCAPE_4X4_NUMONLY}},
    {"MONTH_4X4",			FALSE, {LYT_PORTRAIT_4X4_MONTH,			LYT_LANDSCAPE_4X4_NUM}},

    {"FRENCH_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_AZT_FRENCH}},
    {"SPANISH_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"ITALIAN_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"DUTCH_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"PORTUGUESE_4X4",		FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"GERMAN_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},

    {"TURKISH_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"GREEK_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"RUSSIAN_4X4",			FALSE, {LYT_PORTRAIT_4X4_DEFAULT,		LYT_LANDSCAPE_QTY_RUSSIAN}},

    {"ENGLISH_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"URL_QTY",				FALSE, {LYT_PORTRAIT_QTY_URL,			LYT_LANDSCAPE_QTY_URL}},
    {"EMAIL_QTY",			FALSE, {LYT_PORTRAIT_QTY_EMAIL,			LYT_LANDSCAPE_QTY_EMAIL}},
    {"SYM_QTY_1",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"SYM_QTY_2",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"SYM_QTY_3",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"SYM_QTY_4",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},

    {"FRENCH_QTY",			FALSE, {LYT_PORTRAIT_AZT_DEFAULT,		LYT_LANDSCAPE_AZT_FRENCH}},
    {"SPANISH_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"ITALIAN_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"DUTCH_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"PORTUGUESE_QTY",		FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"GERMAN_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},

    {"TURKISH_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"GREEK_QTY",			FALSE, {LYT_PORTRAIT_QTY_DEFAULT,		LYT_LANDSCAPE_QTY_DEFAULT}},
    {"RUSSIAN_QTY",			FALSE, {LYT_PORTRAIT_QTY_RUSSIAN,		LYT_LANDSCAPE_QTY_RUSSIAN}},
};

McfInputModePopupConfigure mcf_input_mode_popup_configure[MAX_INPUT_MODE_POPUP] = {
    /* name, style, fUseRotation, layoutId[], fUseWindow, fUseDimWindow */
    /* popup input mode */
    {"4X4_TEXTMODE_POPUP", LAYOUT_STYLE_POPUP, FALSE, {LYT_PORTRAIT_4X4_TEXTMODE_POPUP, LYT_PORTRAIT_4X4_TEXTMODE_POPUP}, TRUE, TRUE},

    {"PUNCTUATION_POPUP", LAYOUT_STYLE_POPUP, FALSE, {LYT_PUNCTUATION_POPUP, LYT_PUNCTUATION_POPUP}, TRUE, FALSE, 0},
    {"EMOTICON_POPUP", LAYOUT_STYLE_POPUP, FALSE, {LYT_EMOTICON_POPUP, LYT_EMOTICON_POPUP}, TRUE, FALSE, 0},
    {"URL_POPUP", LAYOUT_STYLE_POPUP, FALSE, {LYT_URL_POPUP, LYT_URL_POPUP}, TRUE, FALSE, 0},
};

McfAutoPopupConfigure mcf_autopopup_configure = {
	"04_textinput_bubble_umlaut_bg.png",
	{0, 128,0, 255}, /*McfColor bgColor;*/
	2, /*mcfdouble bgLineWidth;*/
	{0, 60, 0, 255}, /*McfColor bgLineColor;*/
	0, /*mcfbyte bgPadding; /* padding amount between the bg border and buttons */
	//{"08_textinput_alternative_bg_c.png","08_textinput_alternative_bg_c.png"}, /*mcfchar* btnImgPath[MAX_BUTTON_STATE];*/
	{NULL,NULL}, /*mcfchar* btnImgPath[MAX_BUTTON_STATE];*/
	SW_BTN_STYLE_A, /*mcfbyte swBtnStyleIdx;*/
	66, /*mcfshort btnWidth;*/
	102, /*mcfshort btnHeight;*/
	0, /*mcfbyte btnSpacing;*/
	AUTOPOPUP_LABEL_PROP,
	{
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	},
	0,
	10,
	0, // addGrabLeft
	0, // addGrabRight
	0, // addGrabTop
	100 // addGrabBottom
};

McfDimWndConfigure mcf_dim_window_configure = {
    TRUE,
    {0, 0, 0, 128},
};

McfModifierDecoration mcf_modifier_decoration[MODIFIER_DECORATION_NUM] = {
    { // DRAG_STATE_DECORATION_NONE
        FALSE, { { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, { NULL, NULL, NULL, NULL, NULL, NULL, NULL } }
    },
};

mcfboolean mcf_sublayout_support_table[MAX_INPUT_MODE][SUBLAYOUTID_MAX] = {
    // SUBLAYOUTID_DEFAULT,	SUBLAYOUTID_WITH_VOICE,	SUBLAYOUTID_URL,	SUBLAYOUTID_EMAIL
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_ENGLISH,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_NUM,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_SYM_1,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_SYM_2,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_SYM_3,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_SYM_4,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_SYM_5,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_TELEPHONE,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_URL,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_EMAIL,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_PASSWD,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_IPv6_123,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_IPv6_ABC,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_NUMONLY,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_MONTH,

    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_FRENCH,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_SPANISH,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_ITALIAN,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_DUTCH,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_PORTUGUESE,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_GERMAN,

    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_TURKISH,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_GREEK,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_4X4_RUSSIAN,

    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_ENGLISH,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_URL,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_EMAIL,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_SYM_1,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_SYM_2,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_SYM_3,
    {	TRUE,				FALSE,					FALSE,				FALSE,	  }, //INPUT_MODE_QTY_SYM_4,

    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_FRENCH,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_SPANISH,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_ITALIAN,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_DUTCH,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_PORTUGUESE,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_GERMAN,

    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_TURKISH,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_GREEK,
    {	TRUE,				FALSE,					TRUE,				TRUE,	  }, //INPUT_MODE_QTY_RUSSIAN,
};
