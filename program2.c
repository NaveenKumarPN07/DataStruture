#include<stdio.h>
void push (char stack[] ,int *top , int maxsize , int value){
    if(*top == maxsize-1){
        printf("stack overflow!\n");
        return ;
    }
    stack[++(*top)] = value;
}
char pop(char stack[] , int *top){
    if(*top == -1){
        printf("stack under flow!\n");
        return -1;
    }
    else{
        int value = stack[*top];
        (*top)--;
        return value;
    }

}
int isoperand(char c){
    return ((c >= 'A' && c<='Z') || (c>='a' && c<='z') || (c>= '0' && c<='9'));
}
int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
void infixtopostfix(char exp[],int maxsize){
    char stack[maxsize] ;
    int i=0;
    int top = -1;
    while(exp[i]!='\0'){
        if(isoperand(exp[i])){
            printf("%c",exp[i]);
        }
        else if(exp[i] == '('){
            push(stack , &top , maxsize , exp[i]);
        }
        else if(exp[i] == ')'){
            while(top!=-1 && stack[top] != '('){
                printf("%c",pop(stack  ,&top));
            }
            pop(stack , &top);
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(exp[i])){
                printf("%c",pop(stack , &top));
            }
            push(stack , &top , maxsize , exp[i]);
        }
        i++;
    }
    while(top!=-1){
        printf("%c" , pop(stack , &top ));
    }
}
int main(){
    int maxsize  = 100;
    char exp[maxsize];
    printf("enter  valid infix:\n");
    scanf("%s",exp);
    printf("postfix expression :\n");
    infixtopostfix(exp , maxsize);
    printf("\n");

}
