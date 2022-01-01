/* This is the famous synchronization problem, Dining Philosopher's Problem.
   A simple implementation of the solution is done using semaphores. */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

/* Under the semaphore.h library, there are many functions and variables of type sem_t */
sem_t room; // This is a counting semaphore
sem_t chopstick[5]; 

void * philosopher(void *); 
void eat(int);
int main() {
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&room,0,5); // Having 5 philosophers
    // int sem_init(sem_t *sem, int pshared, unsigned int value); SYNTAX
	
	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]); // Threads are created
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * philosopher(void * num) {
	int phil=*(int *)num;

	sem_wait(&room);
	printf("\nPhilosopher %d has entered room",phil);
	sem_wait(&chopstick[phil]); // The semaphore is locked taking one fork
	sem_wait(&chopstick[(phil+1)%5]); //Other fork is taken
    //this philosopher is about to eat so others cannot barge in except for another where the forks are free.

	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil);

	sem_post(&chopstick[(phil+1)%5]);
	sem_post(&chopstick[phil]);
	sem_post(&room);
}

void eat(int phil) {
	printf("\nPhilosopher %d is eating",phil);
}

/* Moral of the story, carry your own resources, do one task at a time and don’t use others food items just like that. */