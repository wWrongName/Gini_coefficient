#ifndef _GINI_
#define _GINI_

#include <stdio.h>

typedef struct LIST {
	struct LIST *prev;
	struct LIST *next;
	unsigned int value;
} LIST;

LIST *create_hub(LIST *previous, unsigned int val);
LIST *parse(FILE *input);
void gini(FILE *input, char *arg);

#endif