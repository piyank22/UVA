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
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define sz(v) (int)(v.size())

using namespace std;

char arr[110][110];
char temp[110][110];

int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};

int main() 
{
	int t ;
	cin >> t ;
	while(t--)
	{
		memset(arr,0,sizeof(arr));
		memset(temp,0,sizeof(temp));
		int r , c , n ;
		cin >> r >> c >> n ;
		forr(i,1,r) forr(j,1,c) cin >> arr[i][j] ;

		forr(k,1,n)
		{
			forr(i,1,r) forr(j,1,c)
			{
				temp[i][j] = arr[i][j];
				forr(dir,0,3)
				{
					int xd = i+x[dir];
					int yd = j+y[dir];
					if( xd>=1 && xd<=r && yd>=1 && yd<=c )
					{
						if( arr[i][j] == 'P')
						{
							if( arr[xd][yd] == 'S')
								temp[i][j] = 'S';
						}
						else if( arr[i][j] == 'R')
						{
							if( arr[xd][yd] == 'P')
								temp[i][j] = 'P';
						}
						else
						{
							if( arr[xd][yd] == 'R')
								temp[i][j] = 'R';
						}
					}
				}
			}
			forr(i,1,r) forr(j,1,c)
				arr[i][j] = temp[i][j];
		}

		forr(i,1,r)
		{
			forr(j,1,c)
				printf("%c",arr[i][j]);
			printf("\n");
		}
		if(t!=0)
			printf("\n");
	}
	return 0;
}