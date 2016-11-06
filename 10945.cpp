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
		string s,t;
		
		t.clear();
		s.clear();
		getline(cin,s);
		
		if(s=="DONE") break;
		
		bool ans=true;
		forr(i,0,sz(s)-1)
		{
			if(s[i]>=65 && s[i]<=90)
				t += s[i]+32;
			else if(s[i]>=97 && s[i]<=122)
				t += s[i];
		}
		forr(i,0,sz(t)-1)
			if( t[i] != t[sz(t)-1-i] )
			{
				ans = false;
				break;
			}
		
		if(ans)
			cout<<"You won't be eaten!\n";
		else
			cout<<"Uh oh..\n";
	}
	return 0;
}