///////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
///////////////////////////////////////////////////
int main(void){
    int* p = NULL;  // S1 

    p = (int*)malloc(sizeof(int));  // S2 
    // S3 
    if(p == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    } 

    *p = 100;                   // S4 : Writing  
    printf("*p = %d\n", *p);    // S5: Reading

    free(p);    // S6: release 
    p = NULL;   // S7: Make pointer NULL 

    return (0); 
}
////////////////////////////////////////////////////
