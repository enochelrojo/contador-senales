#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void handler_signal(int);

int cantidad_usr1 = 0;
int cantidad_usr2 = 0; 

int main(int argc, char** argv) {
	printf("Abra otra terminal y envíe señales SIGUSR1 ó SIGUSR2 al PID %d y vea lo que sucede\n", getpid());	
	
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	signal(SIGTERM, handler_signal);

	while(1); 
	
	return 0;
}

void handler_signal(int id_senal) {
	switch (id_senal) {
		case SIGUSR1:
			cantidad_usr1++;
			break;
		case SIGUSR2:
			cantidad_usr2++;
			break;
		case SIGTERM:
			printf("Se recibió SIGTERM. En total hay %d SIGUSR1 y %d SIGUSR2.\n", cantidad_usr1, cantidad_usr2);
			exit(EXIT_SUCCESS);
		default: break;
	}
}
