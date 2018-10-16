#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void handler_usr1();
void handler_usr2();
void handler_sigterm();

int cantidad_usr1 = 0;
int cantidad_usr2 = 0; 

int main(int argc, char** argv) {
	printf("Abra otra terminal y envíe señales SIGUSR1 ó SIGUSR2 al PID %d y vea lo que sucede\n", getpid());	
	
	signal(SIGUSR1, handler_usr1);
	signal(SIGUSR2, handler_usr2);
	signal(SIGTERM, handler_sigterm);

	while(1); 
	
	return 0;
}

void handler_usr1() {
	printf("Se recibió SIGUSR1\n");
	cantidad_usr1++;
}

void handler_usr2() {
	printf("Se recibió SIGUSR2\n");
	cantidad_usr2++;
}

void handler_sigterm() {
	printf("Se recibió SIGTERM. En total hay %d SIGUSR1 y %d SIGUSR2.\n", cantidad_usr1, cantidad_usr2);
	exit(EXIT_SUCCESS);
}
