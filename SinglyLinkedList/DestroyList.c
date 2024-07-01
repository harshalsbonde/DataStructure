/////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////////////////////////
struct node{
    int data; 
    struct node* next; 
}; 
/////////////////////////////////////////////////////////////////////////////////////////
struct node* create_list(void); 
void insert_start(struct node* p_head_node, int new_data); 
void show_list(struct node* p_head_node, char* msg); 
void destroy_list(struct node* p_head_node); 
/////////////////////////////////////////////////////////////////////////////////////////
void* xmalloc(size_t number_of_bytes); 
struct node* get_node(int new_data); 
/////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    struct node* even_list = NULL; 
    
    even_list = create_list(); 

    show_list(even_list, "even_list:just after creation"); 
    insert_start(even_list, 10); 
    insert_start(even_list, 20); 
    insert_start(even_list, 30); 
    insert_start(even_list, 40); 
    show_list(even_list, "even_list:after inserting 10, 20, 30, 40"); 

    return (EXIT_SUCCESS); 
}
/////////////////////////////////////////////////////////////////////////////////////////
struct node* create_list(void)
{
    struct node* p_head_node = NULL; 

    p_head_node = get_node(0); 
    return (p_head_node); 
}
/////////////////////////////////////////////////////////////////////////////////////////
void insert_start(struct node* p_head_node, int new_data)
{
    struct node* p_new_node = NULL; 

    p_new_node = get_node(new_data); 
    p_new_node->next = p_head_node->next; 
    p_head_node->next = p_new_node; 
}
/////////////////////////////////////////////////////////////////////////////////////////
void show_list(struct node* p_head_node, char* msg)
{
    struct node* run = NULL; 

    if(msg != NULL)
        puts(msg); 

    printf("[START]->"); 

    run = p_head_node->next; 
    while(run != NULL)
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    }

    puts("[END]"); 
}
////////////////////////////////////////////////////////////////////////////////////////
void destroy_list(struct node* p_head_node)
{
    struct node* run = NULL; 
    struct node* run_next = NULL; 

    run = p_head_node; 
    while(run != NULL)
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    }
}
////////////////////////////////////////////////////////////////////////////////////////
struct node* get_node(int new_data)
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)xmalloc(sizeof(struct node));
    p_new_node->data = new_data; 
    p_new_node->next = NULL; 

    return (p_new_node) ; 
}
/////////////////////////////////////////////////////////////////////////////////////////
void* xmalloc(size_t number_of_bytes)
{
    void* ptr = NULL; 

    ptr = malloc(number_of_bytes); 
    if(ptr == NULL)
    {
        puts("AllocationError:malloc() failed"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}
/////////////////////////////////////////////////////////////////////////////////////////
