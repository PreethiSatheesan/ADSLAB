#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int front=-1,rear=-1,i;
int queue[MAX_SIZE];

int isEmpty()
{
return(front==-1&&rear==-1);
}

int isFull()
{
return((rear+1)%MAX_SIZE==front);
}

void enqueue(int data)
{
if(isFull())
 {
 printf("Queue is full-Overflow.Cannot enqueue./n");
 return;
 }
if(isEmpty())
 {
 front=rear=0;
 }
else
 {
 rear=(rear+1)%MAX_SIZE;
 }
queue[rear]=data;
printf("%d added to the queue.\n",data);
}

void dequeue()
{
if(isEmpty())
 {
 printf("Queue is empty-Underflow.Cannot dequeue.\n");
 return;
 }
printf("%d removed from the queue.\n",queue[front]);
if(front==rear)
 {
 front=rear=-1;
 }
else
 {
 front=(front+1)%MAX_SIZE;
 }
}

int search(int key)
{
if(isEmpty())
 {
 printf("queue is empty.Cannot search.\n");
 return -1;
 }
i=front;
do
{
if(queue[i]==key)
 {
 printf("%d found at position %d in the queue.\n",key,i);
 return -1;
 }
i=(i+1)%NAX_SIZE;
}
while(i!=(rear+1)%MAX_SIZE);
printf("%d not found in the queue.\n",key);
return -1;
}

void display()
{
if(isEmpty())
 {
 printf("Queue is empty.\n");
 return;
 }
printf("Circular queue:");
i=front;
do
 {
 printf("%d",queue[i]);
 i=(i+1)%MAX_SIZE;
 }
while(i!=(rear+1)%MAX_SIZE);
printf("\n");
}

int main()
{
int choice,data,key;
while(1)
{
 printf("\n circular queue operations:\n");
 printf("1.Add(enqueue)\n");
 printf("2.Delete(dequeue)\n");
 printf("3.Search\n");
 printf("4.Display\n");
 printf("5.Exit\n");
 printf("Enter your choice:");
 scanf("%d",&choice);

switch(choice)
{
 case 1:
 printf("Enter the element to add:");
 scanf("%d",&data);
 enqueue(data);
 break;

 case 2:
 dequeue();
 break;

 case 3:
 printf("Enter the element to search:");
 scanf("%d",&key);
 search(key);
 break;

 case 4:
 display();
 break;

 case 5:
 exit(0);

 default:
 printf("Invalid choice.Please try again.\n");
 }
 }
 return 0;
 }
