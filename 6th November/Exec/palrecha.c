#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{	
	printf ("Hello\n") ;
	fork ();
	printf ("Bye\n") ;

	return 0 ;
}