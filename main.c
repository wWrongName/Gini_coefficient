#include "gini_h.h"

int main(int argc, char **argv)
{
	if (argc != 3 && (argv[1] != "-a" || argv[1] != "-g" || argv[1] != "-o")) {
		printf("Incorrect input. Instruction:\n");
		printf("type gini.exe -i data.csv\n");
		return 1;
	}
	FILE *input = fopen(argv[2],"r");
	if (input == NULL) {
		printf("File was not found. Please, check file path.\n");
		return 1;
	}
	gini(input, argv[1]);
	return 0;
}
