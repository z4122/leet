#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int uniqueMorseRepresentations(char** words, int wordsSize) {
	char morse[26][5] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	int temp = 0;
	int diffNum = 0;
	char tra[100][100] = { '\0' };
	char out[100][100] = { '\0' };
	int a = 0;
	for (int i = 0; i<wordsSize; i++)
	{
		temp = strlen(words[i]);
		for (int j = 0; j<temp; j++)
		{
			strcat_s(tra[i], morse[words[i][j] - 'a']);
		}
	}
	for (int i = 0; i < wordsSize; i++)
	{
		for (int j = 0; j <= diffNum; j++)
		{
			if (strcmp(out[j], tra[i])==0)
			{
				break;
			}
			if (j == diffNum)
			{
				strcat_s(out[diffNum], tra[i]);
				diffNum++;
				break;
			}
		}
		
	}
	return diffNum;

}


int main()
{
	char a[] = "aA";
	char b[] = "AAabbB";
	const char *test[5] = { "gin", "zen", "gig", "msg" };
	uniqueMorseRepresentations((char**)test, 4);
	//printf("%d\n", test);
	return 0;
}