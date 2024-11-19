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
int isPalindrome(struct Node *head){
    if(head==NULL || head->next==NULL){
        return 1;
    }
    struct Node *slow=head;
    struct Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct Node *newHead=reverseLinkedList(slow->next);
    struct Node *p1=newHead;
    struct Node *p2=head;
    while(p1!=NULL){
        if(p1->data!=p2->data){
            reverseLinkedList(newHead);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }
    reverseLinkedList(newHead);
    return 1;
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
int main(){
    struct Node *head=NULL;
    printf("1)Insert Node\n2)Display Linkedlist \n3)Check if Palindrome or not \n4)Exit \n");
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
            if(isPalindrome(head)){
                printf("The linked list is palindrome. \n");
            }
            else {
                printf("The linked list is not a palindrome. \n");               
            }
        }
    }while(n!=4);
    
    
    
    return 0;
}