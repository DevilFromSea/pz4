#include "table.h"

int main()
{
	int exitFlag = 0, n;
	table t;
	printf_s("Which table would you like to see?\n"
			"1. Disordered\n"
			"2. Ordered\n"
			"3. Mixed\n");
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
			buildtable(&t, 1);
			exitFlag = 1;
			break;
		case CMD_ORDERED:
			buildtable(&t, 2);
			exitFlag = 1;
			break;
		case CMD_HASHTABLE:
			buildtable(&t, 3);
			exitFlag = 1;
			break;
		default:
			printf_s("Invalid choice.\n");
			break;
		}
	}
	for (int i = 0; i < t.n; i++)
		printf_s("%s	%s	%d\n", t.cont[i].key, t.cont[i].name, t.cont[i].amount);
	system ("pause");
}