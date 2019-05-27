#ifndef _GINI_
#define _GINI_

#include <stdio.h>

typedef struct LIST {
	struct LIST *next;
	unsigned int value;
} LIST;
LIST *create_hub(LIST *data, unsigned int val);
LIST *sort_list(LIST *head);
LIST *parse(FILE *input);
void gini(FILE *input, char *arg);

#endif