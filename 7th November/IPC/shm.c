#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <error.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main ()
{
	key_t key = ftok("golani",65) ;
	int shmid = shmget(key,1024,0666|IPC_CREAT) ;
	

	if (fork())		//Parent is reader.
	{
		char *str = (char *) shmat (shmid, (void*)0 ,0) ;
		printf ("%d\n" , str) ;
		printf ("Parent is waiting before reading...\n") ;
		wait(NULL) ;

		printf ("Reader data : %s\n" , str) ;
			shmdt(str);
			shmctl (shmid, IPC_RMID, NULL) ;

	}
	else			//Child is writer
	{
		sleep(2) ;

		char *str = (char *) shmat (shmid, (void*)0 ,0) ;
		char ch ;
		printf ("%d\n" , str) ;
		printf ("Enter the string : ") ;
		scanf ("%s" , str) ;
		scanf ("%c" , &ch) ;
		printf ("The string entered is : %s\n" , str) ;

		exit(0) ;
	}

	return 0 ;
}