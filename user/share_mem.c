// Create a zombie process that
// must be reparented at exit.

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(void)
{
	exit();
}
