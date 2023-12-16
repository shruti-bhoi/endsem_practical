#include<iostream>
#define MAX_SIZE 5
using namespace std;

class CircularQueue
{
	private:
		int front, rear;
		int arr[MAX_SIZE];
	public:
		CicularQueue()
		{
			front=-1;
			rear=-1;
		}
	int isFull()
	{
		if((front==0 && rear == MAX_SIZE - 1)||((rear+1) % MAX_SIZE==front))
		{
			return 1;
		}
	return 0;
	}
	
	int isEmpty()
	{
		if(front == -1)
		{
			return 1;
		}
	return 0;
	}
	
	void enQueue(int value)
	{
		if(isFull())
		{
			cout<<"Queue is full."<<endl;
		}
		else
		{
			if(front==-1)
			{
				front=0;
			}
			rear=(rear+1)%MAX_SIZE;
			arr[rear]=value;
			cout<<"Enqueued element: "<<value<<endl;
		}
	}
	
	int deQueue()
	{
		int element;
		if (isEmpty())
		{
			cout<<"Queue is empty." <<endl;
			return -1;
		}
		else
		{
			element=arr[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front=(front+1)%MAX_SIZE;
			}
			cout<<"Dequeued element: "<<element<<endl;
		return element;
		}
	}
	void display()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty." <<endl;
		}
		else
		{
			cout<<"Elements in the queue: ";
			int i;
			for(i=front; i!=rear; i=(i+1)%MAX_SIZE)
			{
				cout<<arr[i]<<" "<<",";
			}
			cout<<arr[i]<<"j"<<endl;
		}
	}
};
int main()
{
	CircularQueue q;
	int Num,ch;
	do
	{
		cout<<"\n Queue Opeartion";
		cout<<"\n 1. Add element to queue";
		cout<<"\n 2. Delete element from queue";
		cout<<"\n 3. Elements in the queue are: ";
		cout<<"\n Enter choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the value::";
				cin>>Num;
				q.enQueue(Num);
				break;
			case 2:
				q.deQueue();
				break;
			case 3:
				q.display();
				break;
		}
		cout<<"\n do you want to continue";
		cin>>ch;
	}
	while(ch!=4);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

