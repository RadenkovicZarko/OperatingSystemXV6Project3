#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
int niz[100000];
int
main(int argc, char **argv)
{
	printf("prime <n>\nlatest\npause\nresume\nend\n");
	int index=0;
	int cik=0;


	int pid2;
	char *argv2[]={"/bin/primecom",0};


	int pid3;
	char *argv3[]={"/bin/primecalc",0};


	int s1=share_mem("niz",niz,100000*sizeof(int));
	int s2=share_mem("index",&index,sizeof(int));
	int s3=share_mem("cik",&cik,sizeof(int));

	if(s1==-1 || s2==-1 || s3==-1)
	{
		printf("Lose prosledjen parametar");
	}
	if(s1==-2 || s2==-2 ||s3==-2)
	{
		printf("Vec postoji shared struktura sa istim imenom");
	}
	if(s1==-3 || s2==-3 || s3==-3)
	{
		printf("Ves postoji 10 shared strukura u trenutnom procesu");
	}


	pid2=fork();
	
	if(pid2==0)
	{
		exec("/bin/primecom",argv2);
	}
	else
	{
		pid3=fork();
		if(pid3==0)
		{
			exec("/bin/primecalc",argv3);
		}
		else 
		{
			wait();
			wait();
		}
	}
	
	exit();
}
