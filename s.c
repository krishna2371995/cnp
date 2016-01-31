#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<poll.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define size 1024
typedef struct pollfd plfd;
int main(int argc,char **argv)
{
	mkfifo("p2",0666);
	int fid=open("p2",O_RDWR);
	char *buf=new char[size];
	printf("mss\n");
//	plfd *pfd=new plfd;
//	pfd[0].fd=fid;
//	pfd[0].events=POLLIN;
//	int i=1;
	while(1)
	{
//		int no=poll(pfd,1,0);
//		if(no>0)
//		{
//			if(pfd[0].revents&POLLIN)
//			{
					while(read(fid,buf,size)<0){};
					char *pn=new char[size];
					strcpy(pn,buf);
					strcat(pn," ");
					printf("%s\n",pn);
					bzero(buf,size);
					while(read(fid,buf,size)<0){};
					strcat(pn,buf);
					printf("%s\n",pn);						
					int fd=open("./file.txt",O_RDWR);
					FILE *f=fdopen(fd,"r");
					f=popen(pn,"r");
					char *buf2=new char[size];
					while(read(fd,buf2,size)<0){};
					printf("%s",buf2);
					fclose(f);	
//				}
//			}
		//}
	}
}
