#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void execute(char* input) {
	char* args[64];
	int i = 0;
	
	args[i] = strtok(input, " ");
	i = i + 1;
	while ( (args[i] = strtok(NULL, " ")) != NULL){
		i = i + 1;
	}

	printf("Before for loop\n");
	
	printf("%s\n",args[0]);
	//for (int x = 0; x < i; x++) {
	//	printf("%s\n", args[x]);	
	//} 

}


int main() {
	char str[50] = "ls -la /tmp & pwd //";
	const char s[2] = "&";
	char* token;	
	
	token = strtok(str, s);

	while ( token != NULL) {
		printf("Parsing command: %s\n", token);
		execute(token);
	}

	return 0;
}
