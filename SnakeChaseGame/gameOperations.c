/*FILE: gameOperations.c
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file contians the implementation of all the functions related to receiving user input and manupulating the snake and player accordingly.
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "terminal.h"
#include "gameOperations.h"
#include "linkedList.h"


/*NAME: snakeMovement
PURPOSE: contains the snake algorithm
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (int) player_r, (int) player_c
EXPORTS: none
REMARKS: generates the position of the snake after each user movement and records it in a linked list (slist)*/
void snakeMovement(char** array, int row, int column, int* begin, LinkedList *slist, int player_r, int player_c)
{
	int i;
	int j;
	int sr; /*snake row position coordinate*/
	int sc; /*snake column position coordinate*/
	int rd; /*row difference between player coordinate and snake coordinate*/
	int cd; /*column difference between player coordinate and snake coordinate*/
	int *s_array = (int*) malloc(2 * sizeof(int));
	
	/*Finding snake from the map*/
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(array[i][j] == '~')
			{
				sr = i;
				sc = j;
			} 
		} 
	}
	
	/*row and column differences*/
	rd = player_r - sr;
	cd = player_c - sc;
	
	/*snake movement algorithm implemeted taking in the row (rd) and column(cd) difference between the snake and the player*/ 
	if(rd > 0 && cd >= 0)
	{
		if(array[sr+1][sc] == 'o' || array[sr+1][sc] == '|' || array[sr+1][sc] == '-' || array[sr+1][sc] == 'x')
		{
			/*snake will not move*/
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
		}
		else if(array[sr+1][sc] == '^' || array[sr+1][sc] == 'v' || array[sr+1][sc] == '>' || array[sr+1][sc] == '<' )
		{	
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
			array[sr][sc] = ' ';
			array[sr+1][sc] = '~'; 
			*begin = 0;
			printf("\n\nYou Lose!\n\n");
		}
		else
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
    			array[sr][sc] = ' ';
			array[sr+1][sc] = '~';
		}		
	}
	else if(rd > 0 && cd < 0)
	{
		if(array[sr+1][sc] == '^' || array[sr+1][sc] == 'v' || array[sr+1][sc] == '>' || array[sr+1][sc] == '<' )
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
			array[sr][sc] = ' ';
			array[sr+1][sc] = '~'; 
			*begin = 0;
			printf("\n\nYou Lose!\n\n");
		}
		else if(array[sr+1][sc] == 'o' || array[sr+1][sc] == '|' || array[sr+1][sc] == '-' || array[sr+1][sc] == 'x')
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
		}
		else
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
    			array[sr][sc] = ' ';
			array[sr+1][sc] = '~';
		}		
	}
	else if(rd == cd)
	{
		if(array[sr][sc+1] == '^' || array[sr][sc+1] == 'v' || array[sr][sc+1] == '>' || array[sr][sc+1] == '<' )
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
			array[sr][sc] = ' ';
			array[sr][sc+1] = '~'; 
			*begin = 0;
			printf("\n\nYou Lose!\n\n");
		}
		else if(array[sr][sc+1] == 'o' || array[sr][sc+1] == '|' || array[sr][sc+1] == '-' || array[sr][sc+1] == 'x')
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
		}
		else
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
    			array[sr][sc] = ' ';
			array[sr][sc+1] = '~';
		}		
	}
	else if(rd <= 0 && cd > 0)
	{
		if(array[sr][sc+1] == 'o' || array[sr][sc+1] == '|' || array[sr][sc+1] == '-' || array[sr][sc+1] == 'x')
		{
			/*snake will not move*/
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
		}
		else if(array[sr][sc+1] == '^' || array[sr][sc+1] == 'v' || array[sr][sc+1] == '>' || array[sr][sc+1] == '<' )
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
			array[sr][sc] = ' ';
			array[sr][sc+1] = '~'; 
			*begin = 0;
			printf("\n\nYou Lose!\n\n");
		}
		else
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
    			array[sr][sc] = ' ';
			array[sr][sc+1] = '~';
		}	
	}
	else if(rd <= 0 && cd == 0)
	{
		if(array[sr-1][sc] == 'o' || array[sr-1][sc] == '|' || array[sr-1][sc] == '-' || array[sr-1][sc] == 'x')
		{
			/*snake will not move*/
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
		}
		else if(array[sr-1][sc] == '^' || array[sr-1][sc] == 'v' || array[sr-1][sc] == '>' || array[sr-1][sc] == '<' )
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
			array[sr][sc] = ' ';
			array[sr-1][sc] = '~'; 
			*begin = 0;
			printf("\n\nYou Lose!\n\n");
		}
		else
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
    			array[sr][sc] = ' ';
			array[sr-1][sc] = '~';
		}	
	}	
	else if(rd < 0 && cd < 0)
	{
		if(array[sr][sc-1] == 'o' || array[sr][sc-1] == '|' || array[sr][sc-1] == '-' || array[sr][sc-1] == 'x')
		{
			/*snake will not move*/
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
		}
		else if(array[sr][sc-1] == '^' || array[sr][sc-1] == 'v' || array[sr][sc-1] == '>' || array[sr][sc-1] == '<' )
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
			array[sr][sc] = ' ';
			array[sr][sc-1] = '~'; 
			*begin = 0;
			printf("\n\nYou Lose!\n\n");
		}
		else
		{
			s_array[0] = sr;
			s_array[1] = sc;
			insertStart(slist, s_array);
			
    			array[sr][sc] = ' ';
			array[sr][sc-1] = '~';
		}	
	}	
	
	free(s_array);    			
}


/*NAME: playerUp
PURPOSE: handles the game operation when user input 'w' key
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (LinkedList *) plist, (LinkedList *) position_list
EXPORTS: none
REMARKS: re prints the map after changing the loction of the player and records the player movement across the map in plist*/
void playerUp(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list)
{
	int i = 0;
	int j = 0;
	int sr = 0;
	int sc = 0;
	int rd = 0;
	int cd = 0;
	char position;
	int *s_array = (int*) malloc(2 * sizeof(int));
	int *p_array = (int*) malloc(2 * sizeof(int));
	
	system("clear");
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			/*Finding the player's current position on the map*/
			if(array[i][j] == '^' || array[i][j] == 'v' || array[i][j] == '>' || array[i][j] == '<' )
			{		
		    		if(array[i-1][j] == 'o' || array[i-1][j] == '|' || array[i-1][j] == '-') /*Obstruction by objects condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Initial Location of the player*/
					insertStart(position_list, &position);
					
		    			/*player remains the same yet the snake will move*/
		    			rd = (i-1);
		    			cd = j;
		    			
		    			/*Calling the function with the snake algorithm*/
		    			snakeMovement(array, row, column, begin, slist, rd, cd);
		    			
		    		}
		    		else if(array[i-1][j] == 'x') /*Winning Condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
					
					array[i][j] = ' ';
		        		array[i-1][j] = '^';
				    
		        		*begin = 0;
		        		printf("\n\nYou Win!\n\n");
		        
		    		}
		    		else if(array[i-1][j] == '~') /*Losing condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
					
					s_array[0] = sr;
					s_array[1] = sc;
					insertStart(slist, s_array); /*Inserting position of the snake in to the linked list - slist*/
							
		    			array[i][j] = ' ';
		    			array[sr][sc] = ' ';
		        		array[i-1][j] = '~';
		        		
		        		*begin = 0;
		        		printf("\n\nYou Lose!\n\n");
		   
		    		}
		    		else
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
					
		    			array[i][j] = ' ';
		        		array[i-1][j] = '^';
		        		
		    			rd = (i-1);
		    			cd = j;
		    			
		    			/*Calling the function with the snake algorithm*/
		    			snakeMovement(array, row, column, begin, slist, rd, cd);
		    		}	
		    	}
		}
	}

	/*calling printMap function from print.c*/
	printMap(array, row, column);
	
	/*freeing the arrays used to send data to insertStart function*/
	free(s_array);
	free(p_array);
}


/*NAME: playerLeft
PURPOSE: handles the game operation when user input 'a' key
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (LinkedList *) plist, (LinkedList *) position_list
EXPORTS: none
REMARKS: re prints the map after changing the loction of the player and records the player movement across the map in plist*/
void playerLeft(char** array, int row, int column, int *begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list)
{
	int i = 0;
	int j = 0;
	int sr = 0;
	int sc = 0;
	int rd = 0;
	int cd = 0;
	char position;
	int *s_array = (int*) malloc(2 * sizeof(int));
	int *p_array = (int*) malloc(2 * sizeof(int));
	
	system("clear");
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			/*Finding the player's current position on the map*/
			if(array[i][j] == '^' || array[i][j] == 'v' || array[i][j] == '>' || array[i][j] == '<' )
			{	 
		    		if(array[i][j-1] == 'o' || array[i][j-1] == '|' || array[i][j-1] == '-' ) /*Obstruction by objects condition*/
                    		{
                    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
		    			/*player remains the same yet the snake will move*/
		    			rd = i;
		    			cd = (j-1);

					/*Calling the function with the snake algorithm*/
					snakeMovement(array, row, column, begin, slist, rd, cd);		
		    		}
		    		else if(array[i][j-1] == 'x') /*Winning Condition*/
                    		{
                    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					array[i][j] = ' ';
        			    	array[i][j-1] = '<';
        			    
                        		*begin = 0;
                        		printf("\n\nYou Win!\n\n");
                    		}
                    		else if(array[i][j-1] == '~') /*Losing condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					s_array[0] = sr;
					s_array[1] = sc;
					insertStart(slist, s_array); /*Inserting position of the snake in to the linked list - slist*/
							
		    			array[i][j] = ' ';
		    			array[sr][sc] = ' ';
		        		array[i][j-1] = '~';
		        		
		        		*begin = 0;
		        		printf("\n\nYou Lose!\n\n");
		    		}
		    		else
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array);  /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
		    			array[i][j] = ' ';
        			    	array[i][j-1] = '<';
        			    	
        			    	rd = i;
		    			cd = (j-1);
		    			
		    			/*Calling the function with the snake algorithm*/
		    			snakeMovement(array, row, column, begin, slist, rd, cd);	
		    		}		
		    	}
		}
	}
	
	/*calling printMap function from print.c*/	
	printMap(array, row, column);
	
	/*freeing the arrays used to send data to insertStart function*/
	free(s_array);
	free(p_array);
}


/*NAME: playerRight
PURPOSE: handles the game operation when user input 'd' key
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (LinkedList *) plist, (LinkedList *) position_list
EXPORTS: none
REMARKS: re prints the map after changing the loction of the player and records the player movement across the map in plist*/
void playerRight(char** array, int row, int column, int *begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list)
{
	int i = 0;
	int j = 0;
	int sr = 0;
	int sc = 0;
	int rd = 0;
	int cd = 0;
	char position;
	int *s_array = (int*) malloc(2 * sizeof(int));
	int *p_array = (int*) malloc(2 * sizeof(int));
	
	system("clear");
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			/*Finding the player's current position on the map*/
        		if(array[i][j] == '^' || array[i][j] == 'v' || array[i][j] == '>' || array[i][j] == '<' )
        		{
                    		if(array[i][j+1] == 'o' || array[i][j+1] == '|' || array[i][j+1] == '-' ) /*Obstruction by objects condition*/
                    		{
                    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					/*player remains the same yet the snake will move*/
		    			rd = i;
		    			cd = (j+1);
		    			
		    			/*Calling the function with the snake algorithm*/
		    			snakeMovement(array, row, column, begin, slist, rd, cd);
		    							
                    		}
                    		else if(array[i][j+1] == 'x') /*Winning Condition*/
                    		{
                    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					array[i][j] = ' ';
                        		j++;
        			    	array[i][j] = '>';
                        		*begin = 0;
                        		printf("\n\nYou Win!\n\n");
                        		
                    		}
                    		else if(array[i][j+1] == '~') /*Losing condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
					
					s_array[0] = sr;
					s_array[1] = sc;
					insertStart(slist, s_array); /*Inserting position of the snake in to the linked list - slist*/
				
		    			array[i][j] = ' ';
		    			array[sr][sc] = ' ';
		        		array[i][j+1] = '~';
		        		
		        		*begin = 0;
		        		printf("\n\nYou Lose!\n\n");
		   
		    		}
                    		else
                    		{
                    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
                        		array[i][j] = ' ';
                        		j++;
        			    	array[i][j] = '>';
        			    	
        			    	rd = i;
		    			cd = (j+1);
		    			
		    			/*Calling the function with the snake algorithm*/
		    			snakeMovement(array, row, column, begin, slist, rd, cd);		   	
                    		}
                	}
		}
	}
	
	/*calling printMap function from print.c*/	
	printMap(array, row, column);
	
	/*freeing the arrays used to send data to insertStart function*/
	free(s_array);
	free(p_array);
}


/*NAME: playerDown
PURPOSE: handles the game operation when user input 's' key
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (LinkedList *) plist, (LinkedList *) position_list
EXPORTS: none
REMARKS: re prints the map after changing the loction of the player and records the player movement across the map in plist*/
void playerDown(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list)
{
	int i = 0;
	int j = 0;
	int sr = 0;
	int sc = 0;
	int rd = 0;
	int cd = 0;
	char position;
	int *s_array = (int*) malloc(2 * sizeof(int));
	int *p_array = (int*) malloc(2 * sizeof(int));
	
	system("clear");
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{	
			/*Finding the player's current position on the map*/
			if(array[i][j] == '^' || array[i][j] == 'v' || array[i][j] == '>' || array[i][j] == '<' )
			{	
		    		if(array[i+1][j] == 'o' || array[i+1][j] == '|' || array[i+1][j] == '-' ) /*Obstruction by objects condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					/*player remains the same yet the snake will move*/
		    			rd = (i+1);
		    			cd = j;

					/*Calling the function with the snake algorithm*/
					snakeMovement(array, row, column, begin, slist, rd, cd);
		    		}
		    		else if(array[i+1][j] == 'x') /*Winning Condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					array[i][j] = ' ';
					i++;
				    	array[i][j] = 'v';
				     
					*begin = 0;
					printf("\n\nYou Win!\n\n");
		    		}
		    		else if(array[i+1][j] == '~') /*Losing condition*/
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
					
					s_array[0] = sr;
					s_array[1] = sc;
					insertStart(slist, s_array); /*Inserting position of the snake in to the linked list - slist*/
				
		    			array[i][j] = ' ';
		    			array[sr][sc] = ' ';
		        		array[i+1][j] = '~';
		        		
		        		*begin = 0;
		        		printf("\n\nYou Lose!\n\n");
		   
		    		}
		    		else
		    		{
		    			position = array[i][j];	
					p_array[0] = i;
					p_array[1] = j; 
					insertStart(plist, p_array); /*Inserting Location of the player in to the linked list - plist*/
					insertStart(position_list, &position); /*Inserting position of the player in to the linked list - position_list*/
				
					array[i][j] = ' ';
					i++;
				    	array[i][j] = 'v';
				    	
				    	rd = (i+1);
		    			cd = j;
		    			
		    			/*Calling the function with the snake algorithm*/
		    			snakeMovement(array, row, column, begin, slist, rd, cd);	
		    		}
			}
		}
	}
	
	/*calling printMap function from print.c*/	
	printMap(array, row, column);
	
	/*freeing the arrays used to send data to insertStart function*/
	free(s_array);
	free(p_array);
}


/*NAME: snakeUndo
PURPOSE: undo the movement of the snake
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (LinkedList *) plist, (LinkedList *) position_list
EXPORTS: none
REMARKS: none*/
void snakeUndo(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list)
{
	int i;
	int j;
	int rw;
	int col;
	void *p;
	char position = '~';
	int r; 
	int c;
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			/*finding the position of the snake on map*/
			if(array[i][j] == '~')
			{
				rw = i;
				col = j;			
			}
		}
	}
	
	
	if(slist->head == NULL)
	{
		/*do nothing (snake resumes initial position)*/
	}
	else
	{
		/*snake position will change to the coordinated in the first node of the snake movement linked list (slist)*/
		array[rw][col] = ' ';
		p = removeStart(slist);
		r = *(int *)(p);
		c = *((int *)(p)+1);
		array[r][c] = position;	
	}
}


/*NAME: playerUndo
PURPOSE: undo the movement of the player
IMPORTS: (char**) array, (int) row, (int) column, (*int) begin, (LinkedList *) slist, (LinkedList *) plist, (LinkedList *) position_list
EXPORTS: none
REMARKS: none*/
void playerUndo(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list)
{
	int i;
	int j;
	int rw;
	int col;
	void *p;
	void *cp;
	char position = '~';
	int r; 
	int c;
	
	system("clear");
	
	/*calling snake movement undo function*/
	snakeUndo(array, row, column, begin, plist, slist, position_list);
	
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			/*finding the position of the player on map*/
			if(array[i][j] == '^' || array[i][j] == 'v' || array[i][j] == '>' || array[i][j] == '<' )
			{
				rw = i;
				col = j;			
			}
		}
	}
	
	if(plist->head == NULL)
	{
		/*do nothing (player resumes initial position)*/
	}
	else
	{
		array[rw][col] = ' ';
		p = removeStart(plist);
		r = *(int *)(p);
		c = *((int *)(p)+1);
		cp = removeStart(position_list);
		position = *(char *)(cp);
		array[r][c] = position;	
	}
	
	/*calling printMap function from print.c*/	
	printMap(array, row, column);
}


/*NAME: userInput
PURPOSE: takes in user input and changes the location of the player while printing the map on the screen each time user gives the correct input
IMPORTS: (char**) array, (int) row, (int) column
EXPORTS: none
REMARKS: This function solely handles user input and processes it by calling the appropiriate function for each input*/
void userInput(char** array, int row, int column)
{
	int b;
	int* begin;
	char userInput;
	
	/*create Linked List for storing player movements and snake movements*/
  	LinkedList* slist = createLinkedList(sizeof(int*));
	LinkedList* plist = createLinkedList(sizeof(int*));
	LinkedList* position_list = createLinkedList(sizeof(char));
	
	/*Initialising Variables and pointers*/
	b = 1;
	userInput = 'w';
	begin = &b;
	
	/*clearing the screen before printing the maze*/
	system("clear");
	
	/*calling printMap function from printMap.c*/
	printMap(array, row, column);
	
	while(b != 0)
	{
	
		/*disableBuffer();*/
		disableBuffer();
		
		/*asking for user input*/
		scanf("%c", &userInput);
		
		if(userInput == 'w')
		{
			playerUp(array, row, column, begin, plist, slist, position_list);
		}
		else if(userInput == 'a')
		{	
			playerLeft(array, row, column, begin, plist, slist, position_list);
		}
		else if(userInput == 'd')
		{
			playerRight(array, row, column, begin, plist, slist, position_list);
		}
		else if(userInput == 's')
		{
			playerDown(array, row, column, begin, plist, slist, position_list);
		}
		else if(userInput == 'u')
		{
			playerUndo(array, row, column, begin, plist, slist, position_list);
		}
		else
		{
			/*do nothing*/
		}
		
		enableBuffer();	
	}
	
	/*freeing linked list created using generic list*/
	freeLinkedList(position_list);
	freeLinkedList(plist);
	freeLinkedList(slist);
	begin = NULL;
}

