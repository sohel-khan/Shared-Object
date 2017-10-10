#include<dlfcn.h>
#include<stdio.h>

void *createSH(int iNo)
{
	void *p = NULL;

	if(iNo == 1)
	{
	p = dlopen("/home/student/Desktop/DS Library/Nested/.SO/SinglyLL.so",RTLD_NOW);

	return p;
	}	
	else if(iNo == 2)
	{
	p = dlopen("/home/student/Desktop/DS Library/Nested/.SO/SinglyLL.so",RTLD_NOW);

	return p;
	
	}else
	{
		
		return NULL;	
	}	
	

}


