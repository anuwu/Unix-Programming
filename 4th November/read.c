#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	char buff[11] ;
	int fd, rd ;

	fd = open ("boh.txt" , O_RDONLY) ;
	if (fd < 0)
	{
		printf ("Error opening file") ;
		exit (0) ;
	}

	int i = 1 ;
	while ((rd = read (fd , buff , 10)) == 10)
	{
		printf ("%d %d %s\n" , i, rd, buff) ;
		i++ ;
	}

	printf ("%d %d %s\n" , i , rd, buff) ;
	printf ("%d\n" , (int)read(fd,buff,10)) ;
	

	return 0 ;
}

/*
1 10 This is a 
2 10 test sente
3 10 nce. Test 
4 4 it!
 Test 
0
*/

/*
1 10 This is a 
2 10 test sente
3 10 nce. Testa
4 6 llah.
esta
0
*/

/*
Explanation -
buf = nce. Testa\0 ---> 10 bytes
buf = llah.EOF ----> 6 bytes

Now, it rewrites the first 6 bytes of buf and does not flush the rest.
Thus, esta\0 remains. And EOF is interpreted as new line while printing.
*/