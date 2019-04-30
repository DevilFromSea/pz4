#include "table.h"

table *buildtable(int c)
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
		switch (c)
		{
		case 1:
			t = disadd(t, e);
			break;
		case 2:
			t = add(t, e);
			break;
		case 3:
			t = mixadd(t, e);
			break;
		}
	}
	printf_s("Table was successfully built.\n");
	return t;
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
		while (i >= 0 && strcmp(t->cont[i].key, e.key) >= 0)
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
				if (strcmp(t->cont[k].name, e.name))
				{
					int exitFlag = 0, n;
					printf_s("Added element has the same key as the element %d. What would you like to do with this element?\n"
						"1. Replace element\n"
						"2. Generate new key for added element\n", k + 1);
					while (!exitFlag)
					{
						printf_s("Enter the command number: ");
						if (!scanf_s("%d", &n))
						{
							printf_s("Error. Element was skipped.\n");
							return t;
						}
						switch (n)
						{
						case MCMD_REPLACE:
							t->cont[k] = e;
							exitFlag = 1;
							break;
						case MCMD_GENERATE:
							srand(time(NULL));
							for (int l = 0; l < 8; l++)
							{
								e.key[l] = alph[rand() % 36];
							}
							t = mixadd(t, e);
							exitFlag = 1;
							break;
						default:
							printf_s("Invalid choice.\n");
							break;
						}
					}
					return t;
				}
				t->cont[k].amount += e.amount;
				return t;
			}
		t->cont[t->n] = e;
		t->n++;
	}
	return t;
}