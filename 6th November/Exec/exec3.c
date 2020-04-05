#include <unistd.h>
#include <stdlib.h>

int main()
{	
	char *path = "/bin/bash" ;
	char *args[] = {path, "-c", "echo \"Visit $HOSTNAME:$PORT from your browser\"", NULL} ;
	char *env[] = {"HOSTNAME=www.bits.com" , "PORT=8080", NULL} ;

	execve (path , args, env) ;

	return 0 
;}