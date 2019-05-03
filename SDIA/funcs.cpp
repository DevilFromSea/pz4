#define _CRT_SECURE_NO_WARNINGS
#include "table.h"

int hashcode(UCHAR key[9])
{
	int s = 0, p = -1;
	for (int i = 8; i > -1; i--)
	{
		s += key[i] * pow(10, p);
		p++;
	}
	return s % Hmax;
}

void buildtable(table *t, int c)
{
	telem e;
	t->n = 0;
	FILE *f;
	fopen_s(&f, "WORK.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", e.key);
		fscanf(f, "%s", e.name);
		fscanf(f, "%d", &e.amount);
		switch (c)
		{
		case 1:
			disadd(t, e);
			break;
		case 2:
			add(t, e);
			break;
		}
	}
	fclose(f);
	printf_s("Table was successfully built.\n");
	for (int i = 0; i < t->n; i++)
		printf_s("%s	%s	%d\n", t->cont[i].key, t->cont[i].name, t->cont[i].amount);
}

void buildhtable(htable *t)
{
	telem e;
	for (int k = 0; k < Hmax; k++)
		t->cont[k].amount = -1;
	FILE *f;
	fopen_s(&f, "WORK.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%s", e.key);
		fscanf(f, "%s", e.name);
		fscanf(f, "%d", &e.amount);
		hashadd(t, e);
	}
	fclose(f);
	printf_s("Table was successfully built.\n");
	for (int i = 0; i < Hmax; i++)
	{
		if (t->cont[i].amount != -1)
			printf_s("%d	%s	%s	%d\n", i, t->cont[i].key, t->cont[i].name, t->cont[i].amount);
	}
}

void add(table *t, telem e)
{
	int i = t->n - 1;
	if (t->n < Nmax)
	{
		while (i >= 0 && _mbscmp(t->cont[i].key, e.key) >= 0)
		{
			if (!_mbscmp(t->cont[i].key, e.key))
			{
				t->cont[i].amount += e.amount;
				return;
			}
			t->cont[i + 1] = t->cont[i];
			i--;
		}
		t->cont[i + 1] = e;
		t->n++;
	}
}

void disadd(table *t, telem e)
{
	if (t->n < Nmax)
	{
		for (int k = 0; k < t->n; k++)
			if (!_mbscmp(t->cont[k].key, e.key))
			{
				t->cont[k].amount += e.amount;
				return;
			}
		t->cont[t->n] = e;
		t->n++;
	}
}

void hashadd(htable *t, telem e)
{	
	int index = hashcode(e.key);
	while (t->cont[index].amount != -1)
	{
		index++;
	}
	if (!_mbscmp(t->cont[index - 1].key, e.key))
	{
		t->cont[index - 1].amount += e.amount;
		return;
	}
	t->cont[index] = e;
}
