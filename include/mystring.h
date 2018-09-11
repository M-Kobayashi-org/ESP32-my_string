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

#ifndef COMPONENTS_MY_STRING_MYSTRING_H_
#define COMPONENTS_MY_STRING_MYSTRING_H_

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

char *ltrim(char *, const char **);
char *rtrim(char *, const char **);
char *trim(char *, const char **);

char *uppercase(char *);
char *lowercase(char *);

void dump(FILE *, const void *, size_t);

#ifdef __cplusplus
}
#endif

#endif /* COMPONENTS_MY_STRING_MYSTRING_H_ */
