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
		printf ("Parent sleeping...\n") ;
		sleep (10) ;		//Check ps -a here, will enlist as zombie.
		wait (&status) ;	
		loop () ;			//While waiting for stdin, no more zombie process.
	}
	else if (child == 0)
		exit (100) ;

	return 0 ;
}