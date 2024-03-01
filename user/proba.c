#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	int pid;
	char *argv2[]={"/bin/ls",0};
	
	share_mem("Zarko",4,120000);
	share_mem("Petar",12000,52);
	pid=fork();
	if(pid==0)
	{
		exec("/bin/ls",argv2);
		
	}
	else
	wait();

	exit();
}
