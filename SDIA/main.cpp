#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "table.h"
#include <string.h>

int main()
{
	table *t = buildtable();
	for (int i = 0; i < t->n + 1; i++)
		printf_s("%s %s %d", t->cont[i]->key, t->cont[i]->name, t->cont[i]->amount);
	getchar();
}