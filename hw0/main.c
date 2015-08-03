#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <limits.h>
#include <unistd.h>

int main() {
    	struct rlimit lim;
	getrlimit(RLIMIT_STACK, &lim);
	printf("stack size: %d\n",  (int)lim.rlim_cur);
	getrlimit(RLIMIT_DATA, &lim);
   	printf("process limit: %d\n", (int)sysconf(_SC_CHILD_MAX));
	getrlimit(RLIMIT_NOFILE, &lim);
    	printf("max file descriptors: %d\n", (int)lim.rlim_cur);
}
