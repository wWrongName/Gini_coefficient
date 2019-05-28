#include "gini_h.h"
unsigned int am_of_people = -1;
unsigned int total_salary = 0;

void gini(FILE *input) {
	LIST *data;
	double one_human;
	double G = 0;
	double yi, yj;
	data = parse(input);
	data = sort_list(data);
	one_human = 1 / (double)am_of_people;
	double summ_y = 0;
	for (LIST *data_c = data; data_c != NULL; data_c = data_c->next) {
		yi = 100 * (double)data_c->value / (double)total_salary;
		summ_y += yi;
		for (LIST *data_c2 = data_c; data_c2 != NULL; data_c2 = data_c2->next) {
			yj = 100 * (double)data_c2->value / (double)total_salary;
			G += fabs(yi - yj);
		}
	}
	G = G / (2 * (double)am_of_people * summ_y);
	printf("Gini coefficient: %lf", G);
	free_data(data);
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
			if (am_of_people != -1)
				data = create_hub(data, tmp_data);

			am_of_people++;
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
		if (data == NULL) {
			printf("There is not enough memory to work with so long .csv file.\n");
			printf("Not enough memory for this program.\n");
			return data;
		}
		data->next = NULL;
		data->value = val;
		total_salary += val;
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

LIST *free_data(LIST *data) {
	if (data->next != NULL)
		data->next = free_data(data->next);
	else {
		free(data);
		return NULL;
	}
	if (data == NULL)
		return NULL;
}