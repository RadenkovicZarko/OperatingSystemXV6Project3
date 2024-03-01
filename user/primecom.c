#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

char* my_strcpy(char* destination, const char* source)
{
	
	for(int i=0;i<6;i++)
	{
		source++;
	}
	char *ptr = destination;
	while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
	return ptr;
}


int
main(int argc, char **argv)
{
	/*share_mem("niz",niz,100000*sizeof(int));
	share_mem("index",index,sizeof(int));
	share_mem("cik",cik,sizeof(int));*/
	
	void *niz;
	get_shared("niz",&niz);
	void *index;
	get_shared("index",&index);
	void *cik;
	get_shared("cik",&cik);

	char* komanda=malloc(15*sizeof(char));
	
	while(1)
	{
		gets(komanda,15);
		komanda[strlen(komanda)-1]='\0';
	
		if(strcmp(komanda,"end")==0)
		{
			*((int*)cik)=-1;
			sleep(1);
			break;
		}
		if(strcmp(komanda,"latest")==0)
		{
			int i=(*((int*)index))-1;
			printf("Latest prime is no: %d value: %d\n",i,((int*)niz)[i]);
		}
		if(strcmp(komanda,"pause")==0)
		{
			*((int*)cik)=2;
			printf("Pausing...\n");
		}

		if(strcmp(komanda,"resume")==0)
		{
			*((int*)cik)=1;
			printf("Resuming...\n");
		}


		char* pom=malloc(50*sizeof(char));
		strncpy(pom,komanda,5);
		if(strcmp(pom,"prime")==0)
		{
			
			pom=malloc(50*sizeof(char));
			my_strcpy(pom,komanda);
			int maxi=(*((int*)index))-1;
			if(atoi(pom)>maxi)
			{
				printf("Still haven't calculated prime no. %s. We have primes up to %d\n",pom,maxi);
			}
			else
			printf("number: %d i: %d\n",((int*)niz)[atoi(pom)],atoi(pom));
			
		}

	}
	exit();
}
