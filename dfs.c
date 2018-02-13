#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


typedef struct node {
    int color;
    int value;
    struct node *parent;
    int distance;
    int i;
    int j;
    struct node **adj;
}Node;

typedef struct graph {
    Node *head;
    int n;
    int m;
}Graph;

typedef struct stack {
	Node **data;
	int size;
	int capacity;
	int largestSize;
}Stack;

Stack g_stack;

void initStack(Stack *stack, int capacity) {
	stack->data = malloc(sizeof(Node*)*capacity);
	stack->capacity = capacity;
	stack->size = 0;
	stack->largestSize = 0;
}

void pushStackHelper(Stack *stack, Node *node) {
	stack->data[stack->size] = node;
	stack->size++;
}

void pushStack(Node *node) {
	pushStackHelper(&g_stack, node);
}

void updateStack() {

	if (g_stack.size > g_stack.largestSize){
		g_stack.largestSize = g_stack.size;
	}
    
    //printf("largest size is %d\n", g_stack.largestSize);
}

void clearStack() {
	g_stack.size = 0;
}

void postProcStack() {
	updateStack();
	clearStack();
}

void printStackLargest() {
    printf("%d\n", g_stack.largestSize);
}

void DFS_VISIT(Graph *graph, Node *node) {
    
    node->color = 1;
    
    for(int j = node->j - 1 ; j <= node->j+1 && j < graph->n; j++) {
        for (int i = node->i - 1; i<= node->i+1 && i < graph->m; i++) {
            
            if (j < 0 || i < 0) {
                continue;
            }
            
            Node *p = &(graph->head[j * graph->m + i]);
            
            if (p->color == 0 && p->value == 1) {
                p->parent = node;
		        pushStack(p);
                DFS_VISIT(graph, p);
            }
        }
    }
    
    //printf("%d index [%d][ %d]\n ", node->value, node->j, node->i);
    node->color = 2;
}

void DFS(int *grid, int n, int m) {
    
    Graph *graph = malloc(sizeof(Graph));
    graph->head = malloc(sizeof(Node)*(n*m));
    initStack(&g_stack, n*m);

    graph->n = n;
    graph->m = m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Node *p = &(graph->head[i*m + j]);
	       //printf("value is %d index [%d][%d]\n ", *(grid+i*m+j), i, j);
            p->value = *(grid + i*m + j);
            p->color = 0;
            p->parent = NULL;
            p->distance = 0;
            p->i = j;
            p->j = i;            
        }
    }
    

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Node *p = &(graph->head[i*m+ j]);
            if (p->color == 0 && p->value == 1) {
		          pushStack(p);
                    DFS_VISIT(graph, p);
		          postProcStack();
            }
	    
	    if (p->value == 1){
		    //printf("value is %d index [%d][%d]\n", p->value ,i, j );
	    }
        }
    }
    
    printStackLargest();
}


int main(){
    int n; 
    scanf("%d",&n);
    int m; 
    scanf("%d",&m);
    int grid[n][m];
    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){
          
          scanf("%d",&grid[grid_i][grid_j]);
       }
    }
    
    DFS(*grid, n, m);
    
    return 0;
}

