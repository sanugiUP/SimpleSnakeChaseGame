/*FILE: interface.c
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: creates the map by using the metadata information from the map.c file
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"


/*NAME: createMap
PURPOSE: assigns the position of the player, snake, boundary, walls and goal on the map 
IMPORTS: char* fileName
EXPORTS: (char**) array
REMARKS: This function creates the map that is used by other functions in other .c files of the program*/
char** createMap(char *fileName)
{
	int rows;
	int columns;
	int mdAmount;
	int* rPtr; /*pointer to number of rows*/
	int* cPtr; /*pointer to number of columns*/
	int* mdAmtPtr; /*pointer to the amount of metadata objects*/
	int** metaDataTable;
	int*** metadataTablePtr;
	char** array;
	int i; 
	int j;
	int row_index;
	int column_index;
	
	
	/*initializing variables*/
	rows = 0;
	columns = 0;
	mdAmount = 0;
	j = 0;
	i = 0;
	row_index = 0;
	column_index = 0;
	
	
	/*assigning the pointers to variables respectively*/
	rPtr = &rows;
	cPtr = &columns;
	mdAmtPtr = &mdAmount;
	
	
	/*assigning the metadata array to a pointer*/
	metadataTablePtr = &metaDataTable;
	
	
	/*calling the getMetadata function in map.c*/	
	getMetadata(metadataTablePtr, mdAmtPtr, rPtr, cPtr, fileName);
	
	
	/*creating malloc 2-D array for the game interface*/
	array = (char**)malloc(sizeof(char*) * rows);
	for(i = 0; i < rows; i++)
	{
		array[i] = (char *)malloc(sizeof(char) * rows);
	}
	
	
	/*assigning empty space for each element in the 2-D array*/
	for(i = 0; i < rows; i++)
        {
                for(j = 0; j < columns; j++)
                {
                        array[i][j] = ' ';
                }
        }
	
	
	/*Assigning the positions for player, goal and objects in the map*/
	for(j = 0; j < mdAmount; j++)
	{
		if(metaDataTable[j][2] == 0) /*column index of the metaDataTable will remain the same (2), since the metsDataTable contain 3 rows <mapRow_index> <mapCol_index> <object_code>*/
		{
			row_index = metaDataTable[j][0];
			column_index = metaDataTable[j][1];

			array[row_index][column_index] = '^';
		}
		else if(metaDataTable[j][2] == 2)
		{
			row_index = metaDataTable[j][0];
			column_index = metaDataTable[j][1];

			array[row_index][column_index] = 'x';
		}
		else if(metaDataTable[j][2] == 3)
		{
			row_index = metaDataTable[j][0];
                       column_index = metaDataTable[j][1];

                       array[row_index][column_index] = 'o';
		}
		else if(metaDataTable[j][2] == 1)
		{
			row_index = metaDataTable[j][0];
                       column_index = metaDataTable[j][1];

                      	array[row_index][column_index] = '~';
		}
	}
	
	
	/*building the maze boundary(assigning '|')*/
	for(i = 1; i < rows; i++)
	{
		array[i][0] = '|';
		array[i][columns-1] = '|';
	}
	

	/*building the maze boundary(assigning '-')*/
	for(i = 1; i < columns-1; i++)
	{
		array[0][i] = '-';
		array[rows - 1][i] = '-';
	}


	/*assigning the # to the four corners of the map*/
        array[0][0] = '#';
        array[0][columns-1] = '#';
        array[rows-1][0] = '#';
        array[rows-1][columns-1] = '#';
        
	
	/*freeing malloc metadata array*/
	for(i = 0; i < mdAmount; i++)
	{
		free(metaDataTable[i]);
		metaDataTable[i] = NULL;
	}
	free(metaDataTable);
	metaDataTable = NULL;
	
	return array;	
	
}

