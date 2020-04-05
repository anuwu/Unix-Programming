#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//mkdir needs entire pathname

int main ()
{
	char curr[256] , mod[256] ;

	getcwd (curr , 256) ;
	strcpy (mod , curr) ;
	strcat (mod , "/allah") ;

	mkdir (mod , 0777) ;

	return 0 ;
}