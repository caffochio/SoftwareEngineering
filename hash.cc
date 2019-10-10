#include <stdio.h>
#include <iostream> 
#include <string.h> 
#include <stdlib.h>
using namespace std;

#define Delta 7
#define Size 300

struct list
{
	struct list *next;
	int data;
};

int main()
{
	/* List */
	struct list head;
	head.data = rand()%100000+1;
	head.next = (struct list *)malloc(sizeof(struct list));

	struct list *look;
	look = head.next;

	for (int i=0; i<99; i++)
	{
		look->data=rand()%100000+1;
		look->next=(struct list *)malloc(sizeof(struct list));
		look = look->next;
	}
	cout<<head.data<<",";
	look = head.next;
	for (int i=0; i<99; i++)
	{
		cout<<look->data<<",";
		look = look->next;
	}
	cout<<endl;

	/* Hash */
	int backet[Size];
	for (int i=0; i<Size; i++)
	{
		backet[i]=0;
	}
	backet[head.data%Size]=head.data;
	look = head.next;
	for (int i; i<100; i++)
	{
		if(backet[look->data%Size]==0)
		{
			backet[look->data%Size]=look->data;
		}
		else
		{
			int jump=Delta;
			while(1)
				{
					if(backet[look->data%Size+jump]==0)
					{
						backet[look->data%Size+jump]=look->data;
						break;
					}
					else
					{
						jump+=Delta;
						if(look->data%Size+jump>=Size)
						{
							jump-=Size;
						}
					}
				}
		}
		look = look->next;
	}

	/* Hash Search */
	int key;
	cout<<"key(Pick number from above): ";
	cin>>key;
	while (1)
	{
		int step=1;
		int jump=0;
		if (backet[key%Size+jump]==key)
		{
			cout<<step<<endl;
			break;
		}
		else
		{
			step+=1;
			jump+=7;
			if (key%Size+jump >= Size)
			{
				jump-=Size;
			}
		}

	}

	exit(0);
}