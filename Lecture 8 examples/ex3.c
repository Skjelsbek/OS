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
  int a=0;
  int *x=(int*)arg;

//  printf("arg=%d\n",*x);

  while (1) {
    a += *x;
    while (((in+1) % BUFSIZE) == out)
	; 
    printf("Producer <%u>: write position=%d; writing: {%d}\n",pthread_self(),in,a);
    buffer[in] = a;
    in = (in+1) % BUFSIZE;
    }
  return;
}

//Consumer
void* consumer(void* arg)
{
  int w;
  while (1) {
    while (out == in)
	;//printf("...consumer - waiting...[%d,%d]\n",in,out);

    w = buffer[out];
    printf("Consumer <%u>: read position=%d:%d; reading: {%d}\n",pthread_self(),out,in,w);
    out = (out+1) % BUFSIZE;
    }
  return;
}


//The main program.
int main ()
{
  pthread_t th_id1,th_id2,th_id3,th_id4;
  int x,y,z;

//Create a new thread. The new thread will run the print_xs function.
  x = 1;
  pthread_create (&th_id1, NULL, &producer, (void*)&(x));
  y = 100;
  pthread_create (&th_id2, NULL, &producer, (void*)&(y));
  z = 1000;
//  pthread_create (&th_id3, NULL, &producer, (void*)&(z));
  pthread_create (&th_id4, NULL, &consumer, NULL);
  
// Wait for threads to finish
  pthread_join(th_id1,NULL);
  pthread_join(th_id2,NULL);
//  pthread_join(th_id3,NULL);
  pthread_join(th_id4,NULL);

  return 0;
}
