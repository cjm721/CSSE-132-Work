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


int client_opt_verbose;     // print diagnostics when 1


/* usage - print description of command arguments */
void 
usage()
{
  fprintf(stderr, "Usage: client [-u] [-v] -h <server> [-p <port>]\n");
  fprintf(stderr, "-u for usage\n");
  fprintf(stderr, "-v for verbose mode\n");
  fprintf(stderr, "-h for server name\n");
  fprintf(stderr, "-p for server port\n");
  exit(1);
}


void
die_with_error(char *error_message)
{
  perror(error_message);
  exit(1);
}


/* resolve_name - convert a host name to an IP address */
unsigned long 
resolve_name (char name[])
{
  struct hostent *host;

  if ((host=gethostbyname(name)) == NULL) {
    fprintf(stderr, "gethostbyname() failed");
    exit(1);
  }

  return *((unsigned long *)host->h_addr_list[0]);
}


int
main(int argc, char *argv[])
{
  int sock;                         /* Socket  */
  unsigned short serv_port;         /* Server port */
  extern char *optarg;              /* option argument value */
  struct sockaddr_in serv_addr;     /* Server address */
  char *serv_name;                  /* Server host name */

  int ch;

  client_opt_verbose = 0;
  serv_port = DEFAULTPORT;

  /* Parse command line arguments */
  if (argc < 2) {
    usage();
  }

  while ((ch=getopt(argc, argv, "h:p:uv")) != -1) {
    switch (ch) {
    case 'h':
      serv_name = optarg;
      printf("Using server %s\n", serv_name);
      break;

    case 'p':
      serv_port = atoi(optarg);
      printf("Using port %d\n", serv_port);
      break;

    case 'v':
      client_opt_verbose = 1;
      break;
      
    case 'u':
      usage();
      break;
      
    default:
      usage();
      break;
      
    }
  }


  /* TODO: Create a TCP socket */

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	printf("socket() failed with error code of: %d\n", sock);
	exit(0);	
  }

  /* Construct local address structure */
  memset(&serv_addr, 0, sizeof(serv_addr));       /* Zero out structure */
  serv_addr.sin_family = AF_INET;                 /* Internet address family */
  serv_addr.sin_addr.s_addr = resolve_name(serv_name); /* Server address */
  serv_addr.sin_port = htons(serv_port);          /* Local port */
  
  if (client_opt_verbose > 0) {
    printf("Handling client %s\n", inet_ntoa(serv_addr.sin_addr));
  }


  /* TODO: Connect to server socket */
  //Take returned status code and exit if not sucessfull
  int failed = connect(sock, (const struct sockaddr*) &serv_addr, sizeof(serv_addr));
  if(failed != 0){
    printf("connect() failed with code: %d\n", failed);
    exit(0);
  }


  for (;;) { /* run until user enters "." to quit. */
		char input_string[MAX_STRING_LEN];
    char received_string[MAX_STRING_LEN];
    int received_bytes = 0;
    
    /* Prompt user for string to echo and read in the string.
     *  String may have spaces.
     */
    printf("\n\nEnter the string(\".\" to quit):");
    fgets(input_string, MAX_STRING_LEN, stdin);
		input_string[strlen(input_string)-1] = '\0';
    if (input_string[0] == '.') {
      if (client_opt_verbose > 0) {
        fprintf(stderr, " Quitting ....\n");
		  }
		  break;
    }

		if (client_opt_verbose > 0) {
			fprintf(stderr, " The string to send is %s ....\n", input_string);
    }


    /* TODO: Send string to server */
    int returned = sendto(sock, &input_string, strlen(input_string), 0, 
		 (const struct sockaddr*) &serv_addr, sizeof(&serv_addr));
    if( returned <= 0) {
	printf("Sendto failed with code of: %d\n", returned);
        exit(0);
    }

    /* TODO: Block until message received from the server */
    
    socklen_t serverAddrLen = sizeof(&serv_addr);

    size_t len;
    if ((len = recvfrom(sock, &received_string, sizeof(received_string), 0,
	    (struct sockaddr*)&serv_addr, &serverAddrLen)) < 0){
	printf("recvfrom() failed with code of: %d\n", (int) len);
	exit(0);
    }




    /* Print the received string. */
    fprintf(stdout, "%s", received_string);
    int j = 0;
    for(; j < MAX_STRING_LEN; j++) received_string[j] = 0;
  }


  /* TODO: Close socket */
  close(sock);
  return 0;
}
