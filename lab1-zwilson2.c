//import all libraries needed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//instantiate all arrays/variables, and declare all functions
char input[200];	
char *token;
char *token2;
char *token3;
char *token4;
char *number;
char inputBackup[200];
int digitsOnly(const char *s);
int binaryOnly(char* number);
int d2b(char* number);
void b2d(char* number);
void ucd(char* number);
void gcd(char* decimal);


//begin program
int main(){

//use whileloop label to jump to beginning when error is found
whileLoop:
//while loop will continue until exit command	
	while (strcmp(input, "exit") != 0){	
		printf("zwilson2$ ");	//initial prompt
		scanf("%s",input);	//takes input and saves to array
		strcpy(inputBackup,input);	//copies input to backup
		token = strtok(input,"(");	//parses input for first command
		number = strtok(NULL,")");	//next 4 will parse for diff inputs
		token2 = strtok(number,",");
		token3 = strtok(NULL,",");
		token4 = strtok(NULL,",");		
	
		//check for 1 of 5 commands, if none found then report error
		if(strcmp(token,"exit") !=0 && strcmp(token,"d2b") !=0 && strcmp(token,"b2d") !=0 && strcmp(token,"ucd") !=0 && strcmp(token,"gcd") !=0){
			printf("[Error] Please enter the command correctly!\n");
			goto whileLoop;
		}
		//check for exit command and exit
		if(strcmp(token,"exit") == 0){
			return 0;
		}
		//if nothing is entered afer command, error	
		if(number == NULL){
			printf("[Error] Please enter input number into parenthesis after command!\n");
			goto whileLoop;
		}
		//error if there is no closing parenthesis
		if(inputBackup[strlen(inputBackup)-1] != ')'){
			printf("[Error] Please enter your input correctly!\n");
			goto whileLoop;
		}
		//error if there are anything but integers in input
		if(!digitsOnly(token2)){
			printf("[Error] You must only enter integers in the parenthesis!\n");
			goto whileLoop;
		}
		//following 2 if statements check again for anything but integers
		if(token3 != NULL && !digitsOnly(token3)){
			printf("[Error] You must only enter integers in the parenthesis!\n");
			goto whileLoop;
		}	
		if(token4 != NULL && !digitsOnly(token4)){
			printf("[Error] You must only enter integers in the parenthesis!\n");
			goto whileLoop;
		}
		//once d2b command perform if statement
		if(strcmp(token,"d2b") == 0){
			//each statment checks how many inputs there are and performs d2b function
			if(token3==NULL && token4 == NULL){
				printf("%i\n",d2b(token2));
			}
			if(token3!=NULL && token4 == NULL){  
				printf("%i\n",d2b(token2));
				printf("%i\n",d2b(token3));
			}
			if(token3 != NULL && token4 != NULL){
				printf("%i\n",d2b(token2));
				printf("%i\n",d2b(token3));
				printf("%i\n",d2b(token4));
			}

		}
		//if statement for b2d command
		if(strcmp(token, "b2d") == 0){
			//checks to confirm input is binary only
			if(!binaryOnly(token2)){
				printf("[Error] You must only enter 1's or 0's in the parenthesis!\n");
				goto whileLoop;
			}
			//if statements to confirm how many inputs there are and perform b2d function
			if(token3 != NULL && !binaryOnly(token3)){
				printf("[Error] You must only enter 1's or 0's in the parenthesis!\n");
				goto whileLoop;
			}	
			if(token4 != NULL && !binaryOnly(token4)){
				printf("[Error] You must only enter 1's or 0's in the parenthesis!\n");
				goto whileLoop;
			}
			
		
			if(token3==NULL && token4 == NULL){
				b2d(token2);
			}
			if(token3!=NULL && token4 == NULL){  
				b2d(token2);
				b2d(token3);
			}
			if(token3 != NULL && token4 != NULL){
				b2d(token2);
				b2d(token3);
				b2d(token4);
			}
		}
		//ucd command statement, will check for number of inputs and complete ucd function as necessary
		if(strcmp(token, "ucd") == 0){
			if(token3==NULL && token4 == NULL){
				ucd(token2);
			}
			if(token3!=NULL && token4 == NULL){  
				ucd(token2);
				ucd(token3);
			}
			if(token3 != NULL && token4 != NULL){
				ucd(token2);
				ucd(token3);
				ucd(token4);
			}

		}
		//gcd command will check for number of inputs and complete gcd function as necessary
		if(strcmp(token, "gcd") == 0){
			if(token3==NULL && token4 == NULL){
				gcd(token2);
			}
			if(token3!=NULL && token4 == NULL){  
				gcd(token2);
				gcd(token3);
			}
			if(token3 != NULL && token4 != NULL){
				gcd(token2);
				gcd(token3);
				gcd(token4);
			}
		}
	}
	//end program
	return 0;
}
//checks for only digits in input
int digitsOnly(const char *s){
	while (*s){//check each digit with isdigit function, return true if all digits are 0-9
		if(isdigit(*s++) == 0) return 0;
	}
	return 1;
}
//checks for only binary input
int binaryOnly(char* number){
	int n = atoi(number);
	for(; n !=0; n/=10){
		int mod = n % 10;
		if(0 != mod && 1 != mod){
			return 0;
		}
	return 1;
	}
}
//b2d function
void b2d(char* number){
	int num = atoi(number), binary_val, decimal_val =0, base =1, rem;
	binary_val = num;
	while(num>0){
		rem = num % 10;
		decimal_val = decimal_val + rem * base;
		num = num / 10;
		base = base * 2;
	}
	printf("%d\n",decimal_val);
}
//d2b function	
int d2b(char* number){
	int decimalnum = atoi(number);	
	int binarynum = 0;
      	int rem, temp = 1;
	while (decimalnum!=0){
		rem = decimalnum%2;
       		decimalnum = decimalnum / 2;
        	binarynum = binarynum + rem*temp;
       		temp = temp * 10;
    	}
        return binarynum;
}
//ucd function
void ucd(char* number){
	int num = atoi(number), i; //for loop to print each 1 until 2nd to last in length then print 0
	for(i = num; i>0;i--){
		printf("1");
	}
	printf("0\n");
}
//gcd function
void gcd(char* decimal){
	char number[200];//initiate array to store binary
       	sprintf(number, "%d",d2b(decimal));
	char *c = number;// store binary with pointer
	char *d = c+1;//use new pointer to remove first digit
	long e = strlen(d);//record new length
	char new[200];//create new arry for final output
	int i;//initiate counter
	for(i=0; i<e; i++){//for loop will put the ucd code into array first
		new[i] = '1';
	}
		new[e] = '0';
	for(i=e+1;i<e+e+1;i++){//for loop will put binary code aside from first digit
		new[i] = number[i-e];
	}
	printf("%s\n",new);
}
