#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int glob = 0 ;

void loop ()
{
		char ch ;

		while (1)
		{
			printf ("Press p to proceed\n") ;
			scanf("%[^\n]%*c", &ch);  
			if (ch == 'p') 
				break ;
		}
}

void doSomeWork (char *name)
{
	char ch ;

		while (1)
		{
			printf ("Press p to proceed for process %s and global %d\n" , name, glob) ;
			scanf("%[^\n]%*c", &ch);  
			if (ch == 'p') 
				break ;
		}

	glob++ ;

}


int main ()
{	
	printf ("I am %d\n" , (int)getpid()) ;

	doSomeWork("Parent") ;

	pid_t pid = fork () ;
	printf ("Fork returned %d\n" , (int)pid) ;

	if (pid < 0)
	{
		perror ("Fork failed\n") ;
	}
	else if (pid == 0)
	{
		printf ("I am the child with pid %d\n" , (int)getpid()) ;
		doSomeWork ("Child") ;
		printf ("Child exiting ...\n") ;
		exit (0) ;
	}

	printf ("I am the parent, waiting for child to finish\n") ;
	wait (NULL) ;


	doSomeWork("Parent") ;
	printf ("Parent ending.\n") ;

	return 0 ;
}

/*

Global variables were supposed to be separate?

I am 26693
Press p to proceed for process Parent and global 0
p
Fork returned 26694
I am the parent, waiting for child to finish
Fork returned 0
I am the child with pid 26694
Press p to proceed for process Child and global 1
p
Child exiting ...
Press p to proceed for process Parent and global 1
p
Parent ending.


*/