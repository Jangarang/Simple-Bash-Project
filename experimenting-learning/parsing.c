#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

void parse_initial(char* input, char** commands) {
	char* token;
	char *tokens[MAX_TOKENS];
	int num_tokens = 0;
	

	token = strtok(input,"&");
	tokens[num_tokens] = token;
	while (token != NULL){
		tokens[num_tokens++] = token;
		token = strtok(NULL, "&");
	}

	
	// Debugging purposes
	int array_len;
	array_len = sizeof(tokens) / sizeof(tokens[0]);
	for (int i = 0; i < num_tokens; i++) {
		
		printf("Array of tokens: %s\n", tokens[i]);
	}
	
	// Parse the line into a nested list. Return ? 
	
}



int main(){
	char input [] = "cat input.txt & get \"keyword\" & sort > output.txt";
	char* commands;
	//int number_commands;
	
	parse_initial(input,&commands);

	//After function parse again for > character



	

}
