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

table *ordered();

table *disordered();

table *mixed();

table *add(table *t, telem e);

table *disadd(table *t, telem e);

table *mixadd(table *t, telem e);