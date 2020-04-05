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

int main()
{
key_t key;
int id1, id2 ;
key = ftok("progfile", 65);
/*
if (key == -1)
{
	printf ("ftok\n") ;
	exit(1) ;
}
*/
id1 = msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);
id2 =  msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);
printf ("%d %d\n",id1, id2);
if (id1 == -1)
{
	printf("msgget") ;
	exit(1);
}

}