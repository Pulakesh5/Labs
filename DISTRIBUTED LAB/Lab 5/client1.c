#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define linesize 4096




int  main()
{
	int socket_id = socket(AF_INET, SOCK_STREAM, 0);
	int input_arr[10], sorted_arr[10];
	struct sockaddr_in server_address;

	int server_address_len = sizeof(server_address);

	server_address.sin_family = AF_INET;
	server_address.sin_port = 5050;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	int connection = connect(socket_id, (struct sockaddr*) (&server_address), (server_address_len));

	if(connection<0)
		printf("connection with server failed\n");
	else
		printf("connection has been established\n");

	for(int i=0;i<10;i++)
		input_arr[i] = rand()%100;
	
	printf("sending input array to server \nInput array:\n");
	for(int i=0;i<10;i++)
		printf("%d \t ", input_arr[i]);

	int send_rtn, recv_rtn;

	send_rtn = send(socket_id, &input_arr, 10*sizeof(int), 0);

	recv_rtn = recv(socket_id, &sorted_arr, 10*sizeof(int), 0);

	printf("\nSorted array:\n");
	for(int i=0;i<10;i++)
		printf("%d \t ",sorted_arr[i]);



}
