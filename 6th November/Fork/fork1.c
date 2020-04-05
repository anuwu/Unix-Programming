#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main ()
{	
	pid_t p1 ;

	printf ("Statement 1 %d %d\n" , (int)getpid() , (int)getppid()) ;
	p1 = fork () ;

	printf ("The fork return is %d\n" , (int)p1) ;
	printf ("Statement 2 %d %d\n" , (int)getpid(), (int)getppid()) ;

	return 0 ;
}

/*
Statement 1 24382 24299
The fork return is 24383
Statement 2 24382 24299
The fork return is 0
Statement 2 24383 24382
*/
