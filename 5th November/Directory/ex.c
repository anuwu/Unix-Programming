#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	if (argc != 4)
	{
		printf ("Enter correct number of arguments!\n") ;
		return 1 ;
	}

	char curr[256] , pd[256],  pf1[256], pf2[256] , sent[256] ;
	char buf[11] ;
	char ch ;
	int fd1, fd2 , nbread, nbwrite ;

	getcwd (curr, 256) ;
	strcpy (pd, curr) ;
	strcat (pd, "/") ;
	strcat (pd , argv[1]) ;

	mkdir (pd, 0777) ;
	chdir (pd) ;

	strcpy (pf1, pd) ;
	strcpy (pf2, pd) ;
	strcat (pf1 , "/") ;
	strcat (pf2 , "/") ;
	strcat (pf1 , argv[2]) ;
	strcat (pf2, argv[3]) ;

	fd1 = open (pf1 , O_WRONLY | O_CREAT , 0777) ;
	printf ("Enter the sentence you want to enter\n") ;
	scanf("%[^\n]%*c", sent);  ;
	
	printf ("%d" , strlen(sent)) ;
	write (fd1 , sent , strlen(sent)) ;
	close (fd1) ;
	fd1 = open (pf1 , O_RDONLY) ;

	fd2 = open (pf2 , O_WRONLY | O_CREAT , 0777) ;
	while ((nbread = read(fd1 , buf , 10)) > 0)
	{
		//printf ("Writing\n") ;
		nbwrite = write (fd2 , buf , nbread) ;
		if (nbwrite != nbread)
		{
			printf ("Error in writing to file\n") ;
			return 1 ;
		}
	}

	if (nbread == -1)
	{
		printf ("Error in reading file\n") ;
		return 1 ;
	}

	close (fd1) ;
	close (fd2) ;
	chdir("..") ;

	return 0 ;
}