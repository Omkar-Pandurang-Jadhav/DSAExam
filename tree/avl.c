# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# include<string.h>

struct Node{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int key){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->key=key;
    ptr->height=0;

    return ptr;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
int height(struct Node *node){
    if(node==NULL){
        return -1;
    }

    return node->height;
}

int balanceFactor(struct Node *node){
    return height(node->left)-height(node->right);
}

struct Node *leftLeftRotation(struct Node *node){
    struct Node *n1=(struct Node *)malloc(sizeof(struct Node));
    n1=node->left;
    node->left=n1->right;
    n1->right=node;
    node->height=1+max(height(node->left),height(node->right));
    n1->height=1+max(height(n1->left),height(n1->right));
    printf("LL rotation on %d is applied. \n",node->key);

    return n1;
}
struct Node *rightRightRotation(struct Node *node){
    struct Node *n1=(struct Node *)malloc(sizeof(struct Node));
    n1=node->right;
    node->right=n1->left;
    n1->left=node;
    node->height=1+max(height(node->left),height(node->right));
    n1->height=1+max(height(n1->left),height(n1->right));
    printf("RR rotation on %d is applied. \n",node->key);
    return n1;
}

struct Node *leftRightRotation(struct Node *node){
    int n=node->key;
    node->left=rightRightRotation(node->left);
    node=leftLeftRotation(node);
    printf("LR rotaion on %d is completed . \n",n);

    return node;
}

struct Node *rightLeftRotation(struct Node *node){
    int n=node->key;
    node->right=leftLeftRotation(node->right);
    node=rightRightRotation(node);
    printf("RL rotation on %d is completed. \n",n);

    return node;
}

struct Node *minValue(struct Node *root){
    struct Node *current=root;
    while(current && current->left !=NULL){
        current=current->left;
    }

    return current;
}
struct Node *insertNode(struct Node *root,int key){
    if(root==NULL){
        return createNode(key);
    }
    struct Node *p=root;
    if(key<p->key){
        p->left=insertNode(p->left,key);
    }
    else if(key>p->key){
        p->right=insertNode(p->right,key);
    }
    p->height=1+max(height(p->left),height(p->right));
    int balance=balanceFactor(p);
    printf("Balance Factor of node %d is %d. \n",p->key,balance);

    if(balance>1 && key<p->left->key){
        p=leftLeftRotation(p);
    }
    else if(balance>1 && key>p->left->key){
        p=leftRightRotation(p);
    }
    else if(balance<-1 && key>p->right->key){
        p=rightRightRotation(p);
    }
    else if(balance<-1 && key<p->right->key){
        p=rightLeftRotation(p);
    }

    return p;
}
struct Node * deleteNode(struct Node *root,int key){
    if(root==NULL){
        printf("The node %d is not present in tree. \n",key);
        return root;
    }
    struct Node *p=root;
    if(key<p->key){
        p->left=insertNode(p->left,key);
    }
    else if(key>p->key){
        p->right=insertNode(p->right,key);
    }
    else if(key==p->key){
        if(p->left==NULL){
            struct Node *temp=p;
            p=p->right;
            free(temp);
            return p;
        }
        else if(p->right==NULL){
            struct Node *temp=p;
            p=p->left;
            free(temp);
            return p;
        }
        struct Node *temp=minValue(p->right);
        p->key=temp->key;
        p->right=deleteNode(p->right,temp->key);
    }
    p->height=1+max(height(p->left),height(p->right));
    int balance=balanceFactor(p);
    printf("Balance Factor of node %d is %d. \n",p->key,balance);

    if(balance>1 && key<p->left->key){
        p=leftLeftRotation(p);
    }
    else if(balance>1 && key>p->left->key){
        p=leftRightRotation(p);
    }
    else if(balance<-1 && key>p->right->key){
        p=rightRightRotation(p);
    }
    else if(balance<-1 && key<p->right->key){
        p=rightLeftRotation(p);
    }

    return p;
}
void inorderTraversal(struct Node *root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->key);
    inorderTraversal(root->right);
}
void preorderTraversal(struct Node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->key);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct Node *root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->key);
}

void displayTree(struct Node *root){
    printf("Inorder Traversal : \n");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal : \n");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Traversal : \n");
    postorderTraversal(root);
    printf("\n");
}
int main(){
    struct Node *root=NULL;
    int n;
    printf("1)Insert \n2)Delete \n3)Display \n4)Exit \n");
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the number you want to insert : ");
            int key;
            scanf("%d",&key);
            root=insertNode(root,key);
        }
        else if(n==2){
            printf("Enter the number you want to delete : ");
            int key;
            scanf("%d",&key);
            root=deleteNode(root,key);
        }
        else if(n==3){
            displayTree(root);
        }
    }while(n!=4);

    return 0;
}