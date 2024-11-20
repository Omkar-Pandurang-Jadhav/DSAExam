# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<ctype.h>
# include<string.h>

static int time=1;
static int index=0;
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

void dfsTraversal(int n,int *inTime,int *outTime,int *dfs,int start,struct Node *arr[],int *visited){
    dfs[index]=start;
    index++;
    inTime[start]=time;
    time++;
    visited[start]=1;
    struct Node *temp=arr[start];
    while(temp!=NULL){
        if(visited[temp->data]==0){
            dfsTraversal(n,inTime,outTime,dfs,temp->data,arr,visited);
        }
        temp=temp->next;
    }
    outTime[start]=time;
    time++;
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
    int *inTime=(int *)malloc(sizeof(int));
    int *outTime=(int *)malloc(sizeof(int));
    int *dfs=(int *)malloc(n*sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    dfsTraversal(n,inTime,outTime,dfs,start,arr,visited);
    printf("The dfs Traversal is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",dfs[i]);
    }
    printf("\n");
    printf("The start and end time for an element : \n");
        printf("     Start Time   End Time \n");
    for(int i=0;i<n;i++){
        printf(" %d     %d            %d  \n",i,inTime[i],outTime[i]);
    }

    return 0;
}
