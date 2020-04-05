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
} m1, m2 , mr1, mr2 ;

int main()
{
	key_t key; 
	int msgid;

	key = ftok("golani", 100);
	msgid = msgget(key, 0666 | IPC_CREAT);
	printf ("%d %d\n" , key, msgid);

	/*
	m1.mesg_type = 1;
	printf("Write Data : ");
	scanf ("%[^\n]%*c", m1.mesg_text) ;

	msgsnd(msgid, &m1, sizeof(m1), 0); // msgsnd to send message
	printf("Data send is : %s \n", m1.mesg_text);

	m2.mesg_type = 2;
	printf("Write Data : ");
	scanf ("%[^\n]%*c", m2.mesg_text) ;

	msgsnd(msgid, &m2, sizeof(m2), 0); // msgsnd to send message
	printf("Data send is : %s \n", m2.mesg_text);
	*/

	//-------------------------------------------------------------------------

	

	msgrcv(msgid, &mr1, sizeof(struct mesg_buffer), 1, 0) ;
	printf ("Received message type = %d, text = %s\n" , mr1.mesg_type, mr1.mesg_text) ;

	msgrcv(msgid, &mr2, sizeof(struct mesg_buffer), 2, 0) ;
	printf ("Received message type = %d, text = %s\n" , mr2.mesg_type, mr2.mesg_text) ;

	msgctl (msgid, IPC_RMID, NULL) ;
	

	return 0; // display the message
}