#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<poll.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define size 1024
int main(int argc,char **argv)
{
	//mkfifo("p2",0666);
	int fd=open("p2",O_RDWR);
	while(1)
	{
		int n;
		scanf("%d",&n);
		write(fd,argv[1],strlen(argv[1]));
		scanf("%d",&n);
		write(fd,argv[2],strlen(argv[2]));
		mkfifo(argv[2],0666);
		int fid=open(argv[2],O_RDWR);
		char buf[100]="client sending\n";
		write(fid,buf,strlen(buf));
	}
}
