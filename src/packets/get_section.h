/*
* upgraded-guacamole - A Terraria server written in C for POSIX operating systems
* Copyright (C) 2016  Tyler Watson <tyler@tw.id.au>
*
* This file is part of upgraded-guacamole.
*
* upgraded-guacamole is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.

* upgraded-guacamole is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with upgraded-guacamole.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _HAVE_GET_SECTION_H
#define _HAVE_GET_SECTION_H

#define PACKET_TYPE_GET_SECTION 8

/*
 * Base length + name length + 1
 */
#define PACKET_LEN_GET_SECTION 8

#include <uv.h>

#include "../talloc/talloc.h"

#ifdef __cplusplus
extern "C" {
#endif

struct player;
struct packet;
struct vector_2d;
	
struct get_section {
	struct vector_2d section;
};

int get_section_read(struct packet *packet, const uv_buf_t *buf);

#ifdef __cplusplus
}
#endif

#endif //_HAVE_GET_SECTION_H