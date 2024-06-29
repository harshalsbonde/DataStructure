//////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////
struct node
{
    int data; 
    struct node* next; 
}; 
/////////////////////////////////////////////////////////////////////
int main(void)
{
    struct node* start_node = NULL; 

    start_node = (struct node*)malloc(sizeof(struct node)); 
    if(start_node == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    start_node->data = 10; 
    start_node->next = (struct node*)malloc(sizeof(struct node)); 
    if(start_node->next == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    start_node->next->data = 20; 
    start_node->next->next = (struct node*)malloc(sizeof(struct node)); 
    if(start_node->next->next == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    start_node->next->next->data = 30; 
    start_node->next->next->next = NULL; 

    struct node* run = start_node;
    while(run != NULL)
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    }

    free(start_node->next->next); 
    free(start_node->next); 
    free(start_node); 
    start_node = NULL; 

    return (0); 
}
/////////////////////////////////////////////////////////////////////////////
