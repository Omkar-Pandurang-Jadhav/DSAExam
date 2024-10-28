# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<ctype.h>

struct stack{
    int stacksize;
    int top;
    char *item;
};

int isEmpty(struct stack *st){
    return st->top==-1;
}
char top(struct stack *st){
    if(isEmpty(st)){
        printf("Stack is Empty. \n");
        return -1;
    }
    return st->item[st->top];
}
int isFull(struct stack *st){
    return st->top==st->stacksize-1;
}
void push(struct stack *st,char value){
    if(isFull(st)){
        printf("Stack Overflow. \n");
        return ;
    }
    printf("Push : %c \n",value);
    st->top++;
    st->item[st->top]=value;
}
char pop(struct stack *st){
    if(isEmpty(st)){
        printf("Stack Underflow. \n");
        return -1;
    }
    printf("Pop : %c \n",top(st));
    char c=top(st);
    st->top--;
    return c;
}
int precedence(char c){
    if(c=='^') return 3;
    else if(c=='%' || c=='/' || c=='*') return 2;
    else if(c=='+' || c=='-') return 1;

    return -1;
}
int isOperator(char c){
    if(c=='^' || c=='%' || c=='/' || c=='*' || c=='+' || c=='-'){
        return 1;
    }
    return 0;
}
void reverseString(char infix[],int n){
    for(int i=0;i<n/2;i++){
        char temp=infix[i];
        infix[i]=infix[n-i-1];
        infix[n-i-1]=temp;
    }
}
char *convertInfixToPostfix(char infix[],char *postFix,int n){
    struct stack *st=(struct stack *)malloc(sizeof(struct stack));
    st->stacksize=100;
    st->top=-1;
    st->item=(char *)malloc(st->stacksize*sizeof(char));
    int i=0;
    int j=0;
    while(i<n){
        char c=infix[i];
        if(isalnum(c)){
            postFix[j]=c;
            j++;
        }
        else if(c=='('){
            push(st,c);
        }
        else if(!isEmpty(st) && c==')'){
            while(!isEmpty(st) && top(st)!='('){
                postFix[j]=pop(st);
                j++;
            }
            pop(st);
        }
        else if(isOperator(c)){
            while(!isEmpty(st) && precedence(c)<=precedence(top(st))){
                postFix[j]=pop(st);
                j++;
            }
            push(st,c);
        }
        i++;
    }
    while(!isEmpty(st)){
        postFix[j]=pop(st);
        j++;
    }
    postFix[j]='\0';
    free(st->item);
    free(st);

    return postFix;
}
int main(){
    char infix[100];
    printf("Enter the infix expression : ");
    fgets(infix,100,stdin);
    size_t length=strlen(infix);
    if(infix[length-1]=='\n'){
        infix[length-1]='\0';
        length--;
    }
       
    char *postFix=(char *)malloc((length+1)*sizeof(char));

    postFix=convertInfixToPostfix(infix,postFix,length);

    printf("The postFix Expression is : \n%s",postFix);
    
    reverseString(infix,length);
    for(int i=0;i<length;i++){
        if(infix[i]==')') infix[i]='(';
        else if(infix[i]=='(') infix[i]=')';
    }
    printf("\n");
    char *preFix=(char *)malloc((length+1)*sizeof(char));
    preFix=convertInfixToPostfix(infix,preFix,length);
    reverseString(preFix,strlen(preFix));
    printf("\n");
    printf("The preFix Expression is : \n%s",preFix);
    return 0;
}