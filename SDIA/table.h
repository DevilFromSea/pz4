#pragma once
#define Nmax 15

struct telem
{
	char key[9];
	char name[21];
	int amount;
};

struct table
{
	telem cont[Nmax];
	int n = 0;
};

bool higher(char *a, char *b);

table *add(table *t, telem *e);

table *buildtable();