#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN "input.txt"
int main(void) {
	FILE* fp = fopen(IN, "r");
	char read[200];
	char comp1[200];
	int i1 = 0;
	char comp2[200];
	int i2 = 0;
	char storage;
	int j = 0;
	int flag = 0;
	char flagchar = 'a';
	char test = 'a';
	int score = 0;

	while (fgets(read, 200, fp) != 0) {
		for (j = 0; read[j] != '\0'; ++j);
		for (int i = 0; i < j; i++)
		{
			if (i < j/2)
			{
				comp1[i1++] = read[i];
			}
			else
			{
				comp2[i2++] = read[i];
			}
		}
		for (int x = 0; x < j / 2; x++)
		{
			for (int y = 0; y < j / 2; y++)
			{
				if (comp1[x] == comp2[y]) {
					flagchar = comp2[y];
				}
			}
		}
		do
		{
			score++;
			if (test == 'z'+1)
			{
				test = 'A';
			}
		} while (test++, test-1 != flagchar);
		test = 'a';
		i1 = 0;
		i2 = 0;
	}
	printf("answer part 1 %d", score);
	return 0;
}