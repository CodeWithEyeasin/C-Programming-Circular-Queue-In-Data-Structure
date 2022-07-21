#include <stdio.h>
#define MAX 5
void insert();
void delete();
void display();
int queue_array[MAX];
int front = - 1;
int rear = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice \n\n");
        }
    }
}

void insert()
{
    int x;
    printf("Enter The Element: \n");
    scanf("%d",&x);
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue_array[rear] = x;
    }
    else if(((rear+1)%MAX) == front)
    {
        printf("Queue Is Overflow\n");
    }
    else
    {
        rear=(rear+1)%MAX;
        queue_array[rear] = x;
    }
}

void delete()
{
    if (front == - 1 && rear == -1)
    {
        printf("\nQueue Is Underflow \n");
        return ;
    }
    else if(front==rear)
    {
        printf("%d",queue_array[front]);
       front = rear = -1;
    }
    else
    {
        printf("\ndeleted element %d",queue_array[front]);
        front = (front +1)%MAX;
    }

}

void display()
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < MAX; i++)
        {
            printf("%d ", queue_array[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", queue_array[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
    }
}
