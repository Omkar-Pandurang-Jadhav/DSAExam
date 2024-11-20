# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<ctype.h>
# include<string.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *createNode(int n){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=n;
    ptr->next=NULL;

    return ptr;
}
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

void bfsTraversal(int n,struct Node *arr[],int start){
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
        struct Node *temp=arr[node];
        while(temp!=NULL){
            if(visited[temp->data]==0){
            index++;
            bfs[index]=temp->data;
            enqueue(q,temp->data);
            visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
    printf("The bfs traversal is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",bfs[i]);
    }

}
void addEdge(struct Node *arr[],int n1,int n2){
    struct Node *newNode1=createNode(n1);
    struct Node *newNode2=createNode(n2);

    if(arr[n1]==NULL || arr[n1]->data>n2){
        newNode2->next=arr[n1];
        arr[n1]=newNode2;
    }
    else{
        struct Node *temp=arr[n1];
        while(temp->next!=NULL && temp->next->data<n2){
            temp=temp->next;
        }
        newNode2->next=temp->next;
        temp->next=newNode2;
    }

    if(arr[n2]==NULL || arr[n2]->data>n1){
        newNode1->next=arr[n2];
        arr[n2]=newNode1;
    }
    else{
        struct Node *temp=arr[n2];
        while(temp->next!=NULL && temp->next->data<n1){
            temp=temp->next;
        }
        newNode1->next=temp->next;
        temp->next=newNode1;
    }
}
void disPlayGraph(struct Node *arr[],int n){
    printf("The graph is : \n");
    for(int i=0;i<n;i++){
        printf("%d : ",i);
        struct Node *temp=arr[i];
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("Null \n");
    }
}
void inputForGraph(int e,struct Node *arr[]){
    for(int i=0;i<e;i++){
        int n1,n2;
        printf("Enter the edges %d : ",i+1);
        scanf("%d %d",&n1,&n2);
        addEdge(arr,n1,n2);
    }
}
void displayGraph(int n,struct Node *arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
     
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of nodes in a graph : ");
    scanf("%d",&n);
    int e;
    printf("Enter the number of edges and it should be less than %d : ",n*n);
    scanf("%d",&e);
    struct Node *arr[n];
    for(int i=0;i<n;i++){
        arr[i]=NULL;
    }
    printf("Enter the edge for an graph : \n");
    inputForGraph(e,arr);
    disPlayGraph(arr,n);
    int start;
    printf("Enter the starting Point for graph traversal : ");
    scanf("%d",&start);
    bfsTraversal(n,arr,start);
    
    return 0;
}
