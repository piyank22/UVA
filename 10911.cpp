#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int n;
int x[20];
int y[20];

int target;

double dis[20][20];

double memo[ 1 << 16 ];

double solve(int bitmask)
{
	if(bitmask==target)
		return 0;

	if( memo[bitmask] > -.5 )
		return memo[bitmask];

	int p1;
	int p2;
	for( p1=0 ; p1<2*n ; p1++ )
		if( !(bitmask & 1<<p1) )
			break;

	double ans=1e9;
	for( p2=p1+1 ; p2<2*n ; p2++ )
		if( !(bitmask & 1<<p2) )
			ans = min( ans , dis[p1][p2] + solve( bitmask | (1<<p1) | (1<<p2) ) );

	return memo[bitmask]=ans;
}

int main()
{
	int cnt=1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<2*n;i++)
			scanf("%*s %d %d",&x[i],&y[i]);

		for(int i=0;i<2*n;i++)
			for(int j=i;j<2*n;j++)
				dis[i][j]=dis[j][i]=hypot(x[i]-x[j],y[i]-y[j]);

		target = ( 1<<(2*n) )-1;

		for(int i=0;i<(1<<16);i++)
			memo[i]=-1;

		printf("Case %d: %.2lf\n",cnt++,solve(0));
	}
	return 0;
}