/*FILE: print.c
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file is responsible for printing the map to the screen
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*NAME: printMap
PURPOSE: The function which prints the map to the screen repetitively when called
IMPORTS: (char**) array, (int) row, (int) column
EXPORTS: none
REMARKS: none*/
void printMap(char** array, int row, int column)
{
	int i; 
	int j;
	
	/*initializing variables*/
	i = 0;
	j = 0;
	
	
	/*printing the array*/
	for(i = 0; i < row; i++)
        {
                for(j = 0; j < column; j++)
                {
                        printf("%c", array[i][j]);
                }
                printf("\n");
        }
}
