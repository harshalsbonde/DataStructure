//////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
//////////////////////////////////////////////////////////////////////
/* Layout of struct node */
struct node
{
    int data; 
    struct node* next; 
};
//////////////////////////////////////////////////////////////////////
struct node* create_list(void); 
void* xmalloc(size_t size_in_bytes); 
struct node* get_node(int new_data); 
//////////////////////////////////////////////////////////////////////
int main(void)
{
    struct node* even_list = NULL; 
    struct node* odd_list = NULL; 
    struct node* prime_list = NULL; 

    even_list = create_list(); 
    odd_list = create_list(); 
    prime_list = create_list(); 

    return (0); 
}
/////////////////////////////////////////////////////////////////////
struct node* create_list(void)
{
    struct node* head_node = NULL; 

    head_node = get_node(0); 
    return (head_node); 
}
/////////////////////////////////////////////////////////////////////
struct node* get_node(int new_data)
{
    struct node* new_node = NULL; 

    new_node = (struct node*)xmalloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = NULL; 

    return (new_node); 
}
//////////////////////////////////////////////////////////////////////
void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL; 

    ptr = malloc(size_in_bytes); 
    if(ptr == NULL)
    {
        puts("xmalloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}
///////////////////////////////////////////////////////////////////////
