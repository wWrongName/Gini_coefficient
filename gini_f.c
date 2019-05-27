#include "gini_h.h"

void gini(FILE *input, char *arg) {
	LIST *data;
	LIST *data_c;
	char str[20];
	char *tmp;
	if (!strcmp(arg, "-a")) {
		unsigned long G;
		data = parse(input);
		data = sort_list(data);
		data_c = data;
		data_c;
		for (int i = 2; data_c->next != NULL; i++) { // (data->next) because the last number is not a number
			G = (data->next->value - data->value) * ();
		}
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

LIST *create_hub(LIST *data, unsigned int val) {
	if (data != NULL)
		data->next = create_hub(data->next, val);
	else {
		data = (LIST*)malloc(sizeof(LIST));
		data->next = NULL;
		data->value = val;
	}
	return data;
}

LIST *sort_list(LIST *head) {
	LIST *tmp, *swap_ptr, *pre_ptr, *ptr;
	char increase = 1;
	while(increase) {
		increase = 0;
		pre_ptr = tmp = head;
		ptr = head->next;
		while (ptr != NULL) {
			if (pre_ptr->value > ptr->value) {
				if (tmp == pre_ptr)
					head = ptr;
				else
					tmp->next = ptr;
				pre_ptr->next = ptr->next;
				ptr->next = pre_ptr;
				swap_ptr = pre_ptr;
				pre_ptr = ptr;
				ptr = swap_ptr;
				increase = 1;
			}
			tmp = pre_ptr;
			pre_ptr = pre_ptr->next;
			ptr = ptr->next;
		}
	}
	return head;
}