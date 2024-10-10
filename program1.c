#include<stdio.h>
int stack[5];
int top = -1;
void push(int x){
    if(top==5-1){
        printf("stack overflow\n ");//stack over flow
    }
    else{
        top++;
        stack[top] = x;
        printf("pushed element is %d\n",x);//pushing elements into the stack
    }
}
void pop (){
    if(top ==-1 ){
        printf("under flow\n ");//under flow
    }
    else{
        int item ;
        item = stack[top];
        top--;
        printf("poped element is %d\n",item);//poping of top  element
    }
}
int display(){
    printf("stack elemnts are :");
    for(int i= top;i>=0;i--){
        printf("%d\n",stack[i]);//dispalying elements from top
    }
}
int main(){
    push(4);
    push(2);
    push(9);
    push(2);
    push(6);
    push(5);
    pop();
    display();
    return 0;

}