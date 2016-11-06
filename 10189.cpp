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
	int arr[110][110] = {0} ;
	int c = 1 ;

	int xx[8] = { 1 , 1 , 0 , -1 , -1 , -1 , 0 , 1 };
	int yy[8] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };

	while(1)
	{
		memset( arr , 0 , sizeof(arr) );
		int n , m ;
		cin >> n >> m ;
		if( n==0 && m==0 )
			break;

		if( c != 1 )
			printf("\n");

		forr(i,1,n)
			forr(j,1,m)
			{
				char t;
				cin >> t;
				if( t == '*' )
					arr[i][j] = -1 ;
				else
					arr[i][j] = 0 ;
			}

		forr(i,1,n)
			forr(j,1,m)
				if( arr[i][j] != -1 )
				{
					forr(k,0,7)
					{
						int x = i + xx[k] ;
						int y = j + yy[k] ;
						if( arr[x][y] == -1 ) 
							arr[i][j]++ ;
					}
				}

		printf("Field #%d:\n",c++ );
		forr(i,1,n)
		{
			forr(j,1,m)
				if( arr[i][j] == -1 )
					printf("*");
				else
					printf("%d",arr[i][j] );
			printf("\n"); 
		}
	}
	return 0;
}