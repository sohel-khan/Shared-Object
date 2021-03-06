#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;

}NODE,*PNODE;

class SinglyLL
{
private:
	PNODE head;

public :
	SinglyLL();
	~SinglyLL();
	virtual void InsertFirst(int);
	virtual void InsertLast(int);
	virtual void InsertAtPosition(int,int);
	virtual void DeleteFirst();
	virtual void DeleteLast();
	virtual void DeleteAtPosition(int);
	virtual int Count();
	virtual void Display();

};


typedef struct node1
{
	struct node1 *prev;
	int data;
	struct node1 *next;

}NODE1,*PNODE1;


class DoublyLL
{
private:
	PNODE1 head;

public:

	DoublyLL();
	
	~DoublyLL();
	

	virtual void InsertFirst(int);
	virtual void InsertLast(int);
	virtual void InsertAtPosition(int,int);
	virtual void DeleteFirst();
	virtual void DeleteLast();
	virtual void DeleteAtPosition(int);
	virtual void Display();
	virtual int Count();
};

