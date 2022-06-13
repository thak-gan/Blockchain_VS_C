#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "block.h"
#include "linkedlist.h"
#include "linkedlist.c"
#include "hash.c"


extern hash string_hash(void *string);

typedef enum party_code_t {PARTY1, PARTY2, PARTY3, MAX_PARTIES} party_code;
char *party_name[MAX_PARTIES] = {"PARTY1", "PARTY2", "PARTY3"};
int count_votes[3];
static party_code get_vote()
{
    int r  ;
    printf("cast your vote");
    scanf("%d",&r);
    count_votes[r]++;
    
    return r%MAX_PARTIES;
}

void main(int argc, char const *argv[])
{  

    int voters ;
printf("please input number of voters");
scanf("%d",&voters);
    srand(time(NULL));

    NODE *head;
    DATA genesis_element;
    init(&head);

    // First block is created manually with hash = 0
    transaction genesis_transactions = {party_name[get_vote()]};
    block_t genesis_block = {0, string_hash(genesis_transactions), genesis_transactions};
    genesis_element.info = genesis_block;
    head = add(head, genesis_element);

    // Now, we are going to submmit n random votes
    int i, previous_hash = genesis_element.info.previous_block_hash;
    transaction trans_list = (transaction) malloc (voters * sizeof(char)*10);
    for(i=0;i<voters-1;i++)
    {
        DATA *el = malloc(sizeof(DATA));
        block_t *b = malloc(sizeof(block_t));



        transaction t = {party_name[get_vote()]};
        strcat(trans_list, t);
        b->previous_block_hash = previous_hash;
        b->block_hash = string_hash(trans_list);
        b->transactions = t;
        el->info = *b;
        previous_hash = b->block_hash;
        head = add(head, *el);

    }
    print_list(head);
    int max=0;
    int index;
     for (i = 0; i < 3; i++)
     {
            if (count_votes[i] > max)
            {
                max = count_votes[i];
                index=i;
            }
            
     }

     switch (index)
            {
                case 0:
                    printf("Winning Party = %s","PARTY1");
                        break;
                case 1:
                    printf("Winning Party = %s","PARTY2");
                        break;
                case 2:
                    printf("Winning Party = %s","PARTY3");
                        break;
            }
                
     
    
    return;
}
