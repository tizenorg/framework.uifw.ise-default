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


#include "mcfdebug.h"
#include <sys/time.h>
#include <string.h>


#ifdef MCF_DEBUG_ON

/* Measure elapased time */
static float
_MCF_DEBUG_ELAPASED_TIME(const char* str, struct timeval t0, struct timeval t1);

/* Measure elapased time */
float MCF_DEBUG_TIME(const char* fileStr, int line, const char* str)
{
    float etime = 0.0;
    static struct timeval t0 = {
        0,
    };
    static struct timeval t1;
    char *pFileStr = const_cast<char*>(fileStr);
    if (pFileStr) {
        if (strlen(fileStr) > 20) {
            pFileStr += (strlen(fileStr) - 20);
        }
        gettimeofday(&t1, NULL);
        if (t0.tv_usec != 0) {
            etime = ((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec))/1000000.0;
        }

        printf("[%-20.20s]%04d [T:%u][E:" mc_red "%f" mc_normal "]" mc_blue " %s" mc_normal "\n",
        	   pFileStr, line, (t1.tv_sec * 1000000 + t1.tv_usec), etime, str);
        t0 = t1;
    }
}

/* Measure elapased time */
static float _MCF_DEBUG_ELAPASED_TIME(const char* str, struct timeval t0, struct timeval t1)
{
    float etime;
    etime = ((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec))/1000000.0;
    printf("[%s] elap-time = " mc_green "%f" mc_normal " (%u~%u) \n", str, etime, (t0.tv_sec * 1000000 + t0.tv_usec),
    	   (t1.tv_sec * 1000000 + t1.tv_usec));
    return etime;
}

/* Measure elapased time */
float MCF_DEBUG_ELAPASED_TIME(const char* fileStr, int line, const char* str, int type)
{
    static struct timeval s_tv1;
    static struct timeval s_tv2;
    static int s_start_line = 0;
    static int s_end_line = 0;
    if (type == MEASURE_START) {
        gettimeofday(&s_tv1, NULL);
        s_start_line = line;
        printf("[%-20.20s]%04d [T:%u]" mc_blue " %s" mc_normal "\n", fileStr, line,
        	   (s_tv1.tv_sec * 1000000 + s_tv1.tv_usec), str);
    } else if (type == MEASURE_END) {
        gettimeofday(&s_tv2, NULL);
        s_end_line = line;
        char printStr[100];
        sprintf(printStr,"%s(Line:%d~%d)", str, s_start_line, s_end_line);
        _MCF_DEBUG_ELAPASED_TIME(printStr, s_tv1, s_tv2);
    }
}
#endif
