# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<ctype.h>
# include<string.h>

static int time=1;
static int index=0;

void dfsTraversal(int n,int **graph,int start,int *inTime,int *outTime,int *visited,int *dfs){
    visited[start]=1;
    inTime[start]=time;
    time++;
    dfs[index]=start;
    index++;
    for(int i=0;i<n;i++){
        if(graph[start][i]==1 && visited[i]==0){
            dfsTraversal(n,graph,i,inTime,outTime,visited,dfs);
        }
    }
    outTime[start]=time;
    time++;
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
    int *inTime=(int *)malloc(n*sizeof(int));
    int *outTime=(int *)malloc(n*sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int *dfs=(int *)malloc(n*sizeof(int));
    dfsTraversal(n,graph,start,inTime,outTime,visited,dfs);
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
