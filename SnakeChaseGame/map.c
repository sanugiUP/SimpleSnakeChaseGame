/*FILE: map.c
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file reads the file provided as a command line argument and extracts the metadata information from that file needed to create the map.
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "map.h"


/*NAME: getMetadata
PURPOSE: gets metadata from the input file.
IMPORTS: (int ***) metadataTable, (int *) metadataAmount, (int *) mapRow, (int *) mapCol, (char *) fileName
EXPORTS: none
REMARKS: This function assings the pointers received as imports to the memeory addresses of the relavant variables that store the information read from the input file*/
void getMetadata(int *** metadataTable, int * metadataAmount, int * mapRow, int * mapCol, char *fileName)
{
	FILE *inFile = fopen(fileName, "r");
	int i;
	int j;
    	int ** table; 	
	
	/*Making sure if the file can be read. If not, printing an error message.*/
	if(inFile == NULL)
	{
		printf("Error reading file");
	}
	else
	{
		/*reading the first row to find the amount of metadata, rows and columns and assigning them to integer variables*/
		fscanf(inFile, "%d %d %d", &*metadataAmount, &*mapRow, &*mapCol);
		
		/*Creating 2d array with metadata information later used to create the map*/
		table = (int **) malloc(sizeof(int *) * (*metadataAmount));
		
		for(i = 0 ; i < (*metadataAmount) ; i++)
    		{
        		table[i] = (int *) malloc(sizeof(int) * 3);
   		}
		
		/*reading metadata information from the file an assining them to the relavant position in the array*/
		for(i = 0; i < *metadataAmount; i++)
		{
			for(j = 0; j < 3; j++)
			{
				fscanf(inFile, "%d ", &table[i][j]);
			}
		}
	}
	
	fclose(inFile); /*Freeing file pointer*/
	*metadataTable = table; /* assign the array to be used later in the calling function */
}
