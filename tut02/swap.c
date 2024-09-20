// pass by reference
void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}


// pass by value
void swap2(int a, int b) {
    printf("a = %d, b = %d\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a = %d, b = %d\n", a, b);
}
