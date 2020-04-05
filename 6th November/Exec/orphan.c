#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void loop ()
{
		char ch ;

		while (1)
		{
			printf ("Press p to proceed\n") ;
			scanf("%[^\n]%*c", &ch);  ;
			if (ch == 'p') 
				break ;
		}
}

int main()
{	
	pid_t child = fork () ;
	int status ;

	if (child > 0)
	{
		printf ("Parent PID = %d, PPID = %d\n", (int)getpid(), (int)getppid()) ;
		loop () ;
	}
	else if (child == 0)
	{
		while (1)
		{
			printf ("Child PID = %d, PPID = %d\n" , (int)getpid(), (int)getppid()) ;
			sleep (10) ;
		}
		exit (100) ;
	}

	return 0 ;
}