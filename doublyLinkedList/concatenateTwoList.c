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
void concatenateTwoList(struct Node **head1,struct Node **head2){
    struct Node *p1=*head1;
    struct Node *p2=*head2;
    while(p1->right!=NULL){
        p1=p1->right;
    }
    p1->right=p2;
    p2->left=p1;
}
int main(){
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    printf("1)Insert Node \n2)Display doubly Linked list \n3)Exit \n");
    printf("Enter the info for 1st linked list : \n");
    int n;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the data : ");
            int data;
            scanf("%d",&data);
            insertNode(&head1,data);
        }
        else if(n==2){
            printf("The Doubly Linked List is : \n");
            displayDoublyLinkedList(head1);
        }
    }while(n!=3);

    printf("Enter the info for 2nd linked list : \n");
    int n1;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n1);
        if(n1==1){
            printf("Enter the data : ");
            int data;
            scanf("%d",&data);
            insertNode(&head2,data);
        }
        else if(n1==2){
            printf("The Doubly Linked List is : \n");
            displayDoublyLinkedList(head2);
        }
    }while(n1!=3);

    concatenateTwoList(&head1,&head2);
    printf("The linked list after concatenation is : \n");
    displayDoublyLinkedList(head1);

    return 0;
}