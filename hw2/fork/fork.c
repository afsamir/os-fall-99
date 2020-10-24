/*
 * =====================================================================================
 *
 *       Filename:  fork.c
 *
 *    Description: #1 practical problem, hw2 
 *
 *        Version:  1.0
 *        Created:  10/24/2020 08:06:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amir Afsari
 *
 * =====================================================================================
 */


#include<stdio.h>
#include<stdlib.h>

int main(){	
	if(fork() > 0){
		printf("grandparent PID: %d\n", getpid());
	}else{
		if(fork() > 0){
			printf("parent PID: %d\n", getpid());
		}else{
			printf("child PID %d\n", getpid());
		}
	}
}


