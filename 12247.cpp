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
	int princess[3];
	int prince[3];
	int ans;
	bool loss;
	while(1)
	{
		cin >> princess[0] >> princess[1] >> princess[2] >> prince[0] >> prince[1] ;
		prince[2] = 0 ;
		if( princess[0] == 0 )
			break;
		loss = false ;
		ans = 1;
		int arr[3] = { 0 , 1 , 2 };
		do
		{
			int win[3] = { 0 , 0 , 0 };
			int next_cd;
			forr(i,0,2)
			{
				if( arr[i] != 2 )
					win[i] = prince[ arr[i] ] > princess[i] ;
				else
					next_cd = princess[i] ;
			}

			if( win[0] + win[1] + win[2] == 0 )
				loss = true;
			else // can win
			{
				set< int > s;
				s.insert( princess , princess+3 );
				s.insert( prince , prince+2 );
				next_cd++;

				if( win[0] + win[1] + win[2] == 2 ) // if alredy won find smallest card in deck
					next_cd = 1 ;

				while( s.find(next_cd) != s.end() )
				{
					next_cd++;
				}

				if(next_cd == 53)
					loss = true;
				else
					ans = max( ans, next_cd );
			}

		}while(next_permutation ( arr,arr+3 ) );

		if( loss )
			printf("-1\n");
		else
			printf("%d\n",ans );
	}
	return 0;
}