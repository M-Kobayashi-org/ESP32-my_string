/*
 * Guess of the original plain text Gets a difficult hash value.
 *
 *      Create 2018-09-08 By Masato Kobayashi
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

char *uppercase(char *buf)
{
	char *ptr = buf;
	if (ptr) {
		while (*ptr) {
			if (*ptr >= 'a' && 'z' >= *ptr) {
				*ptr &= 0xdf;
			}
			ptr++;
		}
	}

	return buf;
}

char *lowercase(char *buf)
{
	char *ptr = buf;
	if (ptr) {
		while (*ptr) {
			if (*ptr >= 'A' && 'Z' >= *ptr) {
				*ptr |= 0x20;
			}
			ptr++;
		}
	}

	return buf;
}
