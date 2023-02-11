//TCP Server side code
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<strings.h>

#define maxline 4096
#define LISTENQ 5
#include "sum.h"

void str_echo(int);

long isprime(long n)
{
    long i;
    // Corner case
    if (n <= 1)
        return 0;
 
    // Check from 2 to n-1
    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
 
    return 1;
}
/* code for str_echo function   */
void str_echo(int sockfd)
{
	ssize_t n;
	struct args args;
	struct result result;
	char  line[maxline];
	printf("Connected by TCP...\n\n");
	
	for(;;)
	{
		n=read(sockfd,&args,sizeof(args));
		if(n==0)
			return;
		printf("the  values received from client are %ld %ld\n",args.arg1,args.arg2);
		
		result.sum_result=args.arg1 + args.arg2;
        result.multiply_result = (args.arg1 * args.arg2);
        result.division_result = (args.arg1 / args.arg2);
        result.subtract_result = (args.arg1 - args.arg2);
        result.division_result = (args.arg1 / args.arg2);
        result.modulo_result = (args.arg1) % (args.arg2);

        result.isprime_arg2 = isprime(args.arg2);
        result.isprime_arg1 = isprime(args.arg1);

		// printf("the value returned by server is %ld\n ",result.sum);
		write(sockfd,&result,sizeof(result));
	}

}

int main(int argc,char **argv)
{
	int listenfd,connfd,bd;
	pid_t childpid;
	struct sockaddr_in servaddr;
	char buff[maxline];
	time_t ticks;
	if(( listenfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("error");
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(4500);
	
	if((bd=bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))<0)
	{
		printf("\nbind error");
		exit(0);
	}
	
	listen(listenfd,LISTENQ);
	for(;;)
	{
		printf("Server is listening....\n");
		connfd=accept(listenfd,(struct sockaddr*)NULL,NULL);
		if((childpid=fork())==0)
		{
			close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		close(connfd);
	}
}