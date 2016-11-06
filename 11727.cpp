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
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{

		int a,b,c;
		scanf("%d %d %d\n" , &a,&b,&c );
		int s=a+b+c-min(a,min(c,b))-max(a,max(b,c));
		printf("Case %d: %d\n",i,s);
	}
	return 0;
}