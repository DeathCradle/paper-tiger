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

#ifndef HAVE_PARAM_H
#define HAVE_PARAM_H

#include "talloc/talloc.h"
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif	

struct param {
	char *input_string;
	char **parameters;
	int num_parameters;
};

int param_new(TALLOC_CTX *context, const char *input_string, struct param **out_context);

void param_free(struct param *param);

#ifdef __cplusplus
}
#endif

#endif