#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

// #region snippet1
static struct nodo {
    int value;
    struct nodo *next; // pointer to the next instance
} *head = NULL, *p, *q; // 3 pointers to a nodo
// #endregion snippet1

int AddToHead(int inputValue) {
    void * puntatore =  malloc(sizeof(struct nodo));
    p = (struct nodo *) puntatore;

    if (p != NULL) { // allocate memory for a node
        p->value = inputValue;
        p->next = head;
        head = p; // replace the head
        printAll();
        return LIST_OK;
    } else {
        return LIST_ERROR;
    }
}

int RemoveFromHead(int *v) {
    if (head != NULL) {
        *v = head->value; // return a copy of the value that we are removing
        p = head;
        head = head->next; // replace the head
        free(p); // free the memory of the former head node
        printAll();
        return LIST_OK;
    } else
        return LIST_ERROR;
}

int AddToTail(int v) {
    if (head == NULL) // if the list is empty just add a new item
        return AddToHead(v);
    else {
        q = head;
        while (q->next != NULL) {// scroll the list to the end
            q = q->next;
        }
        if ((p = (struct nodo *) malloc(sizeof(struct nodo))) != NULL) { // allocate memory for a new item
            p->value = v;
            p->next = NULL;
            q->next = p;  // insert the new item to the end of the list
            printAll();
            return LIST_OK;
        } else
            return LIST_ERROR;
    }
}

int RemoveFromTail(int *v) {
    if (head == NULL) {
        return LIST_ERROR; // cannot remove from an empty list
    } else if (head->next == NULL) { // there is just 1 item in the list, the head
        *v = head->value;
        free(head);
        head = NULL;
        printAll();
        return LIST_OK;
    } else {
        q = head;
        while (q->next->next != NULL) { // scroll the list to the end
            q = q->next;
        }
        *v = q->next->value; // return a copy of the tail's value
        free(q->next);
        q->next = NULL; // reset the pointer to the former tail
        printAll();
        return LIST_OK;
    }
}

void ClearAll(void) {
    int v;
    while (RemoveFromHead(&v) != LIST_ERROR);
    printAll();
}

/**
 * Print a single node
 * @param item pointer to the node
 */
void printItem(struct nodo *item) {
    if (item != NULL) {
        printf("address: [%p], value: [%d], next: [%p]", (void *) item, item->value, (void *) item->next);
    }
}

void printAll() {
    p = head;
    int counter = 0;
    if (p == NULL) {
        printf("Empty list!\n");
    }
    while (p != NULL) { // scroll the entire list
        printf("%d) ", counter++);
        printItem(p);
        printf("\n");
        p = p->next;
    }
}

