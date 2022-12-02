#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN "Input.txt"
int main(void) {
	FILE* fp = fopen(IN, "r");
	char elf1;
	char elf2;
	char throwaway;
	int result = 0;
	if (fp == NULL) {
		printf("file doesnt exist");
		exit(1);
	}
	while ((elf1 = getc(fp)) != EOF) { //part one
		throwaway = getc(fp);
		elf2 = getc(fp);
		result = pointaddup(result, elf2);
		throwaway = getc(fp);
		result = rockpaperscissors(result, elf1, elf2);
	}
	printf("answer part 1 %d\n", result);
	result = 0;
	fclose(fp);
	fp = fopen(IN, "r");
	while ((elf1 = getc(fp)) != EOF) {
		throwaway = getc(fp);
		elf2 = getc(fp);
		result = part2(result, elf1, elf2);
		throwaway = getc(fp);
	}
	printf("answer part 2 %d\n", result);
	return 0;
}

int pointaddup(int result, char ch) {
	switch (ch) {
	case 'X'://rock
		result += +1;
		break;
	case 'Y'://paper
		result += +2;
		break;
	case 'Z'://scissors
		result += +3;
		break;
	}
	return result;
}
int rockpaperscissors(int result, char elf1, char elf2) {
	if (elf1 == 'A' && elf2 == 'X' || elf1 == 'B' && elf2 == 'Y' || elf1 == 'C' && elf2 == 'Z') {//tie
		result += 3;
	}
	else if (elf1 == 'A' && elf2 == 'Y' || elf1 == 'B' && elf2 == 'Z' || elf1 == 'C' && elf2 == 'X') {//win
		result += 6;
	}
	else if (elf1 == 'A' && elf2 == 'Z' || elf1 == 'B' && elf2 == 'X' || elf1 == 'C' && elf2 == 'Y') {//loss
		result += 0;
	}
	return result;
}
int part2(int result, char elf1, char elf2) {
	switch (elf2) {
	case 'X'://loss
		if (elf1 == 'A') {
			result += 3;
		}
		else if (elf1 == 'B') {
			result += 1;
		}
		else {
			result += 2;
		}
		break;
	case 'Y'://tie
		if (elf1 == 'A') {
			result += 3 + 1;
		}
		else if (elf1 == 'B') {
			result += 3 + 2;
		}
		else {
			result += 3 + 3;
		}
		break;
	case 'Z'://win
		if (elf1 == 'A') {
			result += 6 + 2;
		}
		else if (elf1 == 'B') {
			result += 6 + 3;
		}
		else {
			result += 6 + 1;
		}
		break;
	}
	return result;
}