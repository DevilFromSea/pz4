#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <ctime>

const char alph[] = "abcdefghijklmnopqrstuvwxyz0123456789";
const int Nmax = 15;

enum Mixcom { MCMD_REPLACE = 1, MCMD_GENERATE };
enum Commands { CMD_DISORDERED = 1, CMD_ORDERED, CMD_MIXED };

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