#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#define Nmax 15

struct telem
{
	char key[8];
	char name[20];
	int amount;
};

struct table
{
	telem *cont[Nmax];
	int n = 0;
};

bool higher(char *a, char *b)
{
	for (int i = 0; i < 9; i++)
	{
		if (a[i] < b[i])
			return false;
		if (a[i] > b[i])
			return true;
	}
	return false;
}

table *add(table *t, telem *e)
{
	int i = t->n - 1;
	if (t->n < Nmax)
	{
		while (i >= 0 && higher(t->cont[i]->key, e->key))
		{
			t->cont[i + 1] = t->cont[i];
			i--;
		}
		t->cont[i + 1] = e;
		t->n++;
		return t;
	}
	else
		return t;
}

table *buildtable()
{
	telem *e;
	table *t = NULL;
	char k[8], n[20];
	FILE *f;
	fopen_s(&f, "WORK.txt", "r");
	while (!feof(f))
	{
		for (int i = 0; i < 8; i++)
			fscanf(f, "%c", e->key);
		fscanf(f, "%s", &n);
		for (int j = 0; j < strlen(n); j++)
			e->name[j] = n[j];
		fscanf(f, "%d", &e->amount);
		t = add(t, e);
	}
	printf_s("Table was successfully built\n");
	return t;
}