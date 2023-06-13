#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};


void New_node(struct Node** head, int newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->link = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* current = *head;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = newNode;
    }
}


void Delete_particular_node(struct Node** head, int location)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node* temp = *head;
    if (location == 0)
    {
        *head = temp->link;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < location - 1; i++)
    {
        temp = temp->link;
    }
    if (temp == NULL || temp->link == NULL)
    {
        return;
    }
    struct Node* nextNode = temp->link->link;
    free(temp->link);
    temp->link = nextNode;
}


void Delete_nodes_from_particular_value(struct Node** head, int value)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current != NULL)
    {
        if (current->data == value)
        {
            if (previous == NULL)
            {
                *head = current->link;
            }
            else
            {
                previous->link = current->link;
            }
            struct Node* nextNode = current->link;
            free(current);
            current = nextNode;
        }
        else
        {
            previous = current;
            current = current->link;
        }
    }
}


void Delete_all(struct Node** head)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL)
    {
        nextNode = current->link;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}


void Display_linked_list(struct Node* head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}



int main()
{
    struct Node* head = NULL;
    int choice, data, location;
    while (1)
    {
        printf("1. Insert new node\n2. Delete node at particular location\n3. Delete all nodes from a particular value\n4. Delete the complete linked list\n5. Display the linked list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the data for new node: ");
                scanf("%d", &data);
                New_node(&head, data);
                break;
            case 2:
                printf("Enter the location of the node to delete: ");
                scanf("%d", &location);
                Delete_particular_node(&head, location);
                break;
            case 3:
                printf("Enter the value to delete from the list: ");
                scanf("%d", &data);
                Delete_nodes_from_particular_value(&head, data);
                break;
            case 4:
                Delete_all(&head);
                printf("Linked list has been deleted\n");
                break;
            case 5:
                printf("Linked list: ");
                Display_linked_list(head);
                break;
            case 6:
                printf("Exited\n");
                exit(0);
            default:
                printf("ERROR: Invalid choice\n");
        }
    }
    return 0;
}