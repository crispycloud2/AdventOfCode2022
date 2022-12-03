#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN "input.txt"
char rucksackcompare(char[], char[], int);
char rucksackcomparepart2(char[], char[], char[], int, int, int);
int scorecalc(char);
int main(void) {
	FILE* fp = fopen(IN, "r");
	char read[200];
	char comp1[200];
	int i1 = 0;
	char comp2[200];
	int i2 = 0;
	char storage;
	int j = 0;
	char item = 'a';
	char test = 'a';
	int scorepart1 = 0;
	
	int j1 = 0;
	int j2 = 0;
	int n;
	int counter = 0;
	char read1[200];
	char read2[200];
	char badge;
	int scorepart2=0;

	while (fgets(read, 200, fp) != 0) {
		for (j = 0; read[j] != '\0'; ++j);//calculates the size of the input string
		for (int i = 0; i < j; i++)//splits the input string in 2
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
		item = rucksackcompare(comp1, comp2, j); //compares every letter of both strings with each other and returns the one matching letter
		scorepart1 += scorecalc(item); //calculates the score based on the letter found (a-z=1-26 A-Z=27-52)
		i1 = 0; //reset i1 and i2 for the string splitting
		i2 = 0;

		counter++; //counter to keep track of groups of 3
		if (counter == 1) //save elf1's string
			strcpy(read1, read), j1 = j;
		if (counter == 2) //save elf2's string
			strcpy(read2, read), j2 = j;
		if (counter == 3)
		{
			counter = 0;
			badge = rucksackcomparepart2(read, read1, read2, j, j1, j2); //campares every letter of all 3 strings and returns the matching letter
			scorepart2 += scorecalc(badge); //calculates the score based on the letter found (a-z=1-26 A-Z=27-52)
		}
	}
	printf("\nanswer part 1 %d\n", scorepart1); //print output
	printf("answer part 2 %d\n", scorepart2);
	return 0;
}

char rucksackcompare(char comp1[], char comp2[], int j) {
	char output='a';
	for (int x = 0; x < j / 2; x++)
	{
		for (int y = 0; y < j / 2; y++)
		{
			if (comp1[x] == comp2[y]) {
				output = comp2[y];
			}
		}
	}
	return output;
}
char rucksackcomparepart2(char string1[], char string2[], char string3[], int j1, int j2, int j3) {
	char output = 'a';
	for (int x = 0; x < j1-1; x++)
	{
		for (int y = 0; y < j2-1; y++)
		{
			for (int z = 0; z < j3-1; z++)
			{
				if (string3[z] == string2[y] && string3[z] == string1[x])
				{
					output = string1[x];
				}
			}
		}
	}
	return output;
}
int scorecalc(char letter) {
	char test = 'a';
	int score = 0;
	do
	{
		score++;
		if (test == 'z' + 1)
		{
			test = 'A';
		}
	} while (test++, test - 1 != letter);
	return score;
}