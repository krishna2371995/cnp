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
	char *buf=new char[size];
	//mkfifo(argv[1],0666);
	printf("%s\n",argv[1]);
	int fd=open(argv[1],O_RDWR);
	while(1)
	{
		while(read(fd,buf,size)<0){};
		printf("%s",buf);
		printf("server reads\n");
	}
}
