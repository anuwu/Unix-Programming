#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main ()
{	
	pid_t p1 , p2 ;

	printf ("Statement 1 %d %d and count = %d\n" , (int)getpid() , (int)getppid(), count) ;

	p1 = fork () ;
	printf ("The fork return is %d and count = %d\n" , (int)p1, count) ;

	printf ("Statement 2 %d %d and count = %d\n" , (int)getpid(), (int)getppid(), count) ;

	p2 = fork () ;
	printf ("The fork return is %d and count = %d\n" , (int)p2, count) ;

	printf ("Statement 3 %d %d and count = %d\n" , (int)getpid() , (int)getppid(), count) ;

	return 0 ;
}

/*

Without counts

0 ---> 24299
1 ---> 25111
2 ---> 25112
3 ---> 25113
4 ---> 25114

Statement 1 25111 24299					p1.s1
The fork return is 25112				p1.f1 ---> Creates p2
Statement 2 25111 24299					p1.s2
The fork return is 25113				p1.f2 ---> Creates p3
Statement 3 25111 24299					p1.s3
The fork return is 0					p2.f1 ---> Doesn't screate
Statement 2 25112 25111					p2.s2
The fork return is 0					p3.f2 ---> Doesn't create
Statement 3 25113 25111					p3.s3
The fork return is 25114				p2.f2 ---> Creates p4
Statement 3 25112 1778					p2.s3
The fork return is 0					p4.f2 ---> Doesn't create
Statement 3 25114 25112					p4.s3

Expected order of execution - (in my notebook)

p1.s1
p1.f1 ---> Creates p2
p1.s2
p1.f2 ---> Creates p3
p1.s3
p2.f1 ---> Doesn't create
p2.s2
p2.f2 ---> Creates p4
p2.s3
p3.f2 ---> Doesn't create
p3.s3
p4.f2 ---> Doesn't create
p4.s3

*/
