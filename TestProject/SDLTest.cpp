#include "pch.h"

#include <stdio.h>

int main()
{
	// �� ���� ���� //
	int a;
	scanf("%d", &a);
	printf("%d", a);

	// �� ���� ���� ���� //
	int b;
	scanf_s("%d", &b, sizeof(b));
	printf("%d", b);

	return 0;
}