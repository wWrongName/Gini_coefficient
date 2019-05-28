#include "gini_h.h"

int main(int argc, char **argv)
{
	if (argc != 3 && argv[1] != "-i") {
		printf("Incorrect input. Instruction:\n");
		printf("You must type the folowing => gini.exe -i data.csv\n");
		return 1;
	}
	FILE *input = fopen(argv[2],"r");
	if (input == NULL) {
		printf("File was not found. Please, check file path.\n");
		return 1;
	}
	gini(input);
	fclose(input);
	return 0;
}
