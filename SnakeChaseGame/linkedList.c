/*FILE: linkedList.h
AUTHOR: Sanugi Perera
CURTIN ID: 20542524
UNIT: COMP1000
PURPOSE: this file contains all the operations that can be performed using a generic linked list.
LAST MOD: 2021-10-11*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


/*NAME: createLinkedList
PURPOSE: Initializes a generic linked list
IMPORTS: (int) d_size
EXPORTS: (LinkedList *) list
REMARKS: none*/
LinkedList* createLinkedList(int d_size)
{
	LinkedList* list;
  	list = (LinkedList*)malloc(sizeof(LinkedList));
 	(*list).head = NULL;
 	(*list).dataSize = d_size;
 	
 	return list;
}


/*NAME: insertStart
PURPOSE: creates a LinkedListNode with the data imported and inserts it at the beginning of the generic linked list
IMPORTS: (LinkedList *) list, (void *) entry
EXPORTS: none
REMARKS: none*/
void insertStart(LinkedList* list, void* entry)
{
	LinkedListNode* newNode;
	
	newNode =(LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->data = malloc(list->dataSize);
	
	memcpy(newNode->data, entry, list->dataSize); 
	/*dest/src/number of bytes*/
	
	newNode->next = list->head;
	list->head = newNode;
	
}


/*NAME: removeStart
PURPOSE: removes the first LinkedListNode from the imported LinkedList and frees the node while exporting its data.
IMPORTS: (LinkedList *) list
EXPORTS: (void *) p
REMARKS: none*/
void* removeStart(LinkedList* list)
{
	LinkedListNode* temp;
	void *p;
	
	temp = list->head;
	p = temp->data;
	list->head = list->head->next;
	
	free(temp->data);
	free(temp);
	
	return p;
}


/*NAME: freeLinkedList
PURPOSE: frees the imported liked list, its nodes and node data.
IMPORTS: (LinkedList *) list
EXPORTS: none
REMARKS: none*/
void freeLinkedList(LinkedList* list)
{
	LinkedListNode* node;
	LinkedListNode* nextNode;
	
	node = list->head;
	
	/*iterating till the list is empty and freeing all the memory occupied by each node and its data*/
	while(node != NULL)
	{
		nextNode = node->next;
		free(node->data); /*freeing the node data*/
		free(node); /*freeing the node*/
		node = nextNode; /*get next node*/
	}

	free(list);
	list = NULL; /*assining pointer to NULL*/
}

