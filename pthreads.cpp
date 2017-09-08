#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <cmath>
#include <ctime>
using namespace std;

#define NUM_THREADS 10
#define MAX 100000000
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
		//if(count(num)%2==0)
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