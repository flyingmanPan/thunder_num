#include <iostream>
#include<cmath>
#include<sys/time.h>
using namespace std;
int count(int);
int main()
{
	
	//cin>>num;
	struct timeval start, end;
    gettimeofday( &start, NULL );
	
	uint64_t product1,product2,product3,num1=1;
	for(;num1<100000;num1++)
	{
		uint64_t num=num1*num1;
		uint64_t i=1;
		while(1)
		{
			uint64_t temp=pow(10,i);
			if(num/temp<=1)
				break;
			if(pow(num%temp+num/temp,2)==num)
				printf("%ld\n",num);
			i++;
		}
		
	}
	
	gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    printf("time: %d us\n", timeuse);
    return 0;
}
