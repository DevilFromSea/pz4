#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <string.h>
#include <mbstring.h>
#include <stdio.h>
#include <ctime>
#include <windows.h>

const int Nmax = 10;
const int Hmax = 65521;

enum Commands { CMD_DISORDERED = 1, CMD_ORDERED, CMD_HASHTABLE };

struct telem
{
	UCHAR key[9];
	char name[21];
	int amount;
};

struct table
{
	telem cont[Nmax];
	int n = 0;
};

struct hashtable
{
	telem cont[Hmax];
};

int hashcode(UCHAR key[9]);

void buildtable(table *t, int c);

void add(table *t, telem e);

void disadd(table *t, telem e);

void hashadd(table *t, telem e);