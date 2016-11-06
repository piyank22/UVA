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
	map< map<char,int> , string > st;
	map<char,int> temp;
	set<string> ananagrams;
	while(1)
	{
		temp.clear();
		string s;
		cin >> s;
		if(s=="#") break;
		forr(i,0,sz(s)-1)
			temp[s[i]]++ , temp[s[i]^32]++;
		
		if( st.find(temp) == st.end() )
			st[temp]=s , ananagrams.insert(s) ;
		else
			ananagrams.erase( st[temp] );
	}
	for(set<string>::iterator it=ananagrams.begin();it!=ananagrams.end() ;it++)
		cout<<*it<<endl;
	return 0;
}