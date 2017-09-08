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
	uint64_t product1,product2,product3,num=1000;
	for(;num<99999999;num++)
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
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    printf("time: %d us\n", timeuse);
    return 0;
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
