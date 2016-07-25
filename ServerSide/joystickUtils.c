/*
 * joystickUtils.c
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


#include <unistd.h>
#include <stdbool.h>
#include "libenjoy/src/libenjoy.h"
#include "misc/printToStderr.h"

libenjoy_context *le_ctx;
libenjoy_joy_info_list *le_jinfo;
extern bool debugmode;

libenjoy_context *joystickutils_init(bool doPopulateInfo = true)
{
	// Initialize the library, and set the context.
	*le_ctx = libenjoy_init();
	// We should at least call this once, so we have a list of joysticks
	libenjoy_enumerate(le_ctx);
	if(doPopulateInfo)
	{
		*le_jinfo = libenjoy_get_info_list(le_ctx);
		if (le_jinfo -> count == 0)
		{
			
	}
	

*float get_joystick()
{
	//TODO: Write something here.
	return 0;
}

