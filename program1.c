#include<stdio.h>
void push(int *top,int a[],int maxi){
    if(*top == maxi-1){
        printf("stack is full!\n");
        return ;
    }
    else{
        int value;
        printf("enter the value:\n");
        scanf("%d",&value);
        (*top)++;
        a[*top] = value;
    }
}
void pop(int a[],int *top){
    if(*top ==-1){
        printf("Stack under flow!\n");
        return ;
    }
    int value = a[*top];
    (*top)--;
    printf("poped element is %d\n",value);
}
void display(int a[],int top){
    if(top == -1){
        printf("stack under flow!\n");
    }
    for(int i=0;i<=top;i++){
        printf("%d ",a[top]);
    }
}
int main(){
    int maxi = 5;
    int a[maxi],top = -1,choice;
    while(1){
        printf("\nMenu\n");
        printf("1 . push\n");
        printf("2 . pop\n");
        printf("3 . display\n");
        printf("4 . exit\n");
        printf("enter your option \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                push(&top,a,maxi);
                break;
            case 2:
                pop(a , &top);
                break;
            case 3:
                display(a , top);
                break;
            case 4:
                return 0;
            default:
                printf("enter the correct choice!\n");
        }
    }
}
