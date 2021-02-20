/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*QUEUE OPERATIONS USING ARRAY*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1;
int queue[MAX];
int main()
{
 void insert();
 void del();
 void traverse();
 int ch;
 
 printf("QUEUE APPLICATION:USING ARRAY:");
 do
 {
  printf("\n1.INSERTION\n");
  printf("2.DELETION\n");
  printf("3.TRAVERSE\n");
  printf("4.EXIT\n");
  printf("enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:insert();break;
   case 2:del();break;
   case 3:traverse();break;
   case 4:printf("END OF QUEUE APPLICATION:");break;
   default:printf("YOU HAVE ENTERED WRONG CHOICE:");
  }
 }while(ch!=4);
	return 0;
}

void insert()
{
 int item;
 printf("enter no for insertion:");
 scanf("%d",&item);
 if(rear==MAX-1)
 {
  printf("QUEUE OVERFLOW");
  return ;
 }
  rear++;
  queue[rear]=item;
  if( front == -1)
  	front++;
 }
 
 
void del()
{
 int item=0;
 if(front== -1)
 {
  printf("QUEUE IS EMPTY:");
  return ;
 }
 if(front==rear)
  {
   item=queue[front];
   queue[front] = 0;
   front=-1;
   rear=-1;
printf("%d is deleted:",item);
   return ;
  }
   item=queue[front];
   queue[front] = 0;
   front++;
   printf("%d is deleted:",item);
}


void traverse()
{
 int temp;
 if(rear == -1)
 {
 	printf("QUEUE IS EMPTY:");
 	return;
  } 
  temp = front;
  printf("ELEMENTS OF QUEUE: ");
  while(temp <= rear )
  {
  	  printf("%d ",queue[temp]);
  	  temp = temp + 1;
  }
}
