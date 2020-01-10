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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringslist.h"

stringslist_t *stringslist_create(size_t size)
{
	stringslist_t *list;

	if (size < 0)
		return NULL;

	list = malloc(sizeof(*list));
	if (list == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	list->size = size;
	list->elements = NULL;
	if (size > 0) {
		list->elements = calloc(sizeof(char *), size);
	}

	return list;
}

stringslist_t *stringslist_load_file(char *filename)
{
	FILE *fp;
	stringslist_t *list;
	ssize_t read;
	char *temp = 0;
	size_t len;

	/* Open file */
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror(filename);
		return NULL;
	}

	/* Get number of elements */
	int no_elements = 0;
	while ((read = getline(&temp, &len, fp)) != -1)
		++no_elements;

	/* Initialize wordlist */
	list = stringslist_create(no_elements);

	rewind(fp);
	for (int i = 0; i < no_elements; i++) {
		read = getline(&temp, &len, fp);
		strtok(temp, "\n");
		*(list->elements + i) = strdup(temp);
		++list->size;
	}
	fclose(fp);

	if (temp != NULL) {
		free(temp);
	}

	return list;
}

void stringslist_destroy(stringslist_t *list)
{
	for (int i = 0; i < list->size; ++i) {
		free(list->elements[i]);
	}
	free(list->elements);
}
