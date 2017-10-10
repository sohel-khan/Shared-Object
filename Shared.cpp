#include<iostream>
#include<stdio.h>
#include"SharedFile.h"


	SinglyLL::SinglyLL()
	{
		head=NULL;
	}

	SinglyLL::~SinglyLL()
	{
	
		if(head == NULL)
		{
			return;
		}
		PNODE temp1=NULL,temp2=NULL;

		temp1 = head;

		while (temp1 != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			delete temp2;
		}
	}

void SinglyLL::InsertFirst(int no)
{
	PNODE newn = new NODE;
	newn->data = no;
	newn->next=NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		newn->next = head;
		head = newn;
	}
}


void SinglyLL::InsertLast(int no)
{
	PNODE temp=head;
	PNODE newn = new NODE;
	newn->data = no;
	newn->next=NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next= newn;
	
	}
}

void SinglyLL::Display()
{
	PNODE temp=head;


	if(temp == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	cout<<"------------------\n";
	while (temp->next != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}

		cout<<temp->data<<endl;
		cout<<"------------------\n";
	
}

int SinglyLL::Count()
{
	int cnt=0;
	PNODE temp=head;

	if(temp == NULL)
	{
		cout<<"List is Empty"<<endl;
	}

	while (temp != NULL)
	{
		cnt++;

		temp = temp->next;
	}

	return cnt;
}


void SinglyLL::InsertAtPosition(int no,int pos)
{
	PNODE temp = head;
	
	if(temp == NULL)
	{
		cout<<"List is Empty...\n";
		return;
	}

	if(pos == 1)
	{
		InsertFirst(no);

	}else if(pos > Count())
	{
		InsertLast(no);
	}
	else
	{
		while (pos != 2)
		{
			temp = temp->next;
			pos--;
		}
		PNODE newn = new NODE;

		newn->next= NULL;
		newn->data = no;
		
		newn->next = temp->next;
		
		temp->next = newn; 
	}

}

void SinglyLL::DeleteFirst()
{
	PNODE temp=NULL;
	temp = head;

	if(temp == NULL)
	{
		cout<<"List is Empty";
		return;
	}

	head = head->next;
	delete temp;

}

void SinglyLL::DeleteLast()
{
	PNODE temp=NULL;
	temp = head;

	if(temp == NULL)
	{
		cout<<"List is Empty";
		return;
	}
		while(temp->next->next != NULL)
		{
		 temp = temp->next;
		}
	    
		delete temp->next;
		temp->next=NULL;
	
}

void SinglyLL::DeleteAtPosition(int ipos)
{
	PNODE temp=NULL,temp1=NULL;
	temp = head;

	if(temp == NULL)
	{
		cout<<"List is Empty";
		return;
	}
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == Count())
	{
		DeleteLast();
	}
	else
	{
		while(ipos != 2)
		{
		 temp = temp->next;
		 ipos--;
		}
	    temp1=temp->next->next;

		delete temp->next;
		temp->next=temp1;
	}
}

	extern"C"
{
	SinglyLL *create()
	{
	
		return new SinglyLL();
	}

	void destroy(SinglyLL *p)
	{
		delete p;
	}

}


