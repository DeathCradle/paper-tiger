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
 * 
 * upgraded-guacamole is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with upgraded-guacamole.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HAVE_GAME_H
#define _HAVE_GAME_H


#include <errno.h>
#include <stdbool.h>
#include <uv.h>

#include "talloc/talloc.h"
//#include "server.h"
#include "bitmap.h"
//#include "player.h"
//#include "console.h"

#define GAME_MAX_PLAYERS 255
#define GAME_PROTOCOL_VERSION 156

#ifdef __cplusplus
extern "C" {
#endif
	
struct player;
struct server;
struct game;
struct console;

struct game {
	double ms_per_frame;

	struct world *world;
    struct server *server;
    struct player *players[256];
	struct console *console;
	
	word_t *player_slots;
	
    uv_loop_t *event_loop;
	uv_timer_t *update_handle;
};

int game_find_next_slot(struct game *context);

int game_start_event_loop(struct game *context);

int game_new(TALLOC_CTX *context, struct game **out_context);

int game_update_loop_init(struct game *game);

#ifdef __cplusplus
}
#endif

#endif /* _HAVE_GAME_H */
