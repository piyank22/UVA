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

const int max_n = (1e6)+10 ;

int player[max_n] ;

int main() 
{
	string s;
	string end="Game Over";
	while( 1 )
	{
		int ans = 0;
		getline(cin,s);
		if(s==end)
			break;

		stringstream ss(s);
		vector< pair<int,int> > game(11,mp(0,0));
		forr(i,1,9)
		{
			ss >> s;
			if(s=="X")
				game[i] = mp(10,0);
			else
			{
				int temp = s[0]-'0';
				ss >> s;
				if( s=="/")
					game[i] = mp(temp,10-temp);
				else
					game[i] = mp(temp,s[0]-'0');
			}
		}

		ss >> s;
		if(s=="X")
		{
			ss >> s;
			if(s=="X")
			{
				ss >> s;
				game[10]=mp(10,10);
				if(s=="X")
					ans += 10;
				else
					ans += s[0]-'0';
			}
			else
			{
				int temp = s[0]-'0';
				game[10]=mp(10,temp);
				ss >> s;
				if(s=="/")
					ans += 10-temp;
				else
					ans += s[0]-'0';
			}
		}
		else
		{
			int temp = s[0]-'0';
			ss >> s;
			if(s=="/")
			{
				game[10]=mp(temp,10-temp);
				ss >> s;
				if(s=="X")
					ans +=10;
				else
					ans +=s[0]-'0';
			}
			else
				game[10]=mp(temp,s[0]-'0');
		}

		//for 9 seperately
		if(game[9].xx==10)//strike
		{
			ans += 10;
			ans += game[10].xx+game[10].yy;
		}
		else if(game[9].xx + game[9].yy ==10)//spare
		{
			ans += 10;
			ans += game[10].xx;
		}
		else
		{
			ans += game[9].xx+game[9].yy;
		}

		rof(ii,8,1)
		{
			if(game[ii].xx==10)//strike
			{
				ans += 10;
				if(game[ii+1].xx==10)
					ans += 10 + game[ii+2].xx;
				else
					ans += game[ii+1].xx+game[ii+1].yy;
			}
			else if(game[ii].xx + game[ii].yy ==10)//spare
				ans += 10 + game[ii+1].xx;
			else
				ans += game[ii].xx + game[ii].yy;
		}
		ans += game[10].xx + game[10].yy ;
		cout<< ans <<endl ;
	}
	return 0;
}