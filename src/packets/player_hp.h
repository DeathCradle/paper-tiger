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

#ifndef _HAVE_PLAYER_HP_H
#define _HAVE_PLAYER_HP_H

#define PACKET_TYPE_PLAYER_HP 16
#define PACKET_LEN_PLAYER_HP 5

#include <uv.h>

#include "../talloc/talloc.h"
#include "../colour.h"

#ifdef __cplusplus
extern "C" {
#endif

struct player;
struct packet;
	
struct player_hp {
	uint8_t id;
	uint16_t life;
	uint16_t life_max;
};

int player_hp_new(TALLOC_CTX *ctx, const struct player *player, uint16_t life, uint16_t life_max, struct packet **out_packet);

int player_hp_write(TALLOC_CTX *context, struct packet *packet, uv_buf_t *buf);

int player_hp_read(struct packet *packet, const uv_buf_t *buf);

int player_hp_handle(struct player *player, struct packet *packet);
	

#ifdef __cplusplus
}
#endif

#endif //_HAVE_PLAYER_HP_H