/*
 * Copyright 2012  Samsung Electronics Co., Ltd
 *
 * Licensed under the Flora License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.tizenopensource.org/license
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef __STRING_TABLE_H__
#define __STRING_TABLE_H__

#include <libintl.h>

#define _(str) gettext(str)
#define gettext_noop(str) (str)
#define N_(str) gettext_noop(str)

struct _tc { /* text class */
	char *name; /* text class name */
	int size; /* font size */
};

struct _ts { /* text set */
	char *name; /* part name */
	char *msgid; /* message ID */
};

#endif /* __STRING_TABLE_H__ */
