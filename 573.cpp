#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

#define PI acos(-1)
#define ll long long
#define eps 1e-5

using namespace std;

int main() 
{
	int u,d,f;
	double h;
	while(1)
	{
		cin>>h>>u>>d>>f;
		if(h==0)
			break;
		double climbing_distance=0;
		int day=0;
		while( climbing_distance >= 0)
		{
			climbing_distance += ( (1.0 - 1.0*day*f/100.0)*u >= 0 ? (1.0 - 1.0*day*f/100.0 )*u : 0 );
			day++;

			if( climbing_distance > h)
				break;
			climbing_distance -= d;
			
		}
		if( climbing_distance >= 0)
			cout<<"success ";
		else
			cout<<"failure ";
		cout<<"on day "<<day<<"\n";
	}
	return 0;
}