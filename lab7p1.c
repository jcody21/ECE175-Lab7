#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//  Author: John Cody
//  Date created: 03/21/2018
//  Program Description: This program takes two strings and finds where there are patterns within the arrays. 

int match(char ar1[20], char ar2[20], int i, int j);

int main(void) {

	int x = 0, y = 0;
	int maxLength = 0, maxX = 0, maxY = 0;

	char s1[20] = "abcdefghefg\0";
	char s2[20] = "abdefghcrt\0";

	while ((s2[y] != '\0') && (y < 20)) {
		x = 0;
		while ((s1[x] != '\0') && (x < 20)) {
			if (match(s1, s2, x, y) > maxLength) {
				maxLength = match(s1, s2, x, y);
				maxX = x;
				maxY = y;
			}
			x++;
		}
		y++;
	}

	printf("Maximum matching string : \"");

	for (x = maxX; x < maxLength + maxX; x++) {
		printf("%c", s1[x]);
	}
	printf("\"\n");
	printf("Starting position on s1 : %d\n", maxX + 1);
	printf("Starting position on s2 : %d\n", maxY + 1);

	
	return 0;
}

int match(char ar1[20], char ar2[20], int i, int j) {

	int length = 0;

	while (ar1[i+length] == ar2[j+length]) {
		length++;
	}
	
	return length;
}