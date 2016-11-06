#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <unistd.h>

#define PI acos(-1)
#define ll long long
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define eps 1e-5
#define setzero(a) memset(&a,0,sizeof(a))
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define sz(v) (int)(v.size())
using namespace std;

int main() 
{
	while(1)
	{
		int t;
		cin >> t;
		if(t==0) break;
		printf("Printing order for %d pages:\n",t );
		double sheets = ceil(t/4.0);
		int x=sheets*4;
		int y=1;
		pair<int,int> pa[110];
		memset(pa,0,sizeof(pa));
		forr(i,1,2*sheets)
		{
			pa[i]=mp(x,y);
			x-=2;
			y+=2;
		}
		int sht=sheets;
		forr(i,1,sheets)
		{
			printf("Sheet %d, front: ", i);
			if(pa[i].xx<=t)
				cout<<pa[i].xx;
			else
				cout<<"Blank";
			cout<<", ";
			cout<<pa[i].yy<<endl;
			if( pa[2*sht-i+1].xx <=t )
			{
				printf("Sheet %d, back : ",i );
				cout<<pa[2*sht-i+1].xx;
				cout<<", ";
				if(pa[2*sht-i+1].yy<=t)
					cout<<pa[2*sht-i+1].yy;
				else
					cout<<"Blank";
				cout<<endl;
			}
		}
	}
	return 0;
}