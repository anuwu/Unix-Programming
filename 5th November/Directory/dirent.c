#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main (int argc, char *argv[])
{
	if (argc > 2)
	{
		printf ("Please enter current number of arguments. Run the code again!") ;
		exit (0) ;
	}

	int count = 0 ;
	DIR *ds ;
	struct dirent *dir ;	
	struct stat filestat ;	//Used to contain every directory entry
	char curr[256] , path[256] ;

	getcwd(curr, 256) ;
	strcpy (path, curr) ;
	if (argc == 2)
	{
		strcat (path , "/") ;
		strcat (path, argv[1]) ;
	}

	ds = opendir (path) ;
	if (ds == NULL)
		printf ("Directory %s is not opened" , argv[1]) ;
	else
		printf ("Directory opened!") ;

	printf ("The list of files and directories are - \n") ;
	while ((dir = readdir(ds)) != NULL)
	{
		if (dir->d_type == DT_REG)
		{
			count++ ;
			stat(dir->d_name , &filestat) ;		//To obtain stats of file
			printf ("File %s %d\n" ,dir->d_name, filestat.st_mode) ;
		}
		else if (dir->d_type == DT_DIR)
			printf ("Folder %s\n", dir->d_name) ;
	}

	if (closedir(ds) == 0)
		printf ("Successfully closed\n") ;
	else
		printf ("DEAD!\n") ;


	printf ("Number of files in the folder = %d\n" , count)

	return 0 ;
}