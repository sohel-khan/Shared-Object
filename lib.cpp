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


	DoublyLL::DoublyLL()
	{
		head=NULL;
	}

	DoublyLL::~DoublyLL()
{
		PNODE1 temp1=head,temp2=NULL;

		if(head == NULL)
		{
			return;
		}

		while(temp1 != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			delete temp2;
		}

}



void DoublyLL::Display()
{
	PNODE1 temp=head;
	cout<<"--------------------------"<<endl;
	if(temp == NULL)
	{
		cout<<"List is Empty"<<endl;
	}

	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
int DoublyLL::Count()
{
	PNODE1 temp=head;
	int iCnt=0;
	cout<<"--------------------------"<<endl;
	if(temp == NULL)
	{
		cout<<"List is Empty"<<endl;
	}

	while(temp != NULL)
	{
		iCnt++;
		temp = temp->next;
	}

	return iCnt;
}

void DoublyLL::InsertFirst(int iNo)
{
	PNODE1 newn = new NODE1;

	newn->prev=NULL;
	newn->data = iNo;
	newn->next=NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		head->prev = newn;
		newn->next = head;

		head=newn;
	}

}


void DoublyLL::InsertLast(int iNo)
{
	PNODE1 temp=head;
	PNODE1 newn = new NODE1;
	newn->prev=NULL;
	newn->data=iNo;
	newn->next=NULL;

	if(head == NULL)
	{
		head = newn;
	}
	else
	{
		while(temp->next !=NULL)
		{
			temp=temp->next;
		}
		newn->prev=temp;
		temp->next=newn;
	}
}



void DoublyLL::InsertAtPosition(int iNo,int iPos)
{
	PNODE1 temp1=head;
	
	PNODE1 newn = new NODE1;
	newn->next = NULL;
	newn->data = iNo;
	newn->prev = NULL;

	if(iPos == 1)
	{
		InsertFirst(iNo);
	}
	else if(iPos > Count())
	{
		InsertLast(iNo);
	}
	else
	{
		while(iPos != 2)
		{
			temp1 = temp1->next;
			iPos--;
		}
		newn->next = temp1->next;
		temp1->next->prev = newn;
		newn->prev = temp1;
		temp1->next = newn;


	}
}

void DoublyLL::DeleteFirst()
{
	PNODE1 temp=head;
	if(temp== NULL)
	{
		return;
	}
	else
	{
		head=head->next;
		head->prev=NULL;
		delete temp;
	}

}

void DoublyLL::DeleteLast()
{
	PNODE1 temp1 = head,temp2;

	if(temp1 == NULL)
	{
		cout<<"List is Empty"<<endl;
		return;
	}
	else
	{
		while(temp1->next != NULL)
		{
			temp1 = temp1->next;
		}

		temp2 = temp1->prev;
		temp2->next = NULL;

		delete temp1;

	}
}

void DoublyLL::DeleteAtPosition(int iPos)
{
	if(iPos > Count())
	{
		cout<<"Enter valid Position"<<endl;
		return;
	}

	PNODE1 temp1=head,temp2=NULL;
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == Count())
	{
		DeleteLast();
	}
	else
	{
		while(iPos != 2)
		{
			temp1=temp1->next;
			iPos--;
		}
		temp2=temp1->next;
		temp1->next=temp2->next;
		temp1->next->prev=temp1;
		delete temp2;
	}

}




	extern"C"
{
	DoublyLL *create1()
	{
	
		return new DoublyLL();
	}

	void destroy1(DoublyLL *p)
	{
		delete p;
	}

}


