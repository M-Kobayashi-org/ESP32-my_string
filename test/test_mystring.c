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

#include <string.h>

#include <unity.h>

#include <mystring.h>

const char *wsps[] = {" ", "\t", "\x0d", "\x0a", "　", NULL};
const char *src = "ABC abc \t012\n\r!#$";
const char *upc = "ABC ABC \t012\n\r!#$";
const char *lwc = "abc abc \t012\n\r!#$";

TEST_CASE("Left trim.", "[my_string]")
{
	char chk[256];
	TEST_ASSERT_EQUAL_STRING(ltrim(src, wsps), src);

	strcpy(chk, " ");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "  ");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "\t");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "\t\t");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "\n");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "\n\n");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "\r");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "\r\r");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "　");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "　　");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, " \t\n\r　");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, " \t\n\r　 \t\n\r　");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	strcpy(chk, "  \t\t\n\n\r\r　　");
	strcat(chk, src);
	TEST_ASSERT_EQUAL_STRING(ltrim(chk, wsps), src);

	TEST_ASSERT_NULL(ltrim(NULL, wsps));

	TEST_ASSERT_NULL(ltrim(src, NULL));

	TEST_ASSERT_NULL(ltrim(NULL, NULL));
}

TEST_CASE("Right trim.", "[my_string]")
{
	char chk[256];
	TEST_ASSERT_EQUAL_STRING(rtrim(src, wsps), src);

	strcpy(chk, src);
	strcat(chk, " ");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "  ");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "\t");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "\t\t");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "\n");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "\n\n");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "\r");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "\r\r");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "　");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "　　");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, " \t\n\r　");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, " \t\n\r　 \t\n\r　");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	strcpy(chk, src);
	strcat(chk, "  \t\t\n\n\r\r　　");
	TEST_ASSERT_EQUAL_STRING(rtrim(chk, wsps), src);

	TEST_ASSERT_NULL(rtrim(NULL, wsps));

	TEST_ASSERT_NULL(rtrim(src, NULL));

	TEST_ASSERT_NULL(rtrim(NULL, NULL));
}

TEST_CASE("Left and right trim.", "[my_string]")
{
	char chk[256];
	TEST_ASSERT_EQUAL_STRING(trim(src, wsps), src);

	strcpy(chk, " ");
	strcat(chk, src);
	strcat(chk, " ");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "  ");
	strcat(chk, src);
	strcat(chk, "  ");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "\t");
	strcat(chk, src);
	strcat(chk, "\t");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "\t\t");
	strcat(chk, src);
	strcat(chk, "\t\t");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "\n");
	strcat(chk, src);
	strcat(chk, "\n");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "\n\n");
	strcat(chk, src);
	strcat(chk, "\n\n");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "\r");
	strcat(chk, src);
	strcat(chk, "\r");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "\r\r");
	strcat(chk, src);
	strcat(chk, "\r\r");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "　");
	strcat(chk, src);
	strcat(chk, "　");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "　　");
	strcat(chk, src);
	strcat(chk, "　　");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, " \t\n\r　");
	strcat(chk, src);
	strcat(chk, " \t\n\r　");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, " \t\n\r　 \t\n\r　");
	strcat(chk, src);
	strcat(chk, " \t\n\r　 \t\n\r　");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	strcpy(chk, "  \t\t\n\n\r\r　　");
	strcat(chk, src);
	strcat(chk, "  \t\t\n\n\r\r　　");
	TEST_ASSERT_EQUAL_STRING(trim(chk, wsps), src);

	TEST_ASSERT_NULL(trim(NULL, wsps));

	TEST_ASSERT_NULL(trim(src, NULL));

	TEST_ASSERT_NULL(trim(NULL, NULL));
}

TEST_CASE("uppercase letter.", "[my_string]")
{
	char chk[256];

	TEST_ASSERT_NULL(uppercase(NULL));

	strcpy(chk, src);
	TEST_ASSERT_EQUAL_STRING(uppercase(chk), upc);
}

TEST_CASE("lowercase letter.", "[my_string]")
{
	char chk[256];

	TEST_ASSERT_NULL(lowercase(NULL));

	strcpy(chk, src);
	TEST_ASSERT_EQUAL_STRING(lowercase(chk), lwc);
}

TEST_CASE("memory dump.", "[my_string]")
{
	dump(stdout, src, strlen(src));
	dump(stdout, wsps, sizeof(wsps));
	dump(stdout, wsps[0], strlen(wsps[0]) + 1);
	dump(stdout, wsps[1], strlen(wsps[1]) + 1);
	dump(stdout, wsps[2], strlen(wsps[2]) + 1);
	dump(stdout, wsps[3], strlen(wsps[3]) + 1);
	dump(stdout, wsps[4], strlen(wsps[4]) + 1);
	dump(stdout, wsps[5], 0);
	dump(stdout, wsps[5], 16);
	dump(stdout, wsps[0], 16);
	dump(stdout, wsps[1], 0);
}
