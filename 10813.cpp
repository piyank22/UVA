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
	int t;
	cin >> t;
	int m[5];
	set<int> ss,dia1,dia2,vert[6];
	while(t--)
	{
		setzero(m);
		ss.clear() ; dia2.clear() ; dia1.clear() ;
		forr(i,1,5) vert[i].clear();

		forr(i,1,5) 
			forr(j,1,5) 
				if(i*j!=9) 
				{ 
					int temp;
					cin >> temp ;
					ss.insert(temp);
					if(i==j)
						dia1.insert(temp);
					if(i+j==6)
						dia2.insert(temp);
					vert[i].insert(temp);
				}

		int val;
		int turn = 0;
		m[2]++;
		bool ans=false;
		int an;
		while(turn<75)
		{
			turn++;
			cin >> val;
			if( ss.find(val) != ss.end() )
			{
				m[ (val-1)/15 ]++;
				dia1.erase(val);
				dia2.erase(val);
				forr(i,1,5)
					vert[i].erase(val);
			}
			if(ans==false)
			{
				if(sz(dia2)==0 || sz(dia1)==0)
					ans=true , an=turn;
				forr(i,0,4)
				{
					if(m[i]==5)
						ans=true , an=turn;
					if(sz(vert[i+1])==0)
						ans=true , an=turn;
				}

			}
		}
		printf("BINGO after %d numbers announced\n",an );
	}

	return 0;
}