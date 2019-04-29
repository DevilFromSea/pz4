#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "table.h"
#include <string.h>

enum Commands { CMD_DISORDERED = 1, CMD_ORDERED, CMD_MIXED, CMD_EXIT };

int main()
{
	int exitFlag = 0, n;
	table *t;
	while (!exitFlag)
	{
		printf("Enter the command number: ");
		if (!scanf_s("%d", &n))
		{
			printf_s("Error.");
			return 0;
		}
		switch (n)
		{
			printf_s("Building table...\n");
		case CMD_DISORDERED:
			t = disordered();
			break;
		case CMD_ORDERED:
			t = ordered();
			break;
		case CMD_MIXED:
			t = mixed();
			break;
		case CMD_EXIT:
			exitFlag = 1;
			break;
		default:
			printf_s("Invalid choice.\n");
			break;
		}
	}
	return 0;
}