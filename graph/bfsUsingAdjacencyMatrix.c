# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<ctype.h>
# include<string.h>

struct Queue{
    int front;
    int rear;
    int *traversal;
    int size;
};
bool isFull(struct Queue *q){
    if(q->rear==q->size-1){
        printf("Queue is Full. \n");
        return true;
    }
    return false;
}
bool isEmpty(struct Queue *q){
    if(q->front>q->rear){
        printf("Queue is Empty. \n");
        return true;
    }
    return false;
}
void enqueue(struct Queue *q,int value){
     if(isFull(q)){
        return;
     }
     q->rear++;
     q->traversal[q->rear]=value;
     printf("%d is enqueued in queue. \n",value);
}
int dequeue(struct Queue *q){
    if(isEmpty(q)){
        return -1;
    }
    int value=q->traversal[q->front];
    q->front++;
    printf("%d is dequeued from queue. \n",value);
    return value;
}

void bfsTraversal(int n,int **graph,int start){
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
    q->rear=-1;
    q->front=0;
    q->size=100;
    q->traversal=(int *)malloc(q->size*sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int index=0;
    int *bfs=(int *)malloc(n*sizeof(int));
    enqueue(q,start);
    bfs[index]=start;
    visited[start]=1;
    while(!isEmpty(q)){
        int node=dequeue(q);
        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && visited[i]==0){
                enqueue(q,i);
                visited[i]=1;
                index++;
                bfs[index]=i;
            }
        }
    }
    printf("The bfs traversal is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",bfs[i]);
    }

}
void inputForGraph(int e,int **graph){
    for(int i=0;i<e;i++){
        int n1,n2;
        printf("Enter the edges %d : ",i+1);
        scanf("%d %d",&n1,&n2);
        graph[n1][n2]=1;
        graph[n2][n1]=1;
    }
}
void displayGraph(int n,int **graph){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of nodes in a graph : ");
    scanf("%d",&n);
    
    int **graph=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        graph[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    int e;
    printf("Enter the number of edges and it should be less than %d : ",n*n);
    scanf("%d",&e);
    printf("Enter the edge for an graph : \n");
    inputForGraph(e,graph);
    printf("The graph is : \n");
    displayGraph(n,graph);
    int start;
    printf("Enter the starting point for graph traversal : ");
    scanf("%d",&start);
    bfsTraversal(n,graph,start);
    
    return 0;
}
