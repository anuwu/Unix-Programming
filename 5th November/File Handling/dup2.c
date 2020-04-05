#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	int fd = open ("two.txt" , O_RDWR | O_CREAT , 0777) ;
	//int cop = dup2 (fd , 1) ;

	printf ("TEST!") ;
	printf("%d\n" , close(fd)) ;
	printf ("%d\n", close (fd)) ;
	//close (cop) ;

	return 0 ;
}

/*
Initially the file contained ---> Dystopia!Dystopia!EOF
Then when the code was run with printf ("TEST!"), the final file had
---> TEST!pia!Dystopia!

Thus open function only overwrites from the beginning!
*/

//Closing a file handler twice produces no error!
