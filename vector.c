///////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h> 
#include <stdlib.h> 
///////////////////////////////////////////////////////////////////////////////////////
struct vector
{
    int* a_ptr; 
    int a_length; 
}; 
///////////////////////////////////////////////////////////////////////////////////////
/*
int main(void)
{
    struct vector* p_vec = NULL; 

    p_vec = allocate_vector(); 

    if(p_vec->a_ptr == NULL)
    {
        p_vec->a_ptr = (int*)malloc(sizeof(int)); 
        if(p_vec->a_ptr == NULL)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }

        p_vec->a_ptr[0] = 10; 
        p_vec->a_length += 1; 
    }
    else 
    {
        int new_required_size_in_bytes = (p_vec->a_length + 1) * sizeof(int); 
        p_vec->a_ptr = (int*)realloc(p_vec->a_ptr, new_required_size_in_bytes); 
        if(p_vec->a_ptr == NULL)
        {
            puts("Error in resizing array"); 
            exit(EXIT_FAILURE); 
        }

        p_vec->a_length = p_vec->a_length + 1; 
        p_vec->a_ptr[p_vec->a_length - 1] = 20; 
    }

}
*/
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    struct vector* p_vec = NULL; 
    int new_required_size_in_bytes; 

    p_vec = allocate_vector(); 

    // insert 10 in vector 
    new_required_size_in_bytes = (p_vec->a_length + 1) * sizeof(int); 
    p_vec->a_ptr = (int*)realloc(p_vec->a_ptr, new_required_size_in_bytes); 
    // error check 
    p_vec->a_length = p_vec->a_length + 1; 
    p_vec->a_ptr[p_vec->a_length - 1] = 10; 

    // insert 20 in vector 
    new_required_size_in_bytes = (p_vec->a_length + 1) * sizeof(int); 
    p_vec->a_ptr = (int*)realloc(p_vec->a_ptr, new_required_size_in_bytes); 
    // error check 
    p_vec->a_length = p_vec->a_length + 1; 
    p_vec->a_ptr[p_vec->a_length - 1] = 20; 

}
/////////////////////////////////////////////////////////////////////////////////////
struct vector* allocate_vector(void)
{
    struct vector* p_vec = NULL; 

    p_vec = (struct vector*)malloc(sizeof(struct vector)); 
    if(p_vec == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    p_vec->a_ptr = NULL; 
    p_vec->a_length = 0; 

    return (p_vec); 
}
///////////////////////////////////////////////////////////////////////////////////////
void push_back(struct vector* p_vec, int new_data)
{
    int new_required_size_in_bytes; 

    new_required_size_in_bytes = (p_vec->a_length + 1) * sizeof(int); 
    p_vec->a_ptr = (int*)realloc(p_vec->a_ptr, new_required_size_in_bytes); 
    if(p_vec->a_ptr == NULL)
    {
        puts("Error in resizing array. exiting..."); 
        exit(EXIT_FAILURE); 
    }

    p_vec->a_length = p_vec->a_length + 1; 
    p_vec->a_ptr[p_vec->a_length - 1] = new_data; 
}
//////////////////////////////////////////////////////////////////////////////////////
