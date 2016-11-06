#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

#define PI acos(-1)
#define ll long long

using namespace std;

int main() 
{
	double dp,lv,inst;
	int n,months;
	double dep[110];
	while(1)
	{
		scanf("%d %lf %lf %d\n", &months , &dp , &lv , &n);
		fill(dep,dep+110,0);
		if(months < 0)
			break;
		inst = lv/months;
		while(n--)
		{
			double x;
			int i;
			scanf("%d %lf\n",&i,&x);
			dep[i]=1-x;
		}
		for(int i=1;i<100;i++)
			if(dep[i]==0)
				dep[i]=dep[i-1];
		double car_value = (dp+lv)*dep[0];
		int c=0;
		while( lv > car_value )
		{
			c++;
			lv-=inst;
			car_value*=dep[c];
		}
		printf("%d month",c);
		if(c!=1)
			printf("s\n");
		else
			printf("\n");
	}
	return 0;
}