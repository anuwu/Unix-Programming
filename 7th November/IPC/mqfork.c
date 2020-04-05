// structure for message queue
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

struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} ;

int main()
{
	key_t key; 
	int msgid;

	char path[100] ;
	getcwd (path, 100) ;
	strcat (path , "/golani") ;

	key = ftok(path, 100);
	msgid = msgget(key, 0666 | IPC_CREAT);
	printf ("%d %d\n" , key, msgid);


	if (fork())
	{
		struct mesg_buffer m1, m2 ;

		printf ("Send message 1 : ") ;
		scanf ("%[^\n]%*c", m1.mesg_text) ;
		m1.mesg_type = 2 ;

		printf ("Send message 2 : ") ;
		scanf ("%[^\n]%*c", m2.mesg_text) ;
		m2.mesg_type = 1 ;

		msgsnd (msgid, &m1, sizeof(struct mesg_buffer), 0) ;
		msgsnd (msgid, &m2, sizeof(struct mesg_buffer), 0) ;

		printf ("Waiting for child to receive\n") ;
		wait (NULL) ;
		printf ("Deleting the queue\n") ;
		msgctl (msgid, IPC_RMID, NULL) ;

	}
	else
	{
		sleep(5) ;

		struct mesg_buffer mr1, mr2 ;

		msgrcv (msgid, &mr1, sizeof(struct mesg_buffer), -5, 0) ;
		printf ("Received message type = %d and msg = %s\n" , mr1.mesg_type, mr1.mesg_text) ;

		msgrcv (msgid, &mr2, sizeof(struct mesg_buffer), -5, 0) ;
		printf ("Received message type = %d and msg = %s\n" , mr2.mesg_type, mr2.mesg_text) ;

		exit(0) ;
	}
	

	return 0 ;
}