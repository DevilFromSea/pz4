#include "table.h"

int main()
{
	table t;
	htable ht;
	int exitFlag = 0, n;
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
			buildhtable(&ht);
			exitFlag = 1;
			break;
		default:
			printf_s("Invalid choice.\n");
			break;
		}
	}
	system ("pause");
}