#pragma once
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

bool higher(char *a, char *b);

table *add(table *t, telem *e);

table *buildtable();