#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

char name[20];

void parent(){
	printf("The job is done!\n");
	}

void child(){
	printf("Enter Name : ");
	scanf("%s",name);
	printf("Your name is %s\n",name);
	}

int main(){

	for(int i=0;i<4;i++){

	pid_t pid = fork();

	if(pid==0){
	child();
	exit(0);
	}

	else{
	wait(NULL);
	parent();
	}

	}
	return EXIT_SUCCESS;
	}
