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
	set< pair<char,char> > s;
	char a[21]={'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'};
	char b[21]={'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','S','8'};
	forr(i,0,20)
	{
		s.insert( mp(a[i],b[i]) );
		s.insert( mp(b[i],a[i]) );
	}

	string str;
	bool pal,mir,first=false;
	while( 1 )
	{
		if(first)
			cout<<"\n";
		if( !(cin>>str) )
			break;
		first=true;
		cout<<str;
		pal=true,mir=true;

		forr(i,0,sz(str)-1)
		{
			if(str[i]!=str[sz(str)-1-i])
				pal=false;
			if( s.find( mp(str[i],str[sz(str)-1-i]) ) == s.end() )
				mir=false;
		}
		
		if(pal & mir)
			printf(" -- is a mirrored palindrome.\n");
		else if(!pal && mir)
			printf(" -- is a mirrored string.\n");
		else if(pal && !mir)
			printf(" -- is a regular palindrome.\n");
		else
			printf(" -- is not a palindrome.\n"); 
	} 
	return 0;
}