#ifndef ADD_CUSTOM_FUNCTIONS
#define ADD_CUSTOM_FUNCTIONS

int add(int a, int b, int device = 0);

void add_CPU(int a, int b, int* c);
void add_GPU(int a, int b, int* c);

#endif 
