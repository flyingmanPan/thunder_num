#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <cmath>
#include <ctime>
using namespace std;

#define NUM_THREADS 10
#define MAX 100000
uint64_t begin_num=0;
uint64_t timeuse=0;
int count(int);
time_t longest_time=0;
void *count_out(void *time)
{
	//time_t t = (time_t)time;
	//printf("Time, %ld\n",t);
	uint64_t product1,product2,product3,
	num=begin_num,end_num=begin_num+MAX/NUM_THREADS;
	begin_num+=MAX/NUM_THREADS;
	for(;num<end_num;num++)
	{
		uint64_t i=1,num1=num*num;
		while(1)
		{
			uint64_t temp=pow(10,i);
			if(num1/temp<=1)
				break;
			if(pow(num1%temp+num1/temp,2)==num1)
				printf("%ld\n",num1);
			i++;
		}
	}
	time_t end=clock();
	if(end>longest_time)
	{
		longest_time=end;
	}
	printf("millis:%ld\n",longest_time/10000);
	pthread_exit(NULL);
}

int main ()
{
	clock_t start,end;
	start=clock();
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;
	for( i=0; i < NUM_THREADS; i++ )
	{
		//cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, count_out, (void *)i);
	}
	pthread_exit(NULL);
}
