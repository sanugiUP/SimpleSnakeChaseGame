/*FILE: map.c
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file reads the file provided as a command line argument and extracts the metadata information from that file needed to create the map.
ASSERTION: the functions in this file assumes that the first line of the input file contain <metadata amount> <number of rows> <number of columns> in the first line respectively.
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "mapsize.h"


/*NAME: getNoRows
PURPOSE: gets the number of rows from the input file.
IMPORTS: (char *) fileName
EXPORTS: (int) row
REMARKS: This function reads the first line of the file and gets the number of rows*/
int getNoRows(char *fileName)
{
	int md;
	int row;
	int col;
	
	FILE *inFile = fopen(fileName, "r");
	
	/*Making sure if the file can be read. If not, printing an error message.*/
	if(inFile == NULL)
	{
		printf("Error reading file");
	}
	else
	{
		fscanf(inFile, "%d %d %d", &md, &row, &col);		
	}
	
	fclose(inFile);
	
	return row;
}


/*NAME: getNoColumns
PURPOSE: gets the number of columns from the input file.
IMPORTS: (char *) fileName
EXPORTS: (int) col
REMARKS: This function reads the first line of the file and gets the number of columns*/
int getNoColumns(char *fileName)
{
	int md;
	int row;
	int col;
	
	FILE *inFile = fopen(fileName, "r");
	
	/*Making sure if the file can be read. If not, printing an error message.*/
	if(inFile == NULL)
	{
		printf("Error reading file");
	}
	else
	{
		fscanf(inFile, "%d %d %d", &md, &row, &col);		
	}
	
	fclose(inFile);
	
	return col;
}


/*NAME: getMetadataAmount
PURPOSE: gets the amount of metadata from the input file.
IMPORTS: (char *) fileName
EXPORTS: (int) md
REMARKS: This function reads the first line of the file and gets the amount of metadata*/
int getMetadataAmount(char *fileName)
{
	int md;
	int row;
	int col;
	
	FILE *inFile = fopen(fileName, "r");
	
	/*Making sure if the file can be read. If not, printing an error message.*/
	if(inFile == NULL)
	{
		printf("Error reading file");
	}
	else
	{
		fscanf(inFile, "%d %d %d", &md, &row, &col);		
	}
	
	fclose(inFile);
	
	return md;
}
