/*FILE: gameOperations.h
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file contains the function prototypes of gameOperations.c file.
LAST MOD: 2021-10-11*/

#ifndef GAMEOPERATIONS_H
#define GAMEOPERATIONS_H
#include "linkedList.h"

void snakeMovement(char** array, int row, int column, int* begin, LinkedList *slist, int player_r, int player_c);
void playerUp(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list);
void playerLeft(char** array, int row, int column, int *begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list);
void playerRight(char** array, int row, int column, int *begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list);
void playerDown(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list);
void snakeUndo(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list);
void playerUndo(char** array, int row, int column, int* begin, LinkedList *plist, LinkedList *slist, LinkedList *position_list);
void userInput(char** array, int row, int column);

#endif
