#include<dlfcn.h>
#include<stdio.h>
#include"SharedFile.h"


int main()
{
	void *p = NULL;
	SinglyLL *ptr = NULL;
	SinglyLL *(*fp1)()  =NULL;
	void (*fp2)(SinglyLL *) = NULL;

	DoublyLL *(*Dfp1)()  =NULL;
	void (*Dfp2)(DoublyLL *) = NULL;
	

	p = dlopen("/home/student/Desktop/DS Library/lib.so",RTLD_NOW);

	if(!p)
	  {
		printf("%s\n",dlerror());
		printf("Unabled to load library\n");
		return -1;
	}
printf("Loaded..\n");
	
	fp1 = (SinglyLL*(*)())dlsym(p,"create");	
	fp2 = (void (*)(SinglyLL *))dlsym(p,"destroy");	
	
	Dfp1 = (DoublyLL*(*)())dlsym(p,"create1");	
	Dfp2 = (void (*)(DoublyLL *))dlsym(p,"destroy");
	
	ptr = fp1();

	ptr->InsertFirst(30);
	ptr->InsertFirst(20);
	ptr->InsertFirst(10);
	ptr->InsertLast(50);
	ptr->InsertLast(60);
	ptr->Display();
	ptr->InsertAtPosition(40,3);
	ptr->Display();
	cout<<ptr->Count()<<endl;
	ptr->DeleteFirst();
	ptr->Display();
	ptr->DeleteLast();
	ptr->Display();
	cout<<"Delete\n";
	ptr->DeleteAtPosition(3);
	ptr->Display();
	
	fp2(ptr);

	ptr = fp1();
	cout<<"Doubly Start...........\n";
	ptr->InsertFirst(30);
	ptr->InsertFirst(20);
	ptr->InsertFirst(10);
	ptr->InsertLast(50);
	ptr->InsertLast(60);
	ptr->Display();
	ptr->InsertAtPosition(40,3);
	ptr->Display();
	cout<<ptr->Count()<<endl;
	ptr->DeleteFirst();
	ptr->Display();
	ptr->DeleteLast();
	ptr->Display();
	cout<<"Delete\n";
	ptr->DeleteAtPosition(3);
	ptr->Display();
	
	fp2(ptr);


	dlclose(p);
	return 0;
}
