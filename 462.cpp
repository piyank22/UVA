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
	string s;

	map<char,int> m;
	m['A']=0;
	for(char c='2';c<='9';c++)
		m[c]=c-'1';
	m['T']=9;
	m['J']=10;
	m['Q']=11;
	m['K']=12;

	m['S']=0;
	m['H']=1;
	m['D']=2;
	m['C']=3;

	int arr[4][13];
	int row_count[4];

	while( getline(cin,s) )
	{
		memset(arr,0,sizeof(arr));
		memset(row_count,0,sizeof(row_count));
		stringstream ss(s);
		forr(i,0,12)
		{
			string t;
			ss >> t;
			arr[ m[t[1]] ][ m[t[0]] ] = 1;
		}

		forr(i,0,3)
		{
			int s=0;
			forr(j,0,12)
				s += arr[i][j];
			row_count[i] = s;
		}

		// point counting 
		int points = 0;
		forr(i,0,3)
		{
			// rule 1
			if(arr[i][0])
				points += 4;
			if(arr[i][12])
				points += 3;
			if(arr[i][11])
				points += 2;
			if(arr[i][10])
				points += 1;

			// rule 2 3 4
			if(arr[i][12] && row_count[i] == 1)
				points--;
			if(arr[i][11] && row_count[i] <= 2)
				points--;
			if(arr[i][10] && row_count[i] <= 3)
				points--;
		}

		// checking for no trump
		if( points >= 16 ) // no trump can happen so check for stopped
		{
			int a=0;
			forr(i,0,3)
			{
				if( ( arr[i][0] == 1 ) || ( arr[i][12] == 1 && row_count[i] >= 2 ) || ( arr[i][11] && row_count[i] >= 3 ) )
					a++;
			}
			if(a==4)
			{
				printf("BID NO-TRUMP\n");
				continue;
			}
		}
		forr(i,0,3)
		{
			if( row_count[i] <= 1 )
				points += 2;
			else if( row_count[i] == 2 )
				points++;
		}
		if( points < 14 )
			printf("PASS\n");
		else
		{
			int ma = 0;
			int index = 0;
			rof(i,3,0)
				if( row_count[i] >= ma )
				{
					ma = row_count[i];
					index = i;
				}
			printf("BID ");
			if( index == 0)
				printf("S\n");
			else if( index == 1 )
				printf("H\n");
			else if(index == 2)
				printf("D\n");
			else
				printf("C\n");
		}
	}
	return 0;
}