#define _CRT_SECURE_NO_WARNINGS
#include "table.h"

int hashcode(UCHAR key[9])
{
	int s = 0, p = 0;
	for (int i = 8; i > -1; i--)
	{
		s += int(key[i]) * 10 ^ p;
		p++;
	}
	return s % Nmax;
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
		case 3:
			hashadd(t, e);
			break;
		}
	}
	printf_s("Table was successfully built.\n");
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

void disadd(table *t, telem e) //νεσο
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

void hashadd(table *t, telem e)
{
   
}
