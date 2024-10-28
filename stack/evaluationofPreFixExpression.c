# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<ctype.h>

struct stack{
    int stacksize;
    int top;
    int *item;
};
int isFull(struct stack *st){
    return st->top==st->stacksize-1;
}
int isEmpty(struct stack *st){
    return st->top==-1;
}
void push(struct stack *st,int c){
    if(isFull(st)){
        printf("Stack Overflow. \n");
        return;
    }
    printf("Push : %d \n",c);
    st->top++;
    st->item[st->top]=c;
}
int pop(struct stack *st){
    if(isEmpty(st)){
        printf("Stack Underflow. \n");
        return -1;
    }
    int c=st->item[st->top];
    printf("Pop : %d \n",c);
    st->top--;
    return c;
}
int isOperator(char c){
    return (c=='^' || c=='%' || c=='+' || c=='-' || c=='*' || c=='/' || c=='~');
}
int evaluationOfPostFixExpression(char postFix[],int n){ 
    struct stack *st=(struct stack *)malloc(sizeof(struct stack));
    st->stacksize=100;
    st->top=-1;
    st->item=(int *)malloc(st->stacksize*sizeof(int));
    for(int i=n-1;i>=0;i--){
        char c=postFix[i];
        int result;
        if(isalnum(c)){
            int num=c-'0';
            push(st,num);
        }
        else if(isOperator(c)){
          
            int left=pop(st);
            int right=pop(st);
            
            switch(c) {
                case '*':
                result=left*right;
                break;
                case '%':
                result=left%right;
                break;
                case '/':
                result=left/right;
                break;
                case '+':
                result=left+right;
                break;
                case '-':
                result=left-right;
                break;
                case '~':
                push(st,right);
                result=-left;
                break;
                case '^':
                result=1;
                for(int i=1;i<=right;i++){
                    result=result*left;
                }
                break;
                default :
                printf("Invalid Operator. \n");
                break;
            }
            push(st,result);
        }
    }
    int ans=pop(st);
    return ans;
}
int main(){
    char postFix[100];
    printf("Enter the preFix Expression : ");
    fgets(postFix,100,stdin);
    int length=strlen(postFix);
    if(postFix[length-1]=='\n'){
        postFix[length-1]='\0';
        length--;
    }

    int result=evaluationOfPostFixExpression(postFix,length);
    printf("The final result is : %d .",result);
    return 0;
}