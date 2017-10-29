#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define WITHDRAW 0
#define PAY_IN 1

int balance;

struct ACCOUNT
{
  int amount;
  int operation;
};

void pay_in(int amount)
{
  balance += amount;
}

void withdraw(int amount)
{
  printf("<%d> attempting to withdraw [%d]: \n",pthread_self(),amount);
  if (balance >= amount) {
    sleep(1);
    printf("Success...\n");
    balance -= amount;
    }
  else {
    printf("Operation not permitted...\n");
    return;
    }
}

void check_balance()
{
  printf("Your current balance is: <%d>\n",balance);
}

void *person(void *arg)
{
  struct ACCOUNT *acc = (struct ACCOUNT*)arg;
  if (acc->operation == WITHDRAW)
    withdraw(acc->amount);
  else
    pay_in(acc->amount);
  check_balance();
}

//The main program.
int main ()
{
  pthread_t th_id1,th_id2;
  struct ACCOUNT acc;

  pay_in(100);

//Create a new thread.
  acc.operation = WITHDRAW;
  acc.amount = 100;
  pthread_create (&th_id1, NULL, &person,(void*)&acc);
  acc.operation = WITHDRAW;
  pthread_create (&th_id2, NULL, &person,(void*)&acc);
  
// Wait for threads to finish
  pthread_join(th_id1,NULL);
  pthread_join(th_id2,NULL);

  return 0;
}
