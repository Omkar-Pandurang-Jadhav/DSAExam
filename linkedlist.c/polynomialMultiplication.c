# include<stdio.h>
# include<stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node *next;
};
struct Node *createNode(int coeff,int pow){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->coeff=coeff;
    ptr->pow=pow;
    ptr->next=NULL;

    return ptr;
}

void insertNode(struct Node **head,int coeff,int pow){
    struct Node *newNode=createNode(coeff,pow);
    if(*head==NULL){
        *head=newNode;
        return;
    }

    struct Node *p=*head;
    
    if(p->pow<newNode->pow){
        newNode->next=p;
        *head=newNode;
    }
    else{
      struct Node *q=NULL;
      while(p!=NULL && p->pow>newNode->pow ){
        q=p;
        p=p->next;
      }
      if(p!=NULL && p->pow==newNode->pow){
        p->coeff+=newNode->coeff;
        free(newNode);
        if(p->coeff==0){
            if(q!=NULL){
                q->next=p->next;
            }
            else {
                *head=p->next;
            }
            free(p);
        }
      }
      else {
        newNode->next=q->next;
        q->next=newNode;
      }
    }
}

void displayLinkedList(struct Node *head){
    struct Node *p=head;
    printf("Coefficient,power -> \n");
    while(p!=NULL){
        printf("%d,%d->",p->coeff,p->pow);
        p=p->next;
    }
    printf("Null \n");
}

void polynomialMultiplication(struct Node **head1,struct Node **head2,struct Node **head3){
    struct Node *p1=*head1;
    while(p1!=NULL){
        struct Node *p2=*head2;
        while(p2!=NULL){
            int coeff=p1->coeff*p2->coeff;
            int pow=p1->pow+p2->pow;
            insertNode(head3,coeff,pow);
            p2=p2->next;
        }
        p1=p1->next;
    }
}
  
int main(){
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    struct Node *head3=NULL;
    printf("1)Insert Node \n2)Display \n3)Exit \n");
    printf("Enter info for first linked list : \n");
    int n;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            int coeff,pow;
            printf("Enter coefficient : ");
            scanf("%d",&coeff);
            printf("Enter power : ");
            scanf("%d",&pow);
            insertNode(&head1,coeff,pow);
        }
        else if(n==2){
            displayLinkedList(head1);
        }

    }while(n!=3);

    printf("Enter info for second linked list : \n");
    int n1;
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n1);
        if(n1==1){
            int coeff,pow;
            printf("Enter coefficient : ");
            scanf("%d",&coeff);
            printf("Enter power : ");
            scanf("%d",&pow);
            insertNode(&head2,coeff,pow);
        }
        else if(n1==2){
            displayLinkedList(head2);
        }

    }while(n1!=3);
    
    polynomialMultiplication(&head1,&head2,&head3);

    printf("The linked list 1 is : \n");
    displayLinkedList(head1);
    printf("The linked list 2 is : \n");
    displayLinkedList(head2);
    printf("The polynomial multiplication of equation is : \n");
    displayLinkedList(head3);

    return 0;
}