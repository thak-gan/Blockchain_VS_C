#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

NODE * reverse(NODE * node) {
    NODE * temp;
    NODE * previous = NULL;
    while (node != NULL) {
        temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }
    return previous;
}

void init(NODE** head) {
    *head = NULL;
}

NODE* add(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(0); // no memory available
    }
    temp->data = data;
    temp->next = node;
    node = temp;
    return node;
}
void blue()
{
    printf("\033[0;34m");

}

void black()
{
    printf(" \033[0;30m");
}


void print_list(NODE* head) {
    head = reverse(head);
    NODE * temp;
    int indent = 0;
    
    
    for (temp = head; temp; temp = temp->next, indent = indent)
    {
        
        printf("    .................................\n");
    printf("    |%*sPrevious hash\t%d\n", indent,"", temp->data.info.previous_block_hash);
        printf("    |%*sBlock hash\t%d\n", indent,"", temp->data.info.block_hash);
    printf("    |%*sTransaction\t%s\n", indent,"", temp->data.info.transactions);
        blue();
        printf("    .................................\n");
        if(temp->next!=NULL)
        {
        printf("                    |\n");
        printf("                    |\n");
        printf("                    |\n");
        printf("                    v");
        }


        printf("%*s\n\n", indent, "");
        black();
        
    }

    printf("\r\n");
}

void add_at(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    temp->data = data;
    temp->next = node->next;
    node->next = temp;
}

void remove_node(NODE* head) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    temp = head->next;
    head->next = head->next->next;
    free(temp);
}

NODE *free_list(NODE *head) {
    NODE *tmpPtr = head;
    NODE *followPtr;
    while (tmpPtr != NULL) {
        followPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
        free(followPtr);
    }
    return NULL;
}