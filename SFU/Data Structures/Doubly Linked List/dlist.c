#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Allocate memory for a node of type struct nodeStruct and initialize
 * it with the value item. Return a pointer to the new node.
 */
struct nodeStruct* List_createNode(int item){
    struct nodeStruct* newNode = (struct nodeStruct*) malloc(sizeof(struct nodeStruct));
    
    if (newNode == NULL) {
		printf("ERROR: Insufficient memory can not proceed without memory to create the Node");
		return NULL;
	}

    newNode->item = item;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

/*
 * Insert node at the head of the list.
 */
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node){
    if(*headRef == NULL){
        *headRef = node;
    }
    else{
        (*headRef)->previous = node;
        node->next = *headRef;
        *headRef = node;
    }
}

/*
 * Insert node after the tail of the list.
 */
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node){
    if(*headRef == NULL){
        *headRef = node;
    }
    else{
        struct nodeStruct *tail = *headRef;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = node;
        node->previous = tail;
    }
}

/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int List_countNodes (struct nodeStruct *head){
    int count = 0;
    
    struct nodeStruct *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    
    return count;
}

/*
 * Return the first node holding the value item, return NULL if none found
 */
struct nodeStruct* List_findNode(struct nodeStruct *head, int item){
    if(head == NULL){
        return NULL;
    } else {
        while(head != NULL){
            if(head->item == item){
               return head; 
            } 
            head = head->next;
        }
        return NULL;
    }
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node has been properly set to a valid node 
 * in the list. For example, the client code may have found it by calling 
 * List_findNode(). If the list contains only one node, the head of the list 
 * should be set to NULL.
 */
void List_deleteNode(struct nodeStruct **headRef, struct nodeStruct *node) {
    struct nodeStruct *curr = *headRef;
    // check if the head of the list is the node to be deleted
    if (curr == node) {
        *headRef = curr->next;
        if (*headRef != NULL) {
            // update the previous pointer of the new head
            (*headRef)->previous = NULL;
        }
    } else {
        // traverse the list to the node intended to be deleted
        while (curr != NULL) {
            if (curr->next == node) {      
                curr->next = node->next;
                if (curr->next != NULL) {
                    curr->next->previous = curr;
                }
                break;
            }
            curr = curr->next;
        }
    }
    // free the deleted node
    free(node);
}

/*
 * Sort the list in ascending order based on the item field.
 * Any sorting algorithm is fine.
 */
void List_sort(struct nodeStruct **headRef) {
    struct nodeStruct *curr, *next;
    int swapped;
    
    if (*headRef == NULL) {
        return;
    }

    // keep swapping untill its not needed
    do {
        swapped = 0;
        curr = *headRef;
        while (curr->next != NULL) {
            next = curr->next;
            // compare curr node with its next node
            if (curr->item > next->item) {
                // swapping the value
                curr->item ^= next->item;
                next->item ^= curr->item;
                curr->item ^= next->item;
                swapped = 1;
            }
            curr = next;
        }
    } while (swapped);
}