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

int arr[11];
vector<int> cc[6];
int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int c,s;
	bool first = true;
	int cnt = 1;
	double imbalance,sum;
	while(cin>>c>>s)
	{
		forr(i,0,5) cc[i].clear();
		imbalance = 0;
		sum = 0;
		if(first==false) cout<<endl; first = false;
		forr(i,0,s-1) cin>>arr[i] , sum += arr[i] ;
		sum = 1.0*sum/c;
		sort(arr , arr+s , [](const int& a , const int& b){ return a>b; } );
		forr(i,0,s-1)
		{
			if(i<c)	cc[i].pb(arr[i]);
			else cc[2*c-i-1].pb(arr[i]);
		}
		cout<<"Set #"<<cnt++<<endl;
		forr(i,0,c-1) 
		{
			double temp = 0;
			printf("%2d:",i ); for( auto k: cc[i] ) printf(" %d",k ) , temp += k ;
			imbalance += fabs(temp-sum);
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n",imbalance );
	}
	return 0;
}