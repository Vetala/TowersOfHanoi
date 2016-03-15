#include<iostream>
#include<ctype.h>     /*  Character Class Tests  */
#include<stdio.h>     /*  Standard I/O.          */
#include<stdlib.h>    /*  Utility Functions.     */

#define EMPTY 0  /*  Empty disk position.  */
#define DISKS 3  /*  Number of disks.  */

int pos[3][DISKS];  /*  Disk position array, [rows][columns].  */

char code[3] = { 'A', 'B', 'C' };  /*  Peg names.  */
void towers(int n, int source, int temporary, int destination);
void moveDisk(int source, int destination);

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;

	int hold = 0;

	/*  Initialize disk positions.  */
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < DISKS; ++j)
		{
			if (i == 0)
			{
				pos[i][j] = j + 1;
			}
			else
			{
				pos[i][j] = EMPTY;
			}
		}
	}

	/*  Print initial disk positions.  */
	printf("\n\n          A B C\n");
	printf("          - - -\n");

	for (j = 0; j < DISKS; ++j)
	{
		printf("%11.1d %d %d\n", pos[0][j], pos[1][j], pos[2][j]);
	}

	towers(DISKS, 0, 1, 2);
	system("PAUSE");
	return 0;
}

void towers(int n, int source, int temporary, int destination)
{
	if (n == 1)  /*  Base case.  */
	{
		moveDisk(source, destination);
	}
	else
	{
		towers(n - 1, source, destination, temporary);
		moveDisk(source, destination);
		towers(n - 1, temporary, source, destination);
	}

	return;
}

void moveDisk(int source, int destination)
{
	int i = 0;
	int j = 0;
	
	/*  Determine source location.  */
	while (pos[source][i] == EMPTY)
	{
		i++;
	}

	/*  Determine destination location.  */
	while ((pos[destination][j] == EMPTY) && (j < DISKS))
	{
		j++;
	}

	j -= 1;

	/*  Move disk.  */
	printf("\n  Move disk #%d from %c to %c:\n\n",
		pos[source][i], code[source], code[destination]);
	pos[destination][j] = pos[source][i];
	pos[source][i] = EMPTY;

	/*  Print disk positions after move.  */
	printf("\n\n          A B C\n");
	printf("          - - -\n");

	for (j = 0; j < DISKS; ++j)
	{
		printf("%11.1d %d %d\n", pos[0][j], pos[1][j], pos[2][j]);
	}
	printf("\n");

	return;
}

