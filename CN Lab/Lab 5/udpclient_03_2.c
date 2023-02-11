//TCP Client side code
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<strings.h>
#include<stdio.h>

#define maxline 4096
#include "sum.h"

void str_cli(FILE *,int);

/* code for str_cli() function  */
void str_cli(FILE *fp,int sockfd)
{
	char sendline[maxline],recvline[maxline];
	struct args args;
	struct result result;

	printf("Connected by TCP...\n\n");

	while(fgets(sendline,maxline,fp)!=NULL)
	{
		if(sscanf(sendline,"%ld %ld", &args.arg1, &args.arg2) !=2)
		{
			printf("\ninvlid input:%S\n",sendline);
			continue;
		}
		
		printf("the values are %ld\t%ld\n",args.arg1,args.arg2);
		
		write(sockfd,&args,sizeof(args));
		
		if(read(sockfd,&result,sizeof(result))==0)
			printf("error");
		
		printf("\nreceived sum result from server = %ld\n",result.sum_result);
        printf("received subtract result from server = %ld\n",result.subtract_result);
        printf("received multiply result from server = %ld\n",result.multiply_result);
        printf("received division result from server = %ld\n",result.division_result);
        printf("received modulo result from server = %ld\n",result.modulo_result);
        printf("received arg1 is_prime from server = %ld\n",result.isprime_arg1);
        printf("received arg2 is_prime from server = %ld\n\n",result.isprime_arg2);
	} 
}


int main(int argc,char **argv)
{
	int sockfd,n,cn;
	char recvline[maxline+1];
	struct sockaddr_in servaddr;

	//printf("%d\n%s %s",argc,argv[1],argv[2]);

	if(argc !=2)
		printf("usage: a.out <IPaddress>");

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
		printf("\nsocket error");
	
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);		//inet_addr("127.0.0.1");
	servaddr.sin_port=htons(4500);
	
	if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
		printf("\ninet_pton error for %s", argv[1]);
	
	cn=connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
	if(cn < 0)
	{
		printf("\nconnection error\n");
		exit(0);
	}
	else
		printf("\nconnection has been estabished\n");
	
	str_cli(stdin,sockfd);
	
	exit(0);
}