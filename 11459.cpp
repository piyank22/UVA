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

const int max_n = (1e6)+10 ;

int player[max_n] ;

int main() 
{
	int t;
	cin >> t ;
	int move[108] ;
	move[101] = 100;
	move[102] = 100;
	move[103] = 100;
	move[104] = 100;
	move[105] = 100;
	move[106] = 100;

	while( t-- )
	{
		int a,b,c ;
		cin >> a >> b >> c ;

		fill( player , player + a + 1 , 1 );
		forr(i,1,100)
			move[i] = i;

		while(b--)
		{
			int t , tt ;
			cin >> t >> tt ;
			move[t] = tt ;
		}
		bool win = false;
		int turn = 0;
		while(c--)
		{
			int t;
			cin >> t ;
			if(!win)
			{
				turn = ( turn % a ) + 1 ;
				player[ turn ] = move[ player[ turn ] + t ];
				if( player[turn] == 100 )
					win = true;
			}
		}
		forr(i,1,a)
			printf("Position of player %d is %d.\n" , i , player[i] );
	}
	return 0;
}