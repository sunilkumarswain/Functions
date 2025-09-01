#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// 1. Simulated GPIO Register (memory-mapped I/O)
volatile int GPIO_STATUS = 0;

// 2. Volatile variable modified by an interrupt (signal handler)
volatile int interruptFlag = 0;

// 3. Shared volatile buffer for threads
volatile int sharedCounter = 0;
pthread_mutex_t lock;

// ISR Simulation (Signal Handler)
void signal_handler(int signum) {
    interruptFlag = 1;  // Interrupt sets flag
    printf("[ISR] Interrupt received: Flag set to 1\n");
}

// Thread 1: Increments sharedCounter
void* thread_func1(void* arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&lock);
        sharedCounter++;
        printf("[Thread 1] Counter = %d\n", sharedCounter);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

// Thread 2: Reads sharedCounter
void* thread_func2(void* arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&lock);
        printf("[Thread 2] Observed Counter = %d\n", sharedCounter);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int funcExer5() {
    signal(SIGINT, signal_handler); // Register signal (Ctrl+C) as simulated interrupt

    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    // 1. Simulate reading GPIO register
    printf("[Main] Reading GPIO_STATUS register...\n");
    GPIO_STATUS = 1; // Simulate hardware setting status
    if (GPIO_STATUS) {
        printf("[Main] GPIO_STATUS is HIGH (1)\n");
    }

    // 2. Wait for interrupt
    printf("[Main] Waiting for interrupt (press Ctrl+C)...\n");
    while (!interruptFlag); // Busy wait for simulation only

    // 3. Start threads sharing a volatile variable
    pthread_create(&t1, NULL, thread_func1, NULL);
    pthread_create(&t2, NULL, thread_func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    printf("[Main] Program completed.\n");
    return 0;
}
