/*TCP_Server*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void _bubble_sort(int list[], int n)
// {
//     int c, d, t;
 
//     for (c = 0; c < (n - 1); c++) {
//         for (d = 0; d < n - c - 1; d++) {
//             if (list[d] > list[d + 1]) {
 
//                 /* Swapping */
//                 t = list[d];
//                 list[d] = list[d + 1];
//                 list[d + 1] = t;
//             }
//         }
//     }
// }

int main()
{
	int socket_id, sess_id;
	
	struct sockaddr_in server_address, client_address;

	int rcv_arr[10], sorted_arr[10];

	server_address.sin_family = AF_INET;
	server_address.sin_port = 5050;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	int server_addr_len = sizeof(server_address);
	int client_addr_len = sizeof(client_address);

	socket_id = socket(AF_INET, SOCK_STREAM, 0);

	bind(socket_id, (struct sockaddr*) (&server_address), server_addr_len);

	listen(socket_id, 5);

	while(1)
	{
		printf("Server is up and running ...\n");
		sess_id = accept(socket_id, (struct sockaddr*)(&client_address),(socklen_t *) &client_addr_len);
		
		recv(sess_id, &rcv_arr, 10*sizeof(int), 0);
		
		// _bubbleSort(rcv_arr,10);


		int c, d, t, n=10;
 
	    for (c = 0; c < (n - 1); c++) {
	        for (d = 0; d < n - c - 1; d++) {
	            if (rcv_arr[d] > rcv_arr[d + 1]) {
	 
	                /* Swapping */
	                t = rcv_arr[d];
	                rcv_arr[d] = rcv_arr[d + 1];
	                rcv_arr[d + 1] = t;
	            }
	        }
	    }
		
		write(sess_id, &rcv_arr, 10*sizeof(int));

		close(sess_id);
	}

	return 0;

}
