#include<stdio.h>
#include<iostream>

#define null (0)

struct node
{
	int a;
	struct  node* next;
	node():
		a(0),next(null)
	{}
};

//! 链表倒序 
node* reverse(node** listPointer)
{
	if(null == listPointer || null == *listPointer) return null;

	node* list = *listPointer;
	node* prev = null;
	node* next = null;

	while(null != list)
	{
		next = list->next;
		list->next = prev;

		prev = list;
		list = next;
	}

	*listPointer = prev;
	return prev;
}

void insert_tail(node* list, int val)
{
	if(null == list) return;
	while(null != list->next)
	{
		list = list->next;
	}
	list->next = new node();
	list->next->a = val;
}

void printList(node* list)
{
	while(null != list)
	{
		std::cout<<list->a<<std::endl;
		list = list->next;
	}
}

int main()
{
	node* list = new node();
	for (int i = 0; i < 5; ++i)
	{
		insert_tail(list, i);
	}
	printList(list);
	node* reverseList = reverse(&list);
	printList(reverseList);

	printList(list);
	printf("hello");
}

