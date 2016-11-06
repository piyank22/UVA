#include <iostream>
#include <cstdio>
#include <math.h>
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
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(v) int(v.size())
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
#define all(v) (v).begin(),(v).end()
#define INF 0x3fffffff
#define ten9 1000000000
#define mod 1000000007
#define zero(x) memset(&x,0,sizeof(x))
#define minus(x) memset(&x,0xff,sizeof(x))
#define trace1(x) cerr<<#x<<" = "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<endl;

using namespace std;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

string arr[65];
int n;
bool can(double f) 
{ 
	string temp;
	double fuel_left = f;
	double start = 0;
	double leak_count = 0;
	double consumption_rate;
	
	stringstream ss;
	ss.clear();
	ss << arr[0] ;
	ss >> temp >> temp >> temp;
	ss >> consumption_rate;

	forr(i,1,n-1)
	{
		stringstream ss(arr[i]);
		double pos;
		ss >> pos;
		fuel_left -= (consumption_rate*(pos-start)/100.0) + (pos-start)*leak_count;
		
		ss >> temp;
		if( fuel_left< -eps )
			return false;
		if(temp == "Fuel")
			ss >> temp >> consumption_rate;
		else if(temp == "Leak")
			leak_count += 1.0 ;
		else if(temp == "Gas")
			fuel_left = f;
		else if(temp == "Mechanic")
			leak_count = 0;
		start = pos;
	}
	return (fuel_left>=-eps);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	string s;
	getline(cin,s);
	arr[0] = s;
	while( s != "0 Fuel consumption 0")
	{
		n=1;
		while(1)
		{
			getline(cin,s);
			arr[n++] = s;
			stringstream ss(s);
			string a,b;
			ss >> a >> b;
			if(b=="Goal")
				 break;
		}

		double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
		forr(i,0,50) 
		{
			mid = (lo + hi) / 2.0;
			if ( can(mid) ) 
			{
				ans = mid;
				hi = mid;
			}
			else
				lo = mid;
		}
		printf("%.3lf\n", ans);
		getline(cin,arr[0]);
		s = arr[0];
	}
	return 0;
}