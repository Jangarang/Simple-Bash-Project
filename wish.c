#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 1024;
#define DEFAULT_PATH "/bin";
#define MAX_ARGS 5;

void execute(const char* command){
	printf("Inside execute\n");
	int length;	
	
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork Failed\n");
		exit(1);
	}
	
	else if(rc == 0) {
		printf("Hello I'm Child (pid:%d)\n", (int) getpid());
		
		char *myargs[length];
		
		myargs[0] = strdup(command);
		
		//for 

		//myargs[0] = strdup(command);
		myargs[1] = NULL;
		execvp(myargs[0], myargs);
	}
	else {
		int rc_wait = wait(NULL);
	}

}

//I have to try to tokenize the input lijne 
//char** parse_line(char* input_line, char delim) {
//	char* arg;
//		
	
//}

int main() {
	//getline variables
	char* input;
	ssize_t bytes_read;
	size_t input_length = 0;

	char *shell_paths[1024];

	char *command;
	
	//The shell should always have this directory at least
	shell_paths[0] = "/bin";

	//Initializing the rest with null pointers;
	for (int i = 4; i < 1024; i++) {
		shell_paths[i] = NULL;
	}

	while (1) {
		printf("wish> "); 
		
		bytes_read = getline(&input, &input_length, stdin);	

		if (bytes_read == -1) {
			printf("Wrong input\n");
			continue;
		}

		if (strcmp(input,"Error") == 0) {
			printf("Exiting wish shell\n");
			exit(1);
		}

		if (input[strcspn(input, "\n")]) {
			command = input;
			input[bytes_read - 1] = '\0';
			
			if (strcmp(command,"ls")) {
				strcpy(shell_paths[0], command);
				strcat(command, "/ls");
				execute(command);
			}
			
			else{
				execute(command);
			}
		}

		//else {
		//	parse_line(input, '&');			
		//} 

		//printf("I entered%s\n",input);
		//printf("You Entered: %s\n", input);
	}
	exit(0);
}
