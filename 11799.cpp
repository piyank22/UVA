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
	int n;
	cin>>n;
	for(int k=1;k<=n;k++)
	{
		int t;
		cin>>t;
		int m=0;
		for(int i=0;i<t;i++)
		{
			int temp;
			cin>>temp;
			m=max(m,temp);
		}
		printf("Case %d: %d\n",k,m );
	}
	return 0;
}