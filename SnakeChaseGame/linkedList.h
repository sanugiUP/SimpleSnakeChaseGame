/*FILE: linkedList.h
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file contains the function prototypes of linkedList.c file including the structs for generic linked list.
LAST MOD: 2021-10-11*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
  	void* data;
  	struct LinkedListNode* next;
  	
}LinkedListNode;


typedef struct 
{
	LinkedListNode* head;
	int dataSize;
	
}LinkedList;

LinkedList* createLinkedList(int d_size);
void insertStart(LinkedList* list, void* entry);
void* removeStart(LinkedList* list);
void freeLinkedList(LinkedList* list);

#endif
