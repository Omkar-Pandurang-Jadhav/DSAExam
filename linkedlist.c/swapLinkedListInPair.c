# include<stdio.h>
# include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node *createNode(int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;

    return ptr;
}

void insertNode(struct Node **head,int data){
    struct Node *newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return ;
    }
    struct Node *p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
}
void displayLinkedList(struct Node *head){
    struct Node *p=head;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL \n");
}

void swapPair(struct Node **head){
    struct Node *p=*head;
    struct Node *q=NULL;
    struct Node *r=NULL;
    int i=0;
    while(p!=NULL && p->next!=NULL){
        i++;
        q=p->next;
        p->next=q->next;
        q->next=p;
        if(i==1){
            *head=q;
            r=p;
        }
        else{
            r->next=q;
            r=p;
        }
        p=p->next;
    }
}
int main(){
    struct Node *head=NULL;
    printf("1)Insert Node\n2)Display Linkedlist \n3)Swap Pair \n4)Exit \n");
    printf("Enter info for Linked List : \n");
    int n;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            int data;
            printf("Enter the data for Node : ");
            scanf("%d",&data);
            insertNode(&head,data);
        }
        else if(n==2){
            printf("The linked list is : \n");
            displayLinkedList(head);
        }
        else if(n==3){
            swapPair(&head);
            printf("The linked list after swapping is : \n");
            displayLinkedList(head);
        }
        }while(n!=4);
    return 0;
}