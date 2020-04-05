#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

//opendir needs full pathname

int main ()
{
	char curr[256] ;
	DIR *ds ;
	struct dirent *dir ;
	struct stat *filestat ;


	filestat = (struct stat *) malloc (sizeof(struct stat)) ;
	getcwd (curr, 256) ;
	ds = opendir(curr) ;
	if (ds == NULL)
	{
		printf ("Error in opening directory\n") ;
		return 1 ;
	}

	while ((dir = readdir(ds)) != NULL)
	{
		stat (dir->d_name , filestat) ;
		printf ("%d %s\n" , filestat->st_mode , dir->d_name) ;
	}

	if (closedir(ds) != 0)
	{
		printf ("error in closing\n") ;
		return 1 ;
	}

	return 0 ;
}