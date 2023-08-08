#include <stdio.h>
#include <string.h>

void execute(char* input) {
    	char* args[64];
	char copy[50];
	int args_len = 0;
		
	strcpy(copy,input);
	//printf("%s",copy);
    	args[args_len] = strtok(copy, " ");
    	args_len = args_len + 1;
    	while ((args[args_len] = strtok(NULL, " ")) != NULL) {
        	args_len = args_len + 1;
    	}

    	//printf("Before for loop\n");
	printf("Checking input parameter %s:\n", input);
	printf("Checking copy of input %s:\n", copy); 	
    	for (int i = 0; i < args_len; i++) {
        	printf("%s\n", args[i]);
    	}
}

int main() {
    	char str[50] = "ls -la /tmp & pwd //";
   	char* token;
	char mcopy[50];
	strcpy(mcopy, str);
    	token = strtok(mcopy, "&");

    	while (token != NULL) {
        	printf("Parsing command: %s\n", token);
        	execute(token);
		printf("token main while %s\n",token);
        	token = strtok(NULL, "&");
		printf("Token main while after %s:\n",token);
    	}

    	return 0;
}
