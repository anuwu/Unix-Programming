#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	printf ("execDemo : My PID is %d\n" , (int)getpid()) ;

	char *args[] = {"./helloExec" , "Hello" , "World", NULL} ;
	execvp (args[0] , args) ;
	//execl ("./helloExec" ,  "./helloExec", "123", "545", NULL) ;

	printf ("Farewell cruel world!\n") ;

	return 0 ;
}