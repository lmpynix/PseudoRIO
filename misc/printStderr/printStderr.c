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
#include "printStderr.h"

int printStderr(const char * errortext = default_error_msg, int addNewLine = 1)
{

	// A manipulatable string, as we can't mess with the source errortext.
	char *intermediary;

	// So we can check up on fprintf() later...
	int charsWritten = 0;

	// Having addNewLine be greater than 1 will mess with the math later, so...
	if (addNewLine > 1) addNewLine = 1;

	// Allocating space for the intermediary string.  Needed space changes size based upon
	// if we want a newline or not, so we increase size by one more character if true.
	intermediary = (char) calloc(strlen(errortext + (1 + addNewLine)),
			sizeof(char));
	strcpy(intermediary, errortext);
	if (addNewLine) strcat(intermediary, '\n');

	// Finally, print the finished text to stderr.
	charsWritten = fprintf(stderr, intermediary);
	// Let's make sure that we were able to write all of the characters.
	if (charsWritten == strlen(intermediary)
			|| charsWritten == strlen(intermediary + 1))
		return (0);
	else
		return (-1);

}
int printStderr_Multi(	const char ** errortext,
						const int * numLines,
						const int addNewLine = 1,
						const int indentFollowingLines = 1)
{
	char * intermediary; // Again, an intermediary string so we don't touch the original.
	int * charsWritten; // Since we'll be writing multiple lines we'll have an array this time.
	int retval = 0; //Value to be returned by the function since I'm not brave enough to use errno for this.
	if (*numlines = 0) return (0);
	for (iter1 = 0; iter1 <= numLines; ++iter1)
	{
		unsigned int intermediarySize = strlen(errortext[iter1]) + 1; // +1 for the \0
		if (addNewLine) intermediarySize++; // +1 for the \n, if we want it.
		if (indentFollowingLines && iter1 != numLines) intermediarySize +=
				indent_length;
		intermediary = (char) calloc(intermediarySize, sizeof(char));
		strcpy(intermediary, errortext[iter1]);
		if (addNewLine) strcat(intermediary, '\n');
		if (indentFollowingLines && iter1 != numlines)
		{
			for (iterIndent = 0; iterIndent <= indent_length; ++iterIndent)
			{
				strcat(intermediary, ' ');
			}
		}
		// And now, the moment you've all been waiting for...  printing the output.
		if (fprintf(stderr, intermediary) != strlen(intermediary))
			retval = -1;

		//Now we just have to clean up a little.
		free(intermediary);

	}

	return (retval);
}
int printStderr_Struct(	const PrintableError * errorStruct)
{
	printStderr_Multi(errorStruct->errortext, errorStruct->numLines,
			errorStruct->addNewLine, errorStruct->indentFollowingLines);
}
