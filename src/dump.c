/*
 * Guess of the original plain text Gets a difficult hash value.
 *
 *      Create 2018-09-10 By Masato Kobayashi
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

#include <stdio.h>
#include <string.h>

void dump(FILE *f, const void *buf, size_t len)
{
	char ascii[16 + 1];
	char *ptr = (char *)buf;
	char *off;

	memset(ascii, 0x00, sizeof(ascii));

	fprintf(f, "  Addr  |  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F |     Ascii\n");
	fprintf(f, "--------+-------------------------------------------------+----------------\n");
	fprintf(f, "%08X|", (unsigned int)ptr & 0xfffffff0);
	size_t l = (unsigned int)ptr & 0x0000000f;
	off = ascii;
	while (l--) {
		fprintf(f, "   ");
		*off = ' ';
		off++;
	}
	if (!buf) {
		len = 0;
	}
	while (len) {
		do {
			fprintf(f, " %X%X", (*ptr & 0xf0) >> 4, (*ptr & 0x0f));
			*off = (*ptr > 0x7e ? '.' : (0x20 > *ptr ? '.' : *ptr));
			off++;
			ptr++;
			len--;
		} while (len && ((unsigned int)ptr & 0x0000000f));
		if (len) {
			fprintf(f, " |%s\n", ascii);
			fprintf(f, "%08X|", (unsigned int)ptr & 0xfffffff0);
		}
		else {
			l = (unsigned int)ptr & 0x0000000f;
			while (l & 0x0f) {
				fprintf(f, "   ");
				*off = ' ';
				off++;
				l++;
			}
			fprintf(f, " |%s\n", ascii);
		}
		off = ascii;
	}
	fprintf(f, "\n");
}
