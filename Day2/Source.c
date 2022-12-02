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
	if (fp == NULL)
	{
		printf("file doesnt exist");
		exit(1);
	}
	while ((elf1 = getc(fp)) != EOF) {
		throwaway = getc(fp);
		elf2 = getc(fp);
		result = pointaddup(result, elf2);
		throwaway = getc(fp);
		result = rockpaperscissors(result, elf1, elf2);
	}
	printf("%d", result);
	return 0;
}

int pointaddup(int result, char ch){
	switch (ch) {
		case 'X':
			result += + 1;
			break;
		case 'Y':
			result += + 2;
			break;
		case 'Z':
			result += + 3;
			break;
	}
	return result;
}
int rockpaperscissors(int result, char elf1, char elf2) {
	if (elf1 == 'A' && elf2 == 'X' || elf1 == 'B' && elf2 == 'Y' || elf1 == 'C' && elf2 == 'Z')
	{
		result += 3;
	}
	else if (elf1 == 'A' && elf2 == 'Y' || elf1 == 'B' && elf2 == 'Z' || elf1 == 'C' && elf2 == 'X')
	{
		result += 6;
	}
	else if (elf1 == 'A' && elf2 == 'Z' || elf1 == 'B' && elf2 == 'X' || elf1 == 'C' && elf2 == 'Y')
	{
		result += 0;
	}
	return result;
}
//A,X=rock
//B,Y=paper
//C,Z=scissors