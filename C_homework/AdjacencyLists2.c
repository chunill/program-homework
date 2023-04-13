#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef short int Bool;
typedef struct Node* nodePointer;
typedef struct Node{
    int vertex;
    nodePointer link;
}Node;
typedef struct Queue* queuePointer;
typedef struct Queue{
    int value;
    queuePointer link;
}Queue;

nodePointer graph[MAX_VERTICES];
Bool visited[MAX_VERTICES];
queuePointer front = NULL, rear = NULL;

void addq(int value);
int deleteq();
void linkStart(int A, int B);
nodePointer newNode(int vertex);
void createEdge(int vertexA, int vertexB);
void DFS(int vertex);
void BFS(int vertex);
void printGraph(int graphSize){
    nodePointer node;
    for (int i=0;i<graphSize;i++){
        printf("[%d] ", i);
        node = graph[i];
        while(node){
            printf("-> %d ", node->vertex);
            node = node->link;
        }
        printf("\n");
    }
}
void printQueue(){
    if(front){
        queuePointer temp = front;
        while(temp){
            printf("%d ", temp->value);
            temp = temp->link;
        }
    }
    else{printf("NULL");}
    printf("\n");
}

int main(void){
    int graphSize;
    int vertexA, vertexB, FSearch;
    printf("[Enter the number of vertices] > ");
    scanf("%d", &graphSize);
    printf("[Enter the vertex A and B to represent connected edges (Enter -1 to END)] > \n");
    while(scanf("%d", &vertexA)){
        if(vertexA == -1){break;}
        scanf("%d", &vertexB);
        if((vertexA >= 0 and vertexA < graphSize)
           and (vertexB >= 0 and vertexB < graphSize)){
            createEdge(vertexA, vertexB);
        }
        else{printf("error: vertex value exceeds number of vertex\n");}
    }
    printf("Adjacency lists: \n\n");
    printGraph(graphSize);
    printf("\n");
    while(TRUE){
        printf("[Enter the first vertex to search (-1 to END)] > ");
        scanf("%d", &FSearch);
        printf("\n");
        if(FSearch == -1){break;}
        else if(FSearch >= 0 and FSearch < graphSize){
            printf("Depth First Search: \n");
            DFS(FSearch);
            printf("\n");
            for(int i=0;i<graphSize;i++){visited[i] = FALSE;}
            printf("Breadth First Search: \n");
            BFS(FSearch);
            printf("\n");
            for(int i=0;i<graphSize;i++){visited[i] = FALSE;}
        }
        else{printf("error: error: vertex value exceeds number of vertex\n");}
    }
    printf("END");
    return 0;
}

void addq(int value){
    queuePointer newValue = (queuePointer)malloc(sizeof(Queue));
    newValue->value = value;
    newValue->link = NULL;
    rear = newValue;

    if(front){
        queuePointer temp = front;
        while(temp->link){temp = temp->link;}
        temp->link = newValue;
    }
    else{front = newValue;}
}

int deleteq(){
    if(front){
        queuePointer temp = front;
        int deleteValue = temp->value;
        front = front->link;
        if(!front){rear = NULL;}
        free(temp);
        return deleteValue;
    }
    else{return -1;}
}

void linkStart(int vertexA, int vertexB){
    nodePointer node = graph[vertexA];
    if(graph[vertexA]){
        while(node->link){node = node->link;}
        node->link = newNode(vertexB);
    }
    else{graph[vertexA] = newNode(vertexB);}
}

nodePointer newNode(int vertex){
    nodePointer node = (nodePointer)malloc(sizeof(Node));
    node->vertex = vertex;
    node->link = NULL;
    return node;
}

void createEdge(int vertexA, int vertexB){
    linkStart(vertexA, vertexB);
    linkStart(vertexB, vertexA);
}

void DFS(int vertex){
    nodePointer visit = graph[vertex];
    visited[vertex] = TRUE;
    printf("v%d ", vertex);
    while(visit){
        if(!visited[visit->vertex]){DFS(visit->vertex);}
        visit = visit->link;
    }
}

void BFS(int vertex){
    nodePointer temp;
    addq(vertex);
    visited[vertex] = TRUE;
    while(front){
        temp = graph[front->value];
        while(temp){
            if(!visited[temp->vertex]){
                addq(temp->vertex);
                visited[temp->vertex] = TRUE;
            }
           temp = temp->link;
        }
        printf("v%d ", deleteq());
    }
    printf("\n");
}