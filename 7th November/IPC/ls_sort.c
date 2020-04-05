#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define STDIN 0
#define STDOUT 1
#define BUF_SIZE 1024


int main ()
{
	int fedes[2] ;
	char buf[BUF_SIZE+1] ;
	pipe (fedes) ;

	if (fork())		//parent ---> Reads from pipe (sort function)
	{
		dup2 (fedes[0] , STDIN) ;

		close (fedes[1]) ;
		execlp ("sort" , "sort" , "-R" , NULL) ;

	}
	else		//Child --> Writes to pipe (ls function)
	{
		dup2 (fedes[1], STDOUT) ;

		char *args[] = {"ls", "-l", NULL} ;
		close (fedes[0]) ;
		execvp (args[0], args) ;
	}

	return 0 ;
}