/*
 * https://github.com/matricali/stringslist
 *
 * Copyright (c) 2018 Jorge Matricali.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __STRINGSLIST_STRINGSLIST_H
#define __STRINGSLIST_STRINGSLIST_H

typedef struct {
	unsigned int size;
	char **elements;
} stringslist_t;

stringslist_t *stringslist_create(size_t size);

stringslist_t *stringslist_load_file(char *filename);

void stringslist_destroy(stringslist_t *list);

#endif /* __STRINGSLIST_STRINGSLIST_H */
