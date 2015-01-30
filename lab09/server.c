/**
 * Lab09 Solution File - simple client for echo server
 * @author millerc5
 * @author sadlercr
 */
 
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define DEFAULTPORT 5555   /* Default port for socket connection */
#define MAX_STRING_LEN 100 /* Maximum length of string to echo */


int server_opt_verbose;     // print diagnostics when 1


void
usage()
{
  fprintf(stderr, "Usage: server [-u] [-v] [-p <port>]\n");
  fprintf(stderr, "-u for usage\n");
  fprintf(stderr, "-v for verbose mode\n");
  fprintf(stderr, "-p for server port\n");
  exit(1);
}


void
die_with_error(char *errorMessage)
{
  perror(errorMessage);
  exit(1);
}


int
main(int argc, char *argv[])
{
  int sock;                         /* Socket  */
  unsigned short serv_port;         /* Server port */
  extern char *optarg;              /* option argument value */
  int optch;                        /* option flag */
  struct sockaddr_in serv_addr;     /* Local address */

  server_opt_verbose = 0;
  serv_port = DEFAULTPORT;

  if (argc < 2) {
    usage();
  }

  while ((optch = getopt(argc, argv, "p:uv")) != -1) {
    switch (optch) {
    case 'p':
      serv_port = atoi(optarg);
      printf("Using port %d\n", serv_port);
      break;

    case 'v':
      server_opt_verbose = 1;
      break;

    case 'u':
      usage();
      break;

    default:
      usage();
    }
  }
  

  /* TODO: Create a TCP socket - the welcome socket */

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	printf("socket() failed with error code of: %d\n", sock);
	exit(0);	
  }

  
  /* Construct local address structure */
  memset(&serv_addr, 0, sizeof(serv_addr));      /* Zero out structure */
  serv_addr.sin_family = AF_INET;                /* Internet address family */
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
  serv_addr.sin_port = htons(serv_port);         /* Local port */
  

  /* TODO: Bind to the local address */

  int result = bind(sock, (const struct sockaddr*) &serv_addr, sizeof(serv_addr));
  if( result != 0 ){
    printf("bind() failed with error code of: %d\n", result);
    exit(0);
  }


  /* TODO: Wait for incoming requests */  

  result = listen(sock, 2);
  if( result != 0 ){
    printf("listen() failed with error code of: %d\n", result);
    exit(0);
  }


  for (;;) { /* run forever */


    /* TODO: Create a client socket for an accepted connection */
    if(server_opt_verbose){
      printf("Waiting for client\n");
    }
    int size_Addr = sizeof(serv_addr);
    int localSock = accept(sock, (struct sockaddr*)  &serv_addr, &size_Addr);
    if(server_opt_verbose){
      printf("Accepting Connection from client\n");
    }


    /* TODO: While the client sends data:
     *        - receive the string to echo 
     *        - send the data back
     */
    while(1)
    {
        char received_string[MAX_STRING_LEN];
	int i = 0;
	for(; i < MAX_STRING_LEN; i++) received_string[i] = 0;
        socklen_t serverAddrLen = sizeof(&serv_addr);
        if(server_opt_verbose){
          printf("Waiting on packet from client\n");
        }
        int len = recv(localSock, &received_string, sizeof(received_string), 0);
        if(server_opt_verbose){
          printf("Recived packet from client\n");
          printf("int len = %d\n", len);
        }        
	if (  len <= 0){
	    
            break;
	
        }
    
        fprintf(stdout, "Receing string: %s\nNumber of characters received: %d\n", received_string, len);
        
        if(server_opt_verbose){
          printf("Sending packet back to client");
        }
        send(localSock, &received_string, len, 0);

    }












    /* TODO: Close the socket for the client */
    if(server_opt_verbose){
      printf("Closing Connection from client\n");
    }
	close(localSock);
  }


  /* TODO: Close the welcome socket */
  if(server_opt_verbose) {
    printf("Closing server socket\n");
  }
  close(sock);
}
