#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 1024;

void execute(const char* command){
	printf("Inside execute\n");
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork Failed\n");
		exit(1);
	}
	
	else if(rc == 0) {
		printf("Hello I'm Child (pid:%d)\n", (int) getpid());
		char *myargs[2];
		myargs[0] = strdup(command);
		myargs[1] = NULL;
		execvp(myargs[0], myargs);
	}
	else {
		int rc_wait = wait(NULL);
	}

}

//char** parse_line(char* input_line, char delim) {
//	char* arg;
//	
//}

int main() {
	//getline variables
	char* input;
	ssize_t bytes_read;
	size_t input_length = 0;

	char *path_list[1024];
	char *command;
	
	while (1) {
		printf("wish> "); 
		
		bytes_read = getline(&input, &input_length, stdin);	

		if (bytes_read == -1) {
			printf("Wrong input\n");
			continue;
		}

		input[strcspn(input, "\n")] = '\0';
		printf("I entered%s\n",input);	

		if (strcmp(input,"Error") == 0) {
			printf("Exiting wish shell\n");
			exit(1);
		}
		command = input;

		execute(command);

		//printf("You Entered: %s\n", input);

	}
	
	exit(0);
}
