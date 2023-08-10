#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void execute(char* input) {
	char* save_ptrexe;
	char* args[10];
	int args_count = 0;
	
	args[args_count] = strtok_r(input," ",&save_ptrexe);
	args_count = args_count + 1;
	
	while( (args[args_count] = strtok_r(NULL, " ", &save_ptrexe)) != NULL) {
		args_count = args_count + 1;		
	}
	
	/*for( int i = 0; i < args_count; i++){
		printf("%s\n",args[i]);
	}*/
	
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork() Failed\n");
	
	}else if (rc == 0) {
		execvp(args[0],args);
	
	}else {
		wait(NULL);
	
	}
}

int main() {
	char str[50] = "ls -la /tmp & pwd //";
	char* token;

	token = strtok(str,  "&");

	while (token != NULL) {
		printf("Parsing command: %s\n", token);
		execute(token);
		token = strtok(NULL, "&");
	}

	return 0;
}
