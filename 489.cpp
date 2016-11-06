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
#define pb push_back
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

int main() 
{
	while(1)
	{
		int n;
		cin >> n ;
		int strokes = 0;
		if( n == -1 )
			break;

		string a,b;
		cin >> a >> b;

		bool ans = false ;

		set< char > s;
		forr(i,0,a.size()-1)
			s.insert( a[i] );

		set< char > tried;
		forr(i,0,b.size()-1)
			if( tried.find(b[i]) == tried.end() )
			{
				if( s.find(b[i]) == s.end() )
					strokes++;
				else
				{
					s.erase(b[i]);
					if(s.empty()==true)
					{
						ans = true;
						break;
					}
				}
				tried.insert( b[i] );
			}

		printf("Round %d\nYou ",n );
		if( ans && strokes < 7 )
			printf("win.\n");
		else if( strokes < 7 )
			printf("chickened out.\n");
		else
			printf("lose.\n");
	}
	return 0;
}