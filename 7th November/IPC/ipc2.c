#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//Child reads and parent writes

int main ()
{
	int fedes[2] ;
	char buf[30] ;

	pipe (fedes) ;

	if (fork())		//Parent
	{
		close (fedes[0]) ;
		printf ("Parent writing\n") ;
		//sleep (5) ;
		write (fedes[1], "hello", 6) ;
		printf ("Parent waiting for child to read\n") ;
		sleep (10) ;				
		wait (NULL) ;
		printf ("Parent sleeping after wait()\n") ;
		sleep (5) ;
		printf ("bye bye parent\n") ;
	}
	else		//Child
	{
		close (fedes[1]) ;
		read (fedes[0], buf, 6) ;
		sleep (5) ;								//ps -a ---> two entries of process
		printf ("Child read : %s\n", buf) ;
		exit (0) ;
	}

	return 0 ;
}

/*
Defunct process will occur only when

Parent writing
Parent waiting for child to read 		---> two entries of process
Child read : 							---> one defunct
Parent sleeping after wait ()			---> one entry
bye bye parent 							---> no entry
*/
