/*
 * printStderr.c
 *
 * Copyright (C) 2016 - Logan Power
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>

int printStderr(const char * errortext = "An unknown error occurred.",
		        int * addNewLine = 1) {

	// A manipulatable string, as we can't mess with the source errortext.
	char *intermediary;

	// So we can check up on fprintf later...
	int charsWritten = 0;

	// Having addNewLine be greater than 1 will mess with the math later, so...
	if (addNewLine > 1) addNewLine = 1;

	// Allocating space for the intermediary string.  Needed space changes size based upon
	// if we want a newline or not, so we increase size by one more character if true.
	intermediary = (char*) calloc(strlen(errortext + (1 + addNewLine)), sizeof(char));
	strcpy(intermediary, errortext);
	if (addNewLine) strcat(intermediary, '\n');

	// Finally, print the finished text to stderr.
	charsWritten = fprintf(stderr, intermediary);
	// Let's make sure that we were able to write all of the characters.
	if (charsWritten == strlen(intermediary) || charsWritten == strlen(intermediary + 1))
		return 0;
	else
		return -1;

}
//int printStderr_Multi(const char * errortext,
//					  const int * numLines,
//		              const int * addNewLine = 1) {
//
//}
