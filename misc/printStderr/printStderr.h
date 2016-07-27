/*
 * printToStderr.h
 * 
 * Copyright 2016 Logan Power <lmpynix@gmail.com>
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

// Error message printed when printStderr() run with no argument.
char default_error_msg[32] = "An Unknown Error has Occurred.";

// Number of spaces that are in an indent.
int indent_length = 4;

// Structure for printStderr_Struct.

typedef struct PrintableError
{
	char ** errortext;
	int numLines;
	int addNewLine;
	int indentFollowingLines;
};

int printStderr(const char * errortext, const int addNewLine);

int printStderr_Multi(	const char ** errortext,
						const int * numLines,
						const int addNewLine,
						const int indentFollowingLines);

int printStderr_Struct(const PrintableError * errorStruct);

