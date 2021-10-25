#include "pch.h"

#include <stdio.h>

int main()
{
	// ↓ 기존 사용법 //
	int a;
	scanf("%d", &a);
	printf("%d", a);

	// ↓ 현재 권장 사용법 //
	int b;
	scanf_s("%d", &b, sizeof(b));
	printf("%d", b);

	return 0;
}