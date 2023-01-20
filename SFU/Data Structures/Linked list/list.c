#include <stdio.h>
#include <stdlib.h>
#include "list.h"



/*
 * Allocate memory for a node of type struct nodeStruct and initialize
 * it with the value item. Return a pointer to the new node.
 */
struct nodeStruct* List_createNode(int item){
    struct nodeStruct* newNode = malloc(sizeof(struct nodeStruct));

	if (newNode == NULL) {
		printf("ERROR: Insufficient memory can not proceed without memory to create the Node");
		return NULL;
	}
    
    newNode -> next = NULL;
	newNode -> item = item;

	return newNode;
}

/*
 * Insert node at the head of the list.
 */
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node){ 
    node->next = *headRef;
    *headRef = node;
}

/*
 * Insert node after the tail of the list.
 */
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node){
    if(*headRef == NULL){
        *headRef = node;
    }
    else{
        struct nodeStruct *curr = *headRef;
        
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
    }
	
}

/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int List_countNodes (struct nodeStruct *head){
    if(head == NULL){
       return 0; 
    }

    int count_node = 0;
    struct nodeStruct* curr = head;
    
    while (curr != NULL) {
        count_node++;
        curr = curr->next;
    }
    
    return count_node;
}

/*
 * Return the first node holding the value item, return NULL if none found
 */
struct nodeStruct* List_findNode(struct nodeStruct *head, int item){
    if(head == NULL){
       return NULL; 
    }

	struct nodeStruct* curr = head;
    
    while (curr != NULL) {
        if (curr->item == item) {
            return curr;
        }
        curr = curr->next;
    }

    // Returns NULL if no such node is found
    return NULL;
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node has been properly set to a valid node 
 * in the list. For example, the client code may have found it by calling 
 * List_findNode(). If the list contains only one node, the head of the list 
 * should be set to NULL.
 */
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node){
    if (*headRef == node) {
        // Node to be deleted is the head of the list
        *headRef = node->next;
    } else {
        // Find the previous node
        struct nodeStruct* prev = *headRef;
        
        while (prev->next != node) {
            prev = prev->next;
        }
        // Unlink the node from the list
        prev->next = node->next;
    }
    // Free memory allocated to the node
    free(node);
}

// Sort the list in ascending order using Selection sort 
void List_sort(struct nodeStruct **headRef) {
    struct nodeStruct *curr, *small, *t;

    if (*headRef == NULL) {
        return;
    }

    for (curr = *headRef; curr->next != NULL; curr = curr->next) {
        // First node as current node
        small = curr;
        for (t = curr->next; t != NULL; t = t->next) {
            // Iterate over the list, and slelect the smallest one
            if (t->item < small->item) {
                small = t;
            }
        }
        if (small != curr) {
            // If the smallest node found is not the current node, swap the values of the current and the smallest node
            int temp = curr->item;
            curr->item = small->item;
            small->item = temp;
        }
    }
}
