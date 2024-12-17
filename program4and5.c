
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createnode(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertatfirst(struct Node **head, int value) {
    struct Node *temp = createnode(value);
    temp->next = *head;
    *head = temp;
}

void insertatend(struct Node **head, int value) {
    if (*head == NULL) {
        *head = createnode(value);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createnode(value);
}

void insertatpos(struct Node **head, int value, int pos) {
    if (pos < 0) {
        printf("Position cannot be negative!\n");
        return;
    }
    if (pos == 0) {
        insertatfirst(head, value);
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node *newnode = createnode(value);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteatfirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatlast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteatspecificele(struct Node **head, int ele) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    if ((*head)->data == ele) {
        deleteatfirst(head);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != ele) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element %d not found in the list!\n", ele);
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void deleteatpos(struct Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    if (pos < 0) {
        printf("Position cannot be negative!\n");
        return;
    }
    if (pos == 0) {
        deleteatfirst(head);
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, pos, ele;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at First\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete at First\n5. Delete at Last\n6. Delete at Position\n");
        printf("7. Delete Specific Element\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertatfirst(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertatend(&head, value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertatpos(&head, value, pos);
                break;
            case 4:
                deleteatfirst(&head);
                break;
            case 5:
                deleteatlast(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteatpos(&head, pos);
                break;
            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &ele);
                deleteatspecificele(&head, ele);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
