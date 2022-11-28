/*FILE: program.c
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: processes the command line arguments calls the necessary functions from header files and executes the final game
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameOperations.h"
#include "interface.h"
#include "mapsize.h"

int main(int argc, char* argv[])
{
	char** array;
	int i;
	int rows;
	int columns;
	FILE* f;
	
	if(argc == 2)
	{
		f = fopen(argv[1], "r");
		
		/*Making sure if the file can be read. If not, printing an error message.*/
		if(f == NULL)
		{
			printf("Error opening file. Please try again.\n");
		}
		else
		{
			/*initializing variables*/ 
			columns = getNoColumns(argv[1]);
			rows = getNoRows(argv[1]);
			i = 0;	
			
			/*creating the map using metadata by calling the createMap() function in interface.c*/
			array = createMap(argv[1]);
			
			/*calling userInput function to handle game operations*/
			userInput(array, rows, columns);
			
			/*freeing malloc array*/
			for(i = 0; i < rows; i++)
			{
				free(array[i]);
				array[i] = NULL;
			}
			
			free(array);
			array = NULL;
			
			/*freeing memory allocated by the file pointer*/
			fclose(f);
		}	
	}
	else
	{
		printf("Invalid Argument!\nPlease enter the file name next to './maze' (ex: ./maze fileName.txt)\n");
	}
	
	return 0;
}
