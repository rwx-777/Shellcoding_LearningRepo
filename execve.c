#include <unistd.h>

int main() {
	char * const argv[] = {"cat","/etc/issue",NULL};
	execve("/bin/cat",argv, NULL);
	return 0;
}

