//3(a)//
#include<stdio.h>
void enqueue(int q[] , int *rear , int *front , int size){
    if(*rear == size -1){
        printf("queue is full!\n");
        return ;
    }
    else{
        int value;
        printf("enter the value :\n");
        scanf("%d",&value);
        if(*front == -1){
            *front = *rear = 0;
        }
        else{
            (*rear)++;
        }
        q[*rear ] = value;
    }
}
void dequeue(int q[] , int *rear , int *front,int size){
    if(*front == -1){
        printf("queue is empty !\n");
        return ;
    }
    else{
        int value = q[*front];
        if(*front == *rear){
            *front = *rear = -1;
        }
        else{
            (*front)++;
        }
        printf("dequed element is %d" , value);
    }
}
void Display(int q[] , int front , int rear){
    if(front == -1){
        printf("queue is empty!\n");
        return;
    }
    else{
        for(int i=front ; i<=rear;i++){
            printf("%d " , q[i]);
        }
    }
    printf("\n");
}
int main(){
    int size = 6;
    int q[size] , rear = -1 , front = -1,choice;
    while(1){
        printf("\nMenu\n");
        printf("1 . enqueue\n");
        printf("2 . dequeue\n");
        printf("3 . display\n");
        printf("4 .exit\n");
        printf("enter the choice :\n");
        scanf("%d" , &choice);
        switch(choice){
            case 1: 
                enqueue(q , &rear , &front , size);
                break;
            case 2:
                dequeue(q , &rear , &front , size);
                break;
            case 3:
                Display(q , front , rear);
                break;
            case 4:
                return 0 ;
            default :
                printf("enter the  valid choice!\n");
        }
    }
}
...............................................................................................
  //3(b)//
  #include<stdio.h>
void enqueue(int q[] , int *rear , int *front , int size){
    if((*rear+1)%size == (*front )){
        printf("queue is full!\n");
        return ;
    }
    else{
        int value;
        printf("enter the value :\n");
        scanf("%d",&value);
        if(*front == -1 ){
            *front = *rear = 0;
        }
        else{
            (*rear) = (*rear + 1)%size;
        }
        q[*rear ] = value;
    }
}
void dequeue(int q[] , int *rear , int *front,int size){
    if(*front == -1){
        printf("queue is empty !\n");
        return ;
    }
    else{
        int value = q[*front];
        if(*front == *rear){
            *front = *rear = -1;
        }
        else{
            (*front) = (*front +1)%size;
        }
        printf("dequed element is %d" , value);
    }
}
void Display(int q[] , int front , int rear,int size){
    if(front == -1){
        printf("queue is empty!\n");
        return;
    }
    else{
        if(front>rear){
            for(int i = front;i<size;i++){
                printf("%d ",q[i]);
            }
            for(int i=0;i<=rear;i++){
                printf("%d " , q[i]);
            }
        }
        else{
            for(int i=front ;i<=rear;i++){
                printf("%d " , q[i]);
            }
        }
    }
    printf("\n");
}
int main(){
    int size = 6;
    int q[size] , rear = -1 , front = -1,choice;
    while(1){
        printf("\nMenu\n");
        printf("1 . enqueue\n");
        printf("2 . dequeue\n");
        printf("3 . display\n");
        printf("4 .exit\n");
        printf("enter the choice :\n");
        scanf("%d" , &choice);
        switch(choice){
            case 1: 
                enqueue(q , &rear , &front , size);
                break;
            case 2:
                dequeue(q , &rear , &front , size);
                break;
            case 3:
                Display(q , front , rear,size);
                break;
            case 4:
                return 0 ;
            default :
                printf("enter the  valid choice!\n");
        }
    }
}
