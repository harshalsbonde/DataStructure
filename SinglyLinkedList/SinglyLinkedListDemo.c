/////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////////////////////////
#define SUCCESS             1 
#define TRUE                1 
#define FALSE               0 
#define LIST_INVALID_DATA   2 
#define LIST_EMPTY          3 
/////////////////////////////////////////////////////////////////////////////////////////
struct node{
    int data; 
    struct node* next;
}; 
/////////////////////////////////////////////////////////////////////////////////////////
struct node* create_list(void); 

void insert_start(struct node* p_head_node, int new_data); 
void insert_end(struct node* p_head_node, int new_data); 
int insert_after(struct node* p_head_node, int e_data, int new_data); 
int insert_before(struct node* p_head_node, int e_data, int new_data);
///
int get_start(struct node* p_head_node, int* p_start_data); 
int get_end(struct node* p_head_node, int* p_end_start); 
int pop_start(struct node* p_head_node, int* p_start_data); 
int pop_end(struct node* p_head_node, int* p_end_data); 
int remove_start(struct node* p_head_node); 
int remove_end(struct node* p_head_node); 
int remove_data(struct node* p_head_node, int r_data); ; 

int get_length(struct node* p_head_node); 
int is_list_empty(struct node* p_head_node); 
///
void show_list(struct node* p_head_node, char* msg); 
void destroy_list(struct node* p_head_node); 

struct node* search_node(struct node* p_head_node, int search_data); 
void get_node_and_its_pred(struct node* p_head_node, int search_data,  struct node** pp_node, 
                            struct node** pp_pred_node); 
struct node* get_node(int data); 
void* xmalloc(size_t number_of_bytes); 
/////////////////////////////////////////////////////////////////////////////////////////
int main(void){
    struct node* p_list = NULL; 

    p_list = create_list();     
    show_list(p_list, "p_list:");     // head_node 
    insert_end(p_list, 10);    
    show_list(p_list, "p_list:");      // head_node -> 10 
    insert_end(p_list, 20);    
    show_list(p_list, "p_list:");      // head_node -> 10 -> 20 
    insert_end(p_list, 30);    
    show_list(p_list, "p_list:");      // head_node -> 10 -> 20 -> 30 
    insert_end(p_list, 40);     
    show_list(p_list, "p_list:");        // head_node -> 10 -> 20 -> 30 -> 40 
    insert_after(p_list, 20, 100); 
    show_list(p_list, "p_list:");        // head_node -> 10 -> 20 -> 100 -> 30 -> 40 
    insert_before(p_list, 20, 200);
    show_list(p_list, "p_list:");        // head_node -> 10 -> 200 -> 20 -> 100 -> 30 -> 40 

    destroy_list(p_list); 
    p_list = NULL; 

    return (EXIT_SUCCESS); 
}
/////////////////////////////////////////////////////////////////////////////////////////
struct node* create_list(void){
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
void insert_end(struct node* p_head_node, int new_data)
{
    struct node* last_node = NULL; 

    last_node = p_head_node; 
    while(last_node->next != NULL)
        last_node = last_node->next; 
    last_node->next = get_node(new_data); 
}
/////////////////////////////////////////////////////////////////////////////////////////
int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* e_node = NULL;
    struct node* new_node = NULL; 

    e_node = search_node(p_head_node, e_data); 
    if(e_node == NULL)
        return (LIST_INVALID_DATA); 

    new_node = get_node(new_data); 
    new_node->next = e_node->next; 
    e_node->next = new_node; 

    return (SUCCESS); 
}
/////////////////////////////////////////////////////////////////////////////////////////
int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    struct node* e_node = NULL; 
    struct node* e_node_pred = NULL; 
    struct node* new_node = NULL; 

    get_node_and_its_pred(p_head_node, e_data, &e_node, &e_node_pred); 
    if(e_node == NULL)
        return (LIST_INVALID_DATA); 

    new_node = get_node(new_data); 
    new_node->next = e_node;
    e_node_pred->next = new_node; 
     
    return (SUCCESS); 
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
/////////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////////
struct node* search_node(struct node* p_head_node, int search_data)
{
    struct node* run = NULL; 

    run = p_head_node->next; 
    while(run != NULL)
    {
        if(run->data == search_data)
            break; 
        run = run->next; 
    }

    return (run); 
}
/////////////////////////////////////////////////////////////////////////////////////////
void get_node_and_its_pred(
    struct node* p_head_node,
    int search_data, 
    struct node** pp_node, 
    struct node** pp_pred_node
)
{
    struct node* run = NULL; 
    struct node* run_pred = NULL; 

    run_pred = p_head_node; 
    run = p_head_node->next; 

    while(run != NULL)
    {
        if(run->data == search_data)
        {
            *pp_node = run; 
            *pp_pred_node = run_pred; 
            return; 
        }

        run_pred = run; 
        run = run->next; 
    }

    *pp_node = NULL; 
}
/////////////////////////////////////////////////////////////////////////////////////////
struct node* get_node(int data)
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)xmalloc(sizeof(struct node)); 
    p_new_node->data = data; 
    p_new_node->next = NULL; 

    return (p_new_node); 
}
/////////////////////////////////////////////////////////////////////////////////////////
void* xmalloc(size_t number_of_bytes)
{
    void* ptr = NULL; 

    ptr = malloc(number_of_bytes); 
    if(ptr == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }
    return (ptr); 
}
/////////////////////////////////////////////////////////////////////////////////////////
