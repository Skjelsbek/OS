#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define BUFSIZE 250

int in=0,out=0;
int buffer[BUFSIZE];

//Producer
void* producer(void* arg)
{
  int x=0;
  while (1) {
    printf("Producer: write position=%d; writing: {%d}\n",in,x);
    buffer[in] = x++;
    in++;
    if (in == BUFSIZE)
      return;
    }
  return;
}

//Consumer
void* consumer(void* arg)
{
  int w;
  while (1) {
    while (in <= out) 
	;//printf("@\n");
    w = buffer[out];
    printf("Consumer: read position=%d; reading: {%d}\n",out,w);
    out++;
    if (out == BUFSIZE)
      return;
    }
  return;
}


//The main program.
int main ()
{
  pthread_t th_id1,th_id2;

//Create a new thread. The new thread will run the print_xs function.
  pthread_create (&th_id1, NULL, &producer, NULL);
  pthread_create (&th_id2, NULL, &consumer, NULL);
  
// Wait for threads to finish
  pthread_join(th_id1,NULL);
  pthread_join(th_id2,NULL);

  return 0;
}
