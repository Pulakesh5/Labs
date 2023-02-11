//UDP Server side code

#include "unp.h"
#include "sum.h"


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

void dg_echo(int sockfd, SA* pcliaddr, socklen_t clilen)
{
    // int n;
    // socklen_t len;
    // char mesg[MAXLINE];
    // for (; ; ) {
    //     len = clilen;
    //     n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
    //     sendto(sockfd, mesg, n, 0, pcliaddr, len);
    // }
    ssize_t n;
    struct args args;
    socklen_t len;
    struct result result;
    printf("Connected by UDP...\n\n");
    for(;;)
    {
        //n=read(sockfd,&args,sizeof(args));
        len = clilen;
        n = recvfrom(sockfd, &args, sizeof(args), 0, pcliaddr, &len);
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
        


        sendto(sockfd, &result, sizeof(result), 0, pcliaddr, len);

        //printf("the value returned by server is %ld\n ",result.sum);
        //write(sockfd,&result,sizeof(result));
        
    }
}
int main(int argc, char** argv)
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
    dg_echo(sockfd, (SA*)&cliaddr, sizeof(cliaddr));
}