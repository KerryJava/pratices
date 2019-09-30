#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node * left;
    struct node * right;
}Node;

typedef struct stack {
    int *a;
    int size;
    int cur_size;
}Stack;

void swap(int *a , int *b) {
    int temp = *a;
    *a  = *b;
    *b = temp;
}

typedef Stack * pStack;

void swapHelper(int *a, int i, int j) {
   int temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

void swapHelperV3(int *a, int *b) {
   int temp = *a;
   *b = *a;
   *a = temp;
}

int partition(int *a, int start , int end) {

    int compare = a[end];
    int j = start;
    int smallIdx = start-1;
    int bigIdx = start;
    for (; bigIdx < end; bigIdx++) {
        if (a[bigIdx] < compare) {
            smallIdx ++;
            swapHelperV3(&a[smallIdx], &a[bigIdx]);
    }

    }
    swapHelperV3(&a[smallIdx+1], &a[end]);
    return smallIdx + 1;
}

void quickSortHelper(int *a, int start , int end , int len) {
    if (start >= end) {
        return;
    }

    int privot = partition(a, start, end); 

    quickSortHelper(a, privot + 1, end, len);
    quickSortHelper(a, start, privot-1, len);
    
}

void quickSort(int *a, int len){
    quickSortHelper(a, 0, len-1, len);
}

void init(Stack *stack, int size) {
    stack->size = size; 
    stack->cur_size = 0;
    printf("xxx");
    stack->a = malloc(sizeof(int)* size);
}

void push(Stack *stack , int element) {
    stack->cur_size ++;
    if (stack->cur_size >= stack->size) {
        stack->size = stack->size * 2;
        stack->a = realloc(stack->a, stack->size );
    }
    stack->a[stack->cur_size-1]= element;
}

int pop(Stack *stack) {
    
    int ret = stack->a[stack->cur_size-1];
    stack->cur_size --;
    return ret;
    
}

void sort(int a[], int len) {
    for (int i = 1; i < len;i++) {
       int compare = a[i] ;
       int j = i - 1;
       for (; j > 0 && a[j] > compare;j--) {
               a[j+1] = a[j];
       }
       a[j+1] = compare;
    }
}

Node * createNode(int value){
    Node *n;
    printf("size %lu\n", sizeof(Node));
    // Node * 
    n = (Node*)malloc(sizeof(Node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main() {
    /*
    printf("hello world\n");
    int a[] = {1, 7, 3, 32, 43, 4};
    int len = sizeof(a)/ sizeof(int);
    printf("hello world len %d \n", len);
    sort(a, len) ;
    Stack b;
    Stack *st = &b ;
    init(st, 2);
    printf("init ");


    for (int i = 0; i< len;i++) {
        printf("%d ", a[i]);
        push(st, i);
    }
    printf("\n");
    int c[] = {1, 7, 3, 32, 43, 4};
    quickSort(c, len);
    for (int i = 0; i< len;i++) {
        printf("%d ", a[i]);
        push(st, i);
    }

    printf("init\n ");
    for (int i = 0; i< len;i++) {
        int j = pop(st);
        printf("%d ", j);
    }
*/
    Node * node =  createNode(10);
    node->left =  createNode(5);
    node->right =  createNode(15);

    node->left->left = createNode(1);
    node->left->right = createNode(8);

    node->right->left = createNode(11);
    node->right->right = createNode(18);
    printf("%d\n", node->value);

    return 0;
}
