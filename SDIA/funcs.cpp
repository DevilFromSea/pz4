#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include "table.h"

bool higher(char *a, char *b)
{
	for (int i = 0; i < 8; i++)
	{
		if (a[i] < b[i])
			return false;
		if (a[i] > b[i])
			return true;
	}
	return true;
}

table *ordered()
{
	telem e;
	table *t = NULL;
	FILE *f;
	fopen_s(&f, "WORK.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", e.key);
		fscanf(f, "%s", e.name);
		fscanf(f, "%d", &e.amount);
		t = add(t, e);
	}
	printf_s("Table was successfully built.\n");
	return t;
}

table *disordered()
{
	telem e;
	table *t = NULL;
	FILE *f;
	fopen_s(&f, "WORK.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", e.key);
		fscanf(f, "%s", e.name);
		fscanf(f, "%d", &e.amount);
		t = disadd(t, e);
	}
	printf_s("Table was successfully built.\n");
	return t;
}

table *mixed()
{

}

table *add(table *t, telem e)
{
	if (!t)
	{
		t = new table;
		t->cont[0] = e;
		t->n++;
		return t;
	}
	int i = t->n - 1;
	if (t->n < Nmax)
	{
		while (i >= 0 && higher(t->cont[i].key, e.key))
		{
			if (!strcmp(t->cont[i].key, e.key))
			{
				t->cont[i].amount += e.amount;
				return t;
			}
			t->cont[i + 1] = t->cont[i];
			i--;
		}
		t->cont[i + 1] = e;
		t->n++;
	}
	return t;
}

table *disadd(table *t, telem e)
{
	if (!t)
	{
		t = new table;
		t->cont[0] = e;
		t->n++;
		return t;
	}
	if (t->n < Nmax)
	{
		for (int k = 0; k < t->n; k++)
			if (!strcmp(t->cont[k].key, e.key))
			{
				t->cont[k].amount += e.amount;
				return t;
			}
		t->cont[t->n] = e;
		t->n++;
	}
	return t;
}

table *mixadd(table *t, telem e)
{

}