#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * start;
void create(int n)
{
    int dat, i;
    struct node *newnd, *temp;
    start = malloc(sizeof(struct node));
    if (start == NULL)
        printf("not enough space ");
    else
    {
        printf("\nenter data for node 1:");
        scanf("%d", &dat);
        start->data = dat;
        start->next = NULL;
        temp = start;
    }
    for (i = 2; i <= n; i++)
    {
        newnd = (struct node *)malloc(sizeof(struct node));
        if (newnd == NULL)
            printf("not enough space ");
        else
        {
            printf("enter data for node %d:", i);
            scanf("%d", &dat);
            newnd->data = dat;
            newnd->next = NULL;
            temp->next = newnd;
            temp = temp->next;
        }
    }
    temp->next = start;
}
void traversal()
{
    struct node *ptr;
    ptr = start;
    int count = 1;
    if (ptr == NULL)
        printf("\nlist is empty!");

    else
    {
        do
        {
            printf("%d-> ", ptr->data);
            ptr = ptr->next;
            count++;
        } while (ptr != start);

        printf("\n total number of nodes are :%d", count - 1);
    }
}
void sortlist()
{

    struct node *temp = start;
    struct node *ptr;
    int temp2;
    do
    {
        ptr = temp->next;
        do
        {
            if (temp->data > ptr->data)
            {
                temp2 = temp->data;
                temp->data = ptr->data;
                ptr->data = temp2;
            }
            ptr = ptr->next;
        } while (ptr != start);
        temp = temp->next;
    } while (temp->next != start);
    traversal();
}
void removedup()
{

    struct node *temp = start;
    struct node *ptr;
    struct node *temp2 = NULL;

    do
    {
        ptr = temp->next;
        temp2 = temp;
        do
        {
            if (temp->data == ptr->data)
            {
                temp2->next = temp2->next->next;
            }
            temp2 = ptr;
            ptr = ptr->next;
        } while (ptr != start);
        temp = temp->next;
    } while (temp->next != start);

    traversal();
}
int main()
{
    int choice, n;
    do
    {
        printf("\n\t1 For creation of circular link list \n");
        printf("\t2. For traversal and counting the nodes  \n");
        printf("\t3.For sorting  \n");
        printf("\t4.For deletion of duplicate\n");
        printf("\t5.To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int tn;
            printf("\nenter number of nodes:");
            scanf("%d", &tn);
            create(tn);
            break;
        }
        case 2:
        {
            traversal();
            break;
        }
        case 3:
        {
            sortlist();
            break;
        }

        case 4:
        {
            removedup();
            break;
        }

        case 5:
        {
            exit(1);
        }
        default:
            printf("\n enter valid choice!");
        }
        printf("\ndo you wish to continue (0/1):");
        scanf("%d", &n);
    } while (n);
}