#include "gini_h.h"

void gini(FILE *input, char *arg) {
	char str[20];
	char *tmp;
	if (!strcmp(arg, "-a")) {
		LIST *data = parse(input);
		//!!!!!!!!!!!!!!!!!!!!!!
	}
	else if (!strcmp(arg, "-g")) {
		//!!!!!!!!!!!!!!!!!!!!!!
	}
	else {
		printf("Type an occupation: ");
		scanf("%s", &str);
		tmp = _strdup(str);
		//!!!!!!!!!!!!!!!!!!!!!!
	}
}

LIST *parse(FILE *input) {
	unsigned int invcom_counter = 0;
	LIST *data = NULL;
	char tmp;
	while ((tmp = fgetc(input)) != EOF) {
		if (tmp == '\"')
			invcom_counter++;
		if (invcom_counter == 9) {
			int tmp_data = 0;
			while ((tmp = fgetc(input)) != '\"') {
				tmp_data = 10 * tmp_data + (tmp - '0');
			}
			data = create_hub(data, tmp_data);
			invcom_counter = 0;
		}
	}
	return data;
}

LIST *create_hub(LIST *previous, unsigned int val) {
	LIST *ptr = (LIST*)malloc(sizeof(LIST));
	ptr->prev = previous;
	ptr->next = NULL;
	ptr->value = val;
	return ptr;
}

void sort_list(LIST *ptr) {
	//!!!!!!!!!!!!!!!!!!!!!!
}