#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
  
int rc = 0; // Reader count  
int data = 0; // Shared data  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_twrt = PTHREAD_COND_INITIALIZER;  
  
void* reader(void* arg) {  
 int reader_id = *(int*)arg;  
  
pthread_mutex_lock(&mutex);  
rc++;  
  
 if (rc == 1)  
pthread_cond_wait(&wrt, &mutex);  
  
pthread_mutex_unlock(&mutex);  
  
 // Reading the shared data  
printf("Reader %d reads data: %d\n", reader_id, data);  
  
pthread_mutex_lock(&mutex);  
rc--;  
  
 if (rc == 0)  
pthread_cond_signal(&wrt);  
  
pthread_mutex_unlock(&mutex);  
  
 return NULL;  
}  
  
int main() {  
pthread_treaders[5]; // Assuming 5 reader threads  
  
 int reader_ids[5];  
 for (int i = 0; i< 5; i++) {  
reader_ids[i] = i + 1;  
pthread_create(&readers[i], NULL, reader, &reader_ids[i]);  
 }  
  
 // Joining reader threads  
 for (int i = 0; i< 5; i++) {  
pthread_join(readers[i], NULL);  
 }  
  
 return 0;  
}
