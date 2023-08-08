#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

//void execute(char* input, char delimiter){



//}

int main(){
	char str[80] = "ls -la /tmp & pwd //";
	//char str[80] = "ayopooo";
	const char s[2] = "&";
	char *token;

	token = strtok(str, s);

	printf("token before going into conditionals:%s\n", token);
	//printf("strtok %s\n",strtok(NULL, s));
	if ( token != NULL && strtok(NULL, s) != NULL) { // -> CHECKS IF THERE ARE DELIMETERS. CHECKS TOKENED STRING AND NEXT ONE.
		
		//printf("Inside if statement\n");\
		//printf("before the while loop %s\n",token);
		//printf("calling the strtok function %s\n", strtok(NULL, s));
		while(token != NULL) {
			printf("%s\n", token); //Since i called strtok inside the if statement the internal state from the function 
			token = strtok(NULL, s);//Continues which is on 'pwd //'. Since its also modifying the original variable str. 
						//Calling token= strtok(NULL, s); will point to null because the orignal string was already destoryed.
		}	
		//printf("%s",token);
		//printf("calling original string variable%s\n", str);
	}else {
		printf("Doesn't have delimeters\n");


	}
	return 0;
}
