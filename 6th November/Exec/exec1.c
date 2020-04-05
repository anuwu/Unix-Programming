#include <unistd.h>
#include <stdio.h>

int main ()
{
	char *path = "/bin/ls" ;
	char *arg1 = "-l" ;
	char *arg2 = "/home/anwesh/Desktop" ;

	char *args_v[] = {path, arg1, arg2} ;
	char *args_vp[] = {"ls", arg1, arg2} ;

	//execl (path, path, arg1, arg2, NULL) ;
	//execl ("ls", "ls", arg1, arg2, NULL) ;			//Gives no output!

	//execlp ("ls" , "ls", arg1, arg2, NULL) ;			
	//execlp (path , path, arg1, arg2, NULL) ;			//Gives same output without full path

	//execv (path, args_v) ;
	//execv ("ls" , args_vp) ;							//No output

	//execvp ("ls", args_vp) ;
	//execvp (path , args_v) ;							//Gives same output without full path

	return 0 ;
}