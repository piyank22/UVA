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

int le;
int arr[110];
void process()
{
	vector<int> vec;
	bool sync = true;
	int min = 2+(5*60*60);
	forr(j,0,le-1)
	{
		for(int i=2*arr[j];i<=5*60*60;i+=2*arr[j])
			vec.pb(i);
	}
	sort(vec.begin(),vec.end());
	forr(i,0,sz(vec)-1)
	{
		int j;
		for(j=0;j<le;j++)
			if( vec[i]%(2*arr[j]) >= arr[j]-5 )  break;
		if(j==le)
		{
			int hr=vec[i]/3600;
			vec[i]=vec[i]%3600;
			int min=vec[i]/60;
			int sec=vec[i]%60;
			printf("%02d:%02d:%02d\n",hr,min,sec );
			sync = false;
			break;
		}
	}
	if(sync)  cout<<"Signals fail to synchronise in 5 hours\n";
}

int main() 
{
	string s;
	while(1)
	{
		getline(cin,s);
		if(s=="0 0 0") break;
		stringstream ss(s);
		int t;
		while(ss >> t)
		{	
			if(t==0)
			{
				process();
				memset(arr,0,sizeof(arr));
				le=0;
			}
			else 
				arr[le++]=t;
		}
	}
	return 0;
}