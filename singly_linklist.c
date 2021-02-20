/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
struct linklist
{
    int num;               // 4
    struct linklist *next; // 8
};
struct linklist *start;

void insert();
void display();
void atend();
void atbeg();
void atbefore();
void atafter();
void atpos();
void count();
void edit();
void del();
void atbeg1();
void atend1();
void reverse();

int main()
{
    int ch1;
    char choice1 = 'y';
    start = NULL;
    system("cls"); // to clear screen

    do
    {
        printf("\n 1. INSERT     ");
        printf("\n 2. DISPLAY     ");
        printf("\n 3. Delete     ");
        printf("\n 4. COUNT NODES     ");
        printf("\n 5. EDIT A NODE     ");
        printf("\n 6. EXIT      ");
        printf("\n7. for reverse");
        printf("\n\n Enter Your Choice = ");
        scanf("%d", &ch1);

        switch (ch1)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            del();
            break;

        case 4:
            count();
            break;
        case 5:
            edit();
            break;
        case 6:
            choice1 = 'n';
            break;
            case 7:
            reverse();
            break;
        default:
            printf("invalid choice");
        }
    } while (choice1 == 'y');
    return 0;
} // end of main //
void insert()
{
    int ch2;
    char choice2;

    do
    {
        printf("\n 1. ATBEG ");
        printf("\n 2. ATEND ");
        printf("\n 3. before specified node");
        printf("\n 4. after specified node");
        printf("\n 5. at position ");
        printf("\n 6. EXIT      ");

        printf("\n\n Enter Your Choice = ");
        scanf("%d", &ch2);

        switch (ch2)
        {
        case 1:
            atbeg();
            break;
        case 2:
            atend();
            break;
        case 3:
            atbefore();
            break;
        case 4:
            atafter();
            break;
        case 5:
            atpos();
            break;
        case 6:
            choice2 = 'n';
            break;
        befault:
            printf("INVALID CHOICE");
        }
    } while (choice2 == 'y');
}
void atbeg()
{
    struct linklist *temp, *node;
    node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("\n\n enter a no.");
    scanf("%d", &node->num);
    node->next = NULL;

    if (start == NULL)
    {
        start = node;
        return;
    }
    else
    {
        temp = start;
        start = node;
        node->next = temp;
    }
}
void display()
{
    struct linklist *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d-->", temp->num);
        temp = temp->next;
    }
}

void atend()
{

    struct linklist *temp, *node;
    node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("enter the data of node : ");
    scanf("%d", &node->num);
    node->next = NULL;
    if (start == NULL)
    {
        start = node;
        return;
    }
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next; //temp is last node
    }
    temp->next = node;
}
void reverse( )
{
	struct linklist *ptr,*temp,*old;
	temp=start;
	ptr=NULL;
	while(temp!=NULL)
	{
		old       = ptr;
		ptr       = temp;
		temp=temp->next;
		ptr->next = old;
	}
	start=ptr;
}

// /* step 1 start
// variable declare of type linklist
// temp=start
// ptr=NULL
// loop: while(temp!=NULL)
//     		old       = ptr;
// 		ptr       = temp;
// 		temp=temp->next;
// 		ptr->next = old;
//  start=ptr
//  exit
//  *\

void atbefore()
{
    int val;
    struct linklist *temp, *temp1, *node;

    printf("\n before which node u want to insert = ");
    scanf("%d", &val);

    node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("enter the data of node");
    scanf("%d", &node->num);
    node->next = NULL;

    temp = start;
    while (temp->num != val)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = node;
    node->next = temp;
}

void atafter()
{
    int val;
    struct linklist *temp, *node;

    printf("\nBefore which node you want to insert = ");
    scanf("%d", &val);

    node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("enter the data of node");
    scanf("%d", &node->num);
    node->next = NULL;

    temp = start;
    while (temp->num != val)
        temp = temp->next;

    node->next = temp->next;
    temp->next = node;
}

void atpos()
{
    int i = 1, c = 0, n;
    struct linklist *temp, *temp1, *node;
    printf("enter the position no=");
    scanf("%d", &n);

    node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("\n\n enter the data of node : ");
    scanf("%d", &node->num);
    node->next = NULL;

    temp = start;

    while (temp != NULL)
    {
        c = c + 1;
        temp = temp->next;
    }
    if (n > c)
    {
        printf("\n Not valid ");
        return;
    }
    temp = start;

    while (i < n)
    {
        i = i + 1;
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = node;
    node->next = temp;
}

void count()
{
    int count = 0;
    struct linklist *temp;
    temp = start;
    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }
    printf("Number of nodes = %d", count);
}

void edit()
{
    int i = 1, count = 0, pos, num1;
    struct linklist *temp;
    printf("\n enter the position of node for edit =");
    scanf("%d", &pos);

    printf("\n\n enter the data of new node :");
    scanf("%d", &num1);

    temp = start;

    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }

    if (pos > count)
    {
        printf("\n Not valid");
        return;
    }

    temp = start;

    while (i < pos)
    {
        i = i + 1;
        temp = temp->next;
    }
    temp->num = num1;
}

void del()
{
    int ch3;
    char choice3;

    do
    {
        printf("\n 1. ATBEG 	");
        printf("\n 2. ATEND 	");
        printf("\n 3. BEFORE 	");
        printf("\n 4. AFTER      ");
        printf("\n 5. ATPOST   ");
        printf("\n 6. EXIT         ");

        printf("\n\n Enter Your Choice = ");
        scanf("%d", &ch3);

        switch (ch3)
        {
        case 1:
            atbeg1();
            break;
        case 2:
            atend1();
            break;
            //			case 3:
            //				before1( );
            //				break;
            //			case 4:
            //				after1( );
            //				break;
            //			case 5:
            //				atpos1( );
            //				break;
        case 6:
            choice3 = 'n';
            break;
        default:
            printf("\n\n INVALID CHOICE ");
        }
    } while (choice3 == 'y');
}
void atbeg1()
{
    struct linklist *temp;
    temp = start;
    start = start->next;
    temp->next = NULL;
    free(temp);
}

void atend1()

{
    struct linklist *temp, *temp1;
    temp = start;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next; //temp is last node
    }
    temp1->next = NULL;
    free(temp);
}
