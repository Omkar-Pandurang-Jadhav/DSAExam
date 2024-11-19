# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# include<string.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}

struct Node *insertionOfANode(int data,struct Node *root){
    if(root==NULL){
        struct Node *newNode=createNode(data);
        return newNode;
    }
    struct Node *p=root;
    if(data<p->data){
        p->left=insertionOfANode(data,p->left);
    }
    else if(data>p->data){
        p->right=insertionOfANode(data,p->right);
    }

    return p;
}

struct Node *rightSubTreeMinValue(struct Node *root){
    struct Node *p=root;
    while(p && p->left!=NULL){
        p=p->left;
    }
    return p;
}
struct Node * deletionOfANode(int data,struct Node *root){
    if(root==NULL){
        printf("The tree is empty deletion cannot happen or data is not present in tree. \n");
        return root;
    }
    struct Node *p=root;
    if(data<p->data){
        p->left=deletionOfANode(data,p->left);
    }
    else if(data>p->data){
        p->right=deletionOfANode(data,p->right);
    }
    else if(data==p->data){
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

        struct Node *temp=rightSubTreeMinValue(p->right);
        p->data=temp->data;
        p->right=deletionOfANode(temp->data,p->right);
    }

    return p;
}
void inorderTraversal(struct Node *root){
    if(root==NULL){
        return ;
    }

    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
void preorderTraversal(struct Node *root){
    if(root==NULL){
        return ;
    }
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node *root){
    if(root==NULL){
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}

void displayTree(struct Node *root){
    printf("Inorder Traversal : \n");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal : \n");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Travversal : \n");
    postorderTraversal(root);
    printf("\n");
}
int main(){
    struct Node *root=NULL;
    int n;
    printf("1)Insertion \n2)Deletion \n3)Display \n4)Exit \n");
    do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            int data;
            printf("Enter the value you want to insert in a tree : ");
            scanf("%d",&data);
            root=insertionOfANode(data,root);
        }
        else if(n==2){
            int data;
            printf("Enter the value you want to delete in a tree : ");
            scanf("%d",&data);
            root=deletionOfANode(data,root);
        }
        else if(n==3){
            displayTree(root);
        }
    }while(n!=4);
    return 0;
}