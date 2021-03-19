#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//Author- Ala Sobhan

int main(){

	int n;
	int pid;
	
	do{
	printf("Enter a positive integer:\n");
	scanf("%d", &n);
	}while(n <= 0);
	
	pid = fork();
	
	if(pid == 0){ //for child process perform the collatz conjecture to produce the sequence
	printf("Child process is working...\n");
	printf("Sequence:\n");
	printf("%d ", n);
        
        while(n != 1){
	if(n%2 == 0){ //n is even
	n = n/2;
	}
        else if(n % 2 == 1){ //n is odd 
	n = 3 * (n) + 1;
	}
	
        printf("%d ", n);
	}
        printf("\nChild process done.\n");	


	}
	else if( pid > 0){ //Parent process 
	printf("Parent is waiting for child process to complete...\n");
	wait(); //wait for the child to terminate
	printf("Parent process done.\n");
	}
	else {// pid is less than 0 as fork was unsuccessful
	printf("fork() was unsuccessful\n");
	}

}