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

#include <string.h>

#include "continue_connecting2.h"
#include "world_info.h"

#include "../player.h"
#include "../packet.h"
#include "../server.h"
#include "../util.h"

int continue_connecting2_handle(struct player *player, struct packet *packet)
{
	struct packet *world_info;

	if (world_info_new(player, player, &world_info) < 0) {
		_ERROR("%s: error creating world info packet.\n", __FUNCTION__);
		return -1;
	}

	server_send_packet(player, world_info);

	return 0;
}
