#include <unistd.h>
#include <stdio.h>

int main ()
{
	printf ("HELLO WORLD\n") ;
	execl ("/bin/echo" , "/bin/echo", "PRINT", "UT", NULL) ;
	return 0 ;
}