#include "stdafx.h"

#include <stdio.h>
#define MAX_STR_SIZE 100
int main() {
	char str_read[MAX_STR_SIZE];
	fgets(str_read, MAX_STR_SIZE, stdin);
	int num = strlen(str_read);
	str_read[num - 1] = '\0';
	printf("�о���� ���ڿ� : %s \n", str_read);
	return 0;
}