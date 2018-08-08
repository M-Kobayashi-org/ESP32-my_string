/*
 * Guess of the original plain text Gets a difficult hash value.
 *
 *      Create 2018-07-22 By Masato Kobayashi
 *
 *
 *   Copyright (C) 2018 Masato Kobayashi. All rights reserved.
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * The Trim library deletes the blank string before and after
 * the character string in C language format.
 *
 * @author Masato Kobayashi
 *
 */

#include <mystring.h>
#include <stdlib.h>
#include <string.h>

char *ltirim(char *src, const char **wsps)
{
	int isFind = 0;
	do {
		isFind = 0;
		char **wsp = (char **)wsps;
		while(*wsp) {
			size_t len = strlen(*wsp);
			while (memcmp((void *)src, (void *)*wsp, len) == 0) {
				src += len;
				isFind = 1;
			}
			wsp++;
		}
	} while (isFind);
	return src;
}

char *rtirim(char *src, const char **wsps)
{
	int isFind = 0;
	char *pos = NULL;
	do {
		isFind = 0;
		char **wsp = (char **)wsps;
		while(*wsp) {
			size_t len = strlen(*wsp);
			pos = src + strlen(src) - len;
			while (memcmp((void *)pos, (void *)*wsp, len) == 0) {
				*pos = 0x00;
				pos -= len;
				isFind = 1;
			}
			wsp++;
		}
	} while (isFind);
	return src;
}
