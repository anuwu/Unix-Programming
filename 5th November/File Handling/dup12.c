#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void loop ()
{
		char ch ;

		while (1)
		{
			printf ("Press p to proceed\n") ;
			scanf ("%c" , &ch) ;
			if (ch == 'p') 
				break ;
		}
}

int main ()
{
	int fd1, fd2, fd3 
;
	char *str1 = "String 1.", *str2 = " String 2.", *str3 = " String 3." ;
	char *str4 = " String 4." ;


	if ((fd1 = open("three.txt" , O_RDONLY)) > 0)
	{
		close (fd1) ;
		link ("three.txt" , "haha.txt") ;

		loop () ;

		unlink ("haha.txt") ;

		loop() ;

		unlink("three.txt") ;

		loop () ;
	}

	if ((fd2 = open("four.txt" , O_RDONLY)) > 0)
	{
		close (fd2) ;
		unlink("four.txt") ;

		loop() ;
	}

	fd1 = open ("three.txt" , O_RDWR | O_APPEND | O_CREAT , 0777) ;
	fd2 = open ("four.txt", O_RDWR | O_APPEND | O_CREAT , 0777) ; 

	write (fd1 , str1, strlen(str1)) ;
	write (fd2, str2, strlen(str2)) ;

	fd3 = dup2 (fd1, fd2) ;
	printf ("The FD values are %d, %d, %d\n" , fd1, fd2, fd3) ;

	/* fd1 = 3 --> three.txt
	   fd2 = 4 --> three.txt
	   fd3 = 4 --> three.txt
	*/

	write (fd3, str3, strlen(str3)) ;		//number 4, writes to three.txt
	write (fd2 , str4, strlen(str4)) ;

	//return 0 ;


	close (fd1) ;		//number 3, linked to three.txt
	loop() ;
	unlink ("three.txt") ;


	int fd4 = open ("four.txt" , O_RDWR | O_APPEND) ;
	unlink ("four.txt") ;	
	/*The intended effect of seeing "four.txt" in directory 
	even after linking will not be achieved because there 
	is actually no file descriptor linked to "four.txt" 

	However, after introducing fd4, the intended effect IS STILL NOT SEEN!
	*/


	loop () ;
	close (fd4) ;

	return 0 ;
}

/*
Let's say that close (1) was excecuted, then if printf is run, no output is produced!
*/