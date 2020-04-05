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
	pipe (fedes) ;
	close (STDIN) ;
	dup (fedes[0]) ;
	dup2 (fedes[0] , STDIN) ;
	execlp ("sort", "sort", "dummy.txt", NULL) ;

	return 0 ;
}