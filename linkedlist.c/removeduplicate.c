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
        return;
      }
      struct Node *p=*head;
      if(p->data>=newNode->data){
        newNode->next=p;
        *head=newNode;
      }
      else{
        struct Node *q=NULL;
        while(p!=NULL && p->data<newNode->data){
            q=p;
            p=p->next;
        }
        newNode->next=q->next;
        q->next=newNode;
      }
}
void displayLinkedlist(struct Node *head){
    struct Node *p=head;
    printf("The linked list is : \n");
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL \n");
}
void removeDuplicate(struct Node **head){
    struct Node *p=*head;
    while(p!=NULL && p->next!=NULL){
        struct Node *q=NULL;
        while(p->next!=NULL && p->data==p->next->data){
            q=p->next;
            p->next=p->next->next;
            free(q);
        }
        p=p->next;
    }
}
int main(){
    struct Node *head=NULL;
    printf("1)Insert Node \n2)Display Linkedlist \n3)Remove Duplicate \n4)Exit \n");
    int n;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            int data;
            printf("Enter the data : ");
            scanf("%d",&data);
            insertNode(&head,data);
        }
        else if(n==2){
            displayLinkedlist(head);
        }
        else if(n==3){
            removeDuplicate(&head);
        }
    }while(n!=4);

    return 0;
}