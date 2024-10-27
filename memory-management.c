#include<stdio.h>
#include<stdlib.h>

int glo1 = 10;
int glo2 = 20;
int glo3 = 30;

void third_func() {
    int local3 = 300;
    printf("Address of local3 variable is %p\n", (void*)&local3);
}

void second_func() {
    int local2 = 200;
    printf("Address of local2 variable is %p\n", (void*)&local2);
    third_func();
}

void first_func() {
    int local1 = 100;
    //address of variables in stack
    printf("Stack-grow down:\n");
    printf("Address of local1 variable is %p\n", (void*)&local1);
    second_func();

    int *array1 = (int*)malloc(sizeof(int));
    int *array2 = (int*)malloc(sizeof(int));
    int *array3 = (int*)malloc(sizeof(int));

    //address of variables in heap
    printf("Heap-grow up:\n");
    printf("Address of array1(malloc) is %p\n", (void*)array1);
    printf("Address of array2(malloc) is %p\n", (void*)array2);
    printf("Address of array3(malloc) is %p\n", (void*)array3);

    free(array1);
    free(array2);
    free(array3);
}

int main() {
    //address of Global variables
    printf("Address of glo1 is %p\n", (void*)&glo1);
    printf("Address of glo2 is %p\n", (void*)&glo2);
    printf("Address of glo3 is %p\n", (void*)&glo3);
    first_func();
    return 0;
}