#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN "Input.txt"
#define pointaddup(in) ((in) == 'A') ? 1 : ((in) == 'B') ? 2 : ((in) == 'C') ? 3 : 0
#define rps(in1, in2) ((in1) == (in2)) ? 3 : ((in1) > (in2)) ? 0 : ((in1) < (in2)) ? 6 : 0
#define rpsedge(in1, in2) ((in1) == 'C' && (in2) == 'A') ? 6 : ((in1) == 'A' && (in2) == 'C') ? -6 : 0
#define winlose(in1, in2) ((in2) == 'A') ? lose(in1) : ((in2) == 'B') ? tie(in1) : ((in2) == 'C') ? win(in1) : 0
#define lose(in) ((in) == 'A') ? 3 : ((in) == 'B') ? 1 : ((in) == 'C') ? 2 : 0
#define tie(in) ((in) == 'A') ? 1+3 : ((in) == 'B') ? 2+3 : ((in) == 'C') ? 3+3 : 0
#define win(in) ((in) == 'A') ? 2+6 : ((in) == 'B') ? 3+6 : ((in) == 'C') ? 1+6 : 0
int main(void) {
	FILE* fp = fopen(IN, "r");
	char elf1;
	char elf2;
	char throwaway;
	int result1 = 0;
	int result2 = 0;
	if (fp == NULL){
		printf("file doesnt exist");
		exit(1);
	}
	while ((elf1 = getc(fp)) != EOF) {
		throwaway = getc(fp);
		elf2 = getc(fp) - 23;
		result1 += pointaddup(elf2);
		throwaway = getc(fp);
		result1 += (rps(elf1, elf2)) + (rpsedge(elf1, elf2));
		result2 += winlose(elf1, elf2);
	}
	printf("answer part 1 %d\n", result1);
	printf("answer part 2 %d\n", result2);
	fclose(fp);
	return 0;
}