//UDP Client side code
#include "unp.h"
#include "sum.h"
void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int n=0;
    char sendline[MAXLINE], recvline[MAXLINE + 1];
    struct args args;
    struct result result;

    printf("Connected by UDP...\n\n");

    while (fgets(sendline, MAXLINE, fp) != NULL) {

        if(sscanf(sendline,"%ld %ld", &args.arg1, &args.arg2) !=2)
        {
            printf("\ninvalid input:%S\n",sendline);
            continue;
        }

        sendto(sockfd, &args, sizeof(args), 0, pservaddr, servlen);

        printf("the input numbers are %ld\t%ld\n",args.arg1,args.arg2);
        
        n = recvfrom(sockfd, &result, sizeof(result), 0, pservaddr, &servlen);
        
        //printf("n = %d, error is %d\n",n,errno);
        //printf("received message size %d\n", n);
        //result[n] = 0; /* null terminate */
        //fputs(result, stdout);

        printf("\nreceived sum result from server = %ld\n",result.sum_result);
        printf("received subtract result from server = %ld\n",result.subtract_result);
        printf("received multiply result from server = %ld\n",result.multiply_result);
        printf("received division result from server = %ld\n",result.division_result);
        printf("received modulo result from server = %ld\n",result.modulo_result);
        printf("received arg1 is_prime from server = %ld\n",result.isprime_arg1);
        printf("received arg2 is_prime from server = %ld\n\n",result.isprime_arg2);
    }
}

int main(int argc, char** argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    if (argc != 2)
        exit(0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    dg_cli(stdin, sockfd, (SA*)&servaddr, sizeof(servaddr));
    exit(0);
}