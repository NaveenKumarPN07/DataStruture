#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node *concat(Node *head1, Node *head2)
{
    Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

Node *sort(Node *head)
{
    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL){
        temp = head;
        while (temp->next != NULL)
        {if (temp->data > temp->next->data)
            {   t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

Node *reverse(Node *head){
    Node *prev = NULL, *temp, *next;
    temp = head;
    while (temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

void displayLinkedLists(Node *head1, Node *head2)
{
    printf("Linked List 1: ");
    while (head1 != NULL)
    {
        printf("%d -> ", head1->data);
        head1 = head1->next;
    }
    printf("NULL\n");

    printf("Linked List 2: ");
    while (head2 != NULL)
    {
        printf("%d -> ", head2->data);
        head2 = head2->next;
    }
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    int choice, value;

    while (1)
    {
        printf("1. Insert at beginning (List 1)\n");
        printf("2. Insert at beginning (List 2)\n");
        printf("3. Sort lists\n");
        printf("4. Concatenate lists\n");
        printf("5. Reverse list 1\n");
        printf("6. Display lists\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert in List 1: ");
            scanf("%d", &value);
            list1 = insertAtBeginning(list1, value);
            break;
        case 2:
            printf("Enter value to insert in List 2: ");
            scanf("%d", &value);
            list2 = insertAtBeginning(list2, value);
            break;
        case 3:
            list1 = sort(list1);
            list2 = sort(list2);
            printf("Lists sorted.\n");
            break;
        case 4:
            list1 = concat(list1, list2);
            printf("Lists concatenated.\n");
            break;
        case 5:
            list1 = reverse(list1);
            printf("List 1 reversed.\n");
            break;
        case 6:
            displayLinkedLists(list1, list2);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
....................................................
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct node *temp;
    if (front == NULL)
        printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void printList()
{
    struct node *temp = front;
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value;

    while (1)
    {   printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Queue: ");
            printList();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
...........................................
#include <stdio.h>
#include <stdlib.h>

struct node{;
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop()
{
    struct node *temp;
    if (head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Popped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Stack: ");
            printList();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
