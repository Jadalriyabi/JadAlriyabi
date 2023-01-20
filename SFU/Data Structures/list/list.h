#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/*
 * list.h
 *
 *  Created on: Jan 16, 2023
 *      Author: Jad Alriyabi
 */

struct nodeStruct {
  int item;
  struct nodeStruct *next;
};

/* Function prototypes */
struct nodeStruct* List_createNode(int item);
int List_nodeAlreadyInserted(struct nodeStruct *headRef, struct nodeStruct *node);
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node);
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node);
int List_countNodes (struct nodeStruct *head);
struct nodeStruct* List_findNode(struct nodeStruct *head, int item);
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node);
void List_sort (struct nodeStruct **headRef);

#endif




