#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, e;
	char ch;
	FILE *fp;

	fp = fopen("graphdata.txt", "r");

	// ch = fgetc(fp);
	// n = ch;
	// ch = fgetc(fp);
	// e = ch;
	do
	{
		ch = fgetc(fp);
		printf("%c", ch);
	} while (ch != EOF);

	fclose(fp);

	return 0;
}
