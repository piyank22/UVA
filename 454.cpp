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
#include <unistd.h>

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

string basestring(string s)
{
	string ans;
	forr(i,0,sz(s)-1)
		if(s[i]!=' ')
			ans += s[i];

	sort( ans.begin() , ans.end() );
	return ans;
}

int main() 
{
	int t;
	scanf("%d\n\n",&t);
	bool first=false;
	string s;
	vector<string> words;
	while(t--)
	{
		words.clear();
		while( getline(cin,s) && s!="" )
			words.pb( s );

		sort(words.begin() , words.end() );
		forr(i,0,sz(words)-2)
			forr(j,i+1,sz(words)-1)
				if( basestring(words[i]) == basestring(words[j]) )
					cout<<words[i]<<" = "<<words[j]<<"\n";

		if(t)
			printf("\n");
	}
	return 0;
}