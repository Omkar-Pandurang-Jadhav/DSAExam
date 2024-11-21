# include<stdio.h>
# include<stdlib.h>

void maxHeap(int *arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i]>arr[(i-1)/2]){
            int j=i;
            while(arr[j]>arr[(j-1)/2]){
                int temp=arr[(j-1)/2];
                arr[(j-1)/2]=arr[j];
                arr[j]=temp;
                j=(j-1)/2;
            }
        }
    }
}
void minHeap(int *arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[(i-1)/2]){
            int j=i;
            while(arr[j]<arr[(j-1)/2]){
                int temp=arr[(j-1)/2];
                arr[(j-1)/2]=arr[j];
                arr[j]=temp;
                j=(j-1)/2;
            }
        }
    }
}
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void ascendingOrderHeap(int *arr,int n){
       maxHeap(arr,n);
       printf("The max heap arr is : \n");
       printArray(arr,n);
       for(int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        int j=0,index;
       do{
        index=2*j+1;
        if(arr[index]<arr[index+1] && index<(i-1)) index++;
        if(arr[index]>arr[j] && index<i){
            int temp=arr[index];
            arr[index]=arr[j];
            arr[j]=temp;
        }
        j=index;
       }while(index<i);
       printf("The %dth step of maxHeapSort. \n",n-i);
       printArray(arr,n);
       }
       
}
void descendingOrderHeap(int *arr,int n){
       minHeap(arr,n);
       printf("The min heap arr is : \n");
       printArray(arr,n);
       for(int i=n-1;i>0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        int j=0,index;
       do{
        index=2*j+1;
        if(arr[index]>arr[index+1] && index<(i-1)) index++;
        if(arr[index]<arr[j] && index<i){
            int temp=arr[index];
            arr[index]=arr[j];
            arr[j]=temp;
        }
        j=index;
       }while(index<i);
       printf("The %d th step of minHeapSort. \n",n-i);
       printArray(arr,n);
       }
       
}
int main(){
    int n;
    printf("Enter the size of an array : ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the element for an array : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("1)Min Heap \n2)Max Heap \n");
    int choice;
    printf("Enter the number based on your choice : ");
    scanf("%d",&choice);
    if(choice==1){
        descendingOrderHeap(arr,n);
        printf("The final array after minHeapSort is : \n");
        printArray(arr,n);
    }
    else if(choice==2){
        ascendingOrderHeap(arr,n);
        printf("The final array after maxHeapSort is : \n");
        printArray(arr,n);
    }
    return 0;
}