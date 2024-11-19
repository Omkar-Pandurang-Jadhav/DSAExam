# include<stdio.h>
# include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *reverseLinkedList(struct Node *head){
    if(head==NULL || head->next==NULL){
       return head;
    }
    struct Node *newHead=reverseLinkedList(head->next);
    struct Node *front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

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

struct Node *additionOfLinkedList(struct Node **head1,struct Node **head2,struct Node **head3){
    struct Node *p1=*head1;
    struct Node *p2=*head2;
    int carry=0;
    int num;
    while(p1!=NULL && p2!=NULL){
        int sum=p1->data+p2->data;
        num=sum+carry;
        insertNode(head3,num%10);
        carry=num/10;
        p1=p1->next;
        p2=p2->next;
    }
    
    while(p1!=NULL){
        int num=p1->data+carry;
        insertNode(head3,num%10);
        carry=num/10;
        p1=p1->next;
    }
    while(p2!=NULL){
        int num=p2->data+carry;
        insertNode(head3,num%10);
        carry=num/10;
        p2=p2->next;
    }
    insertNode(head3,carry);

    return *head3;
}
int main(){
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    printf("1)Insert Node\n2)Display Linkedlist \n3)Exit \n");
    printf("Enter info for 1st Linked List : \n");
    int n;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            int data;
            printf("Enter the data for Node : ");
            scanf("%d",&data);
            insertNode(&head1,data);
        }
        else if(n==2){
            printf("The linked list is : \n");
            displayLinkedList(head1);
        }
        }while(n!=3);

    printf("Enter info for 2nd Linked List : \n");
    int n1;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n1);
        if(n1==1){
            int data;
            printf("Enter the data for Node : ");
            scanf("%d",&data);
            insertNode(&head2,data);
        }
        else if(n1==2){
            printf("The linked list is : \n");
            displayLinkedList(head2);
        }
    }while(n1!=3);

    head1=reverseLinkedList(head1);
    head2=reverseLinkedList(head2);
    struct Node *head3=NULL;
    head3=additionOfLinkedList(&head1,&head2,&head3);
    head1=reverseLinkedList(head1);
    head2=reverseLinkedList(head2);
    head3=reverseLinkedList(head3);

    printf("The Linked List 1 is : \n");
    displayLinkedList(head1);
    printf("The Linked List 2 is : \n");
    displayLinkedList(head2);
    printf("The addition of Linked List 1 and 2 is : \n");
    displayLinkedList(head3);

    return 0;
}