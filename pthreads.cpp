#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include<cmath>
#include<sys/time.h>
using namespace std;

#define NUM_THREADS 10
uint64_t begin_num=0;
uint64_t timeuse=0;
struct timeval start, end;
int count(int);
void *count_out(void *threadid)
{
	long tid;
	tid = (long)threadid;
	//printf("Thread ID, %ld\n",tid);
	uint64_t product1,product2,product3,
	num=begin_num,end_num=begin_num+100000000/NUM_THREADS;
	begin_num+=100000000/NUM_THREADS;
	for(;num<end_num;num++)
	{
		if(count(num)%2==0)
		{
			uint64_t data=num,front=0,back=0,count1=count(num);
			int middle=count1-1;
			for(;middle>0;middle--)
			{
				data=num,front=0,back=0;
				for(int i=0;i<middle;i++)
				{
					back+=data%10*pow(10,i);
					data/=10;
				}
				for(int i=0;i<count1-middle;i++)
				{
					front+=data%10*pow(10,i);
					data/=10;
				}
				//cout<<front<< "   "<<back<< "        "<<middle<<endl;
				if((back+front)*(back+front)==num)
					printf("%ld\n",num);
			}
		}
	}
	gettimeofday( &end, NULL );
	
	uint64_t _timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + 
	end.tv_usec -start.tv_usec;
	if(_timeuse>timeuse)
	{
		timeuse=_timeuse;
		printf("time: %d us\n", timeuse);
	}
	pthread_exit(NULL);
}

int main ()
{
    gettimeofday( &start, NULL );
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
int count(int num)
{
	int digit=1;
	while(!(num>=0&&num<=9))
	{
		digit++;
		num/=10;
	}
	return digit;
}