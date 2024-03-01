#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int proveri(int x)
{
	int pom=1;
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
			pom=0;
	}
	return pom;
}

int
main(int argc, char **argv)
{	
	void* niz;
	void* index;
	void* cik;
	get_shared("niz",&niz);
	get_shared("index",&index);
	get_shared("cik",&cik);

	int ind=1;
	int i=2;
	int pause=0;
	while(1)
	{	
		if(*((int*)(cik))==-1){break;}
		if(*((int*)(cik))==2) pause=1;
		if(*((int*)(cik))==1) pause=0;
		
		if(pause==0){ 
			if(proveri(i))
			{
				*((int*)index)=ind;
				((int*)niz)[ind]=i;
				ind++;
				//printf("%d\n",((int*)niz)[*((int*)index)]);
			}
			i++;	
		}
		printf("");
	}
	
	exit();
}
