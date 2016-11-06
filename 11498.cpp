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
	while( scanf("%d",&n) , n>0 )
	{

		int a,b;
		int x,y;
		scanf("%d %d\n" , &a,&b );
		while(n--)
		{
			scanf("%d %d\n" , &x,&y );
			if( x==a || y==b )
				printf("divisa\n");
			else if(x>a)
			{
				if(y>b)
					printf("NE\n");
				else
					printf("SE\n");
			}
			else
			{
				if(y>b)
					printf("NO\n");
				else
					printf("SO\n");
			}
		}
	}
	return 0;
}