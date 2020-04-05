#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main ()
{	
	int count = 0 ;
	pid_t p1 , p2 ;

	count++ ;
	printf ("Statement 1 %d %d and count = %d\n\n" , (int)getpid() , (int)getppid(), count) ;

	p1 = fork () ;
	printf ("Statement after fork1 before count++ %d %d %d\n" , (int)getpid() , (int)getppid(), count) ;
	count++ ;
	printf ("The fork return is %d and count = %d\n\n" , (int)p1, count) ;

	count++ ;
	printf ("Statement 2 %d %d and count = %d\n\n" , (int)getpid(), (int)getppid(), count) ;

	p2 = fork () ;
	printf ("Statement after fork2 before count++ %d %d %d\n" , (int)getpid() , (int)getppid(), count) ;
	count++ ;
	printf ("The fork return is %d and count = %d\n\n" , (int)p2, count) ;

	count++ ;
	printf ("Statement 3 %d %d and count = %d\n\n" , (int)getpid() , (int)getppid(), count) ;

	return 0 ;
}

/*

fork () - Creates a new process and copies all the local variables upto that point.

Statement 1 25642 24299 and count = 1

Statement after fork1 before count++ 25642 24299 1
The fork return is 25643 and count = 2

Statement 2 25642 24299 and count = 3

Statement after fork1 before count++ 25642 24299 3
The fork return is 25644 and count = 4

Statement 3 25642 24299 and count = 5

Statement after fork1 before count++ 25643 25642 1
The fork return is 0 and count = 2

Statement 2 25643 25642 and count = 3

Statement after fork1 before count++ 25644 25642 3
The fork return is 0 and count = 4

Statement 3 25644 25642 and count = 5

Statement after fork1 before count++ 25643 1778 3
The fork return is 25645 and count = 4

Statement 3 25643 1778 and count = 5

Statement after fork1 before count++ 25645 25643 3
The fork return is 0 and count = 4

Statement 3 25645 25643 and count = 5


*/
