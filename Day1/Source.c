#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN "Elfs.txt"
int main(void) {
	FILE* fp = fopen(IN, "r");
	char read[200];
	int temp;
	int tempcalc=0;
	int savedelf[] = {0, 0, 0};
	if (fp == NULL)
	{
		printf("file doesnt exist");
		exit(1);
	}
	while (fgets(read, 200, fp)!=0)
	{
		if (strcmp(read, "\n") == 0)
		{
			if (tempcalc > savedelf[0]) {
				savedelf[2] = savedelf[1];	
				savedelf[1] = savedelf[0];
				savedelf[0] = tempcalc;
			}
			else if (tempcalc > savedelf[1]) {
				savedelf[2] = savedelf[1];
				savedelf[1] = tempcalc;
			}
			else if (tempcalc > savedelf[2]) {
				savedelf[2] = tempcalc;
			}
			tempcalc = 0;
		}
		else
		{
			temp = atoi(read);
			tempcalc += temp;
		}
	}
	if (tempcalc > savedelf[0]) {
		savedelf[2] = savedelf[1];
		savedelf[1] = savedelf[0];
		savedelf[0] = tempcalc;
	}
	else if (tempcalc > savedelf[1]) {
		savedelf[2] = savedelf[1];
		savedelf[1] = tempcalc;
	}
	else if (tempcalc > savedelf[2]) {
		savedelf[2] = tempcalc;
	}
	tempcalc = savedelf[0] + savedelf[1] + savedelf[2];
	printf("\nthe elf with the most callories has %d callories and the top 3 combined is %d\n\n", savedelf[0], tempcalc);
	return 0;
}
