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

#include "game.h"
#include "util.h"
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#define FRAMES_PER_SEC 60

static int __game_update(struct game_context *context)
{
	return 0;
}

int game_run(struct game_context *context)
{
	int msec;
	int ret;
	clock_t start, diff;

	do {
		start = clock();

		if ((ret = __game_update(context)) < 0) {
			_ERROR("%s: game has existed with code %d", __FUNCTION__, ret);
			return ret;
		}

		diff = clock() - start;
		msec = diff * 1000 / CLOCKS_PER_SEC;

		Sleep(msec);
	} while (context->is_exited == false);

	return 0;
}

int game_new(TALLOC_CTX *context, struct game_context **out_context)
{
	struct game_context *gameContext = NULL;
	TALLOC_CTX *tempContext;

	if ((tempContext = talloc_new(NULL)) == NULL) {
		return -ENOMEM;
	}

	gameContext = talloc_zero(tempContext, struct game_context);

	/*
	 * Init game stuff here
	 */

	gameContext->ms_per_frame = 1000. / FRAMES_PER_SEC;

	*out_context = talloc_steal(context, gameContext);

	talloc_free(tempContext);
	return 0;
}