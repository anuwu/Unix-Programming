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
	}
	else if (child == 0)
	{
		sleep (1) ;
		printf ("Child PID = %d, PPID = %d\n" , (int)getpid(), (int)getppid()) ;
		exit (100) ;
	}

	return 0 ;
}