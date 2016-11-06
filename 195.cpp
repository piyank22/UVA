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

bool cmp(char a,char b)
{
	char c = (a<=96?a+32:a);
	char d = (b<=96?b+32:b);
	if(c==d)
		return a<b;
	return c<d;
}

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		vector<char> vec;
		vec.clear();
		string s;
		cin>>s;
		vec.insert(vec.begin(),s.begin(),s.end());
		sort(vec.begin(),vec.end(),cmp);
		do
		{
			forr(i,0,sz(vec)-1)
				cout<<vec[i];
			cout<<endl;
		}while( next_permutation(vec.begin(),vec.end(),cmp) );
	}
	return 0;
}