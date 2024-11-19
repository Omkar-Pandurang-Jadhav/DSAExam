# include<stdio.h>
# include<stdlib.h>

struct Node{
    int data;
    struct Node *right;
    struct Node *left;
};
struct Node *createNode(int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}
void insertNode(struct Node **head,int data){
    struct Node *newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return ;
    }
    struct Node *p=*head;
    while(p->right!=NULL){
        p=p->right;
    }
    p->right=newNode;
    newNode->left=p;
}
void displayDoublyLinkedList(struct Node *head){
    struct Node *p=head;
    printf("NULL<-");
    while(p->right!=NULL){
        printf("%d<->",p->data);
        p=p->right;
    }
    printf("%d->NULL \n",p->data);
}
void reverseDoublyLinkedList(struct Node **head){
    struct Node *p=*head;
    struct Node *q=NULL;
    while(p->right!=NULL){
        q=p->left;
        p->left=p->right;
        p->right=q;
        p=p->left;
        *head=p;
    }
    q=p->left;
    p->left=p->right;
    p->right=q;
}
int main(){
    struct Node *head=NULL;
    printf("1)Insert Node \n2)Display doubly Linked list \n3)Reverse the doubly linked list \n4)Exit \n");
    int n;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the data : ");
            int data;
            scanf("%d",&data);
            insertNode(&head,data);
        }
        else if(n==2){
            printf("The Doubly Linked List is : \n");
            displayDoublyLinkedList(head);
        }
        else if(n==3){
            reverseDoublyLinkedList(&head);
            printf("The Doubly Linked List after reversal is : \n");
            displayDoublyLinkedList(head);
        }
    }while(n!=4);

    return 0;
}