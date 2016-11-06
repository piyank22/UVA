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

int n, q;

const int max_n = 1e5+10;

vi adj[max_n<<1];
int level[max_n<<1];
vector<pii> query[max_n<<1];
int ans[max_n];

bool cmp( const pii& a , const pii& b)	{	return a.xx < b.xx;		}

void solve( vector<pii> &partial_level_vertex_list )
{
	if(sz(partial_level_vertex_list)==0) return;

	if( sz( query[ partial_level_vertex_list.back().yy ] ) )
	{
		for( auto i: query[partial_level_vertex_list.back().yy] )
			ans[i.yy] = lower_bound(all(partial_level_vertex_list),mp(i.xx,0),cmp)->yy;
	}

	int in = partial_level_vertex_list.back().yy;
	for( auto i: adj[in] )
	{
		partial_level_vertex_list.eb(level[i],i);
		solve(partial_level_vertex_list);
	}
	partial_level_vertex_list.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while( cin >> n >> q )
	{
		forr(i,0,(max_n<<1)-2)	adj[i].clear() , query[i].clear() ;
		zero(level);
		level[0]=1;
		forr(i,1,n-1)
		{
			int p;
			cin >> p >> level[i];
			adj[p].eb(i);
		}

		forr(i,1,q)
		{
			int p,lv;
			cin >> p >> lv;
			query[p].eb(lv,i);
		}

		vector<pii> partial_level_vertex_list;
		partial_level_vertex_list.eb(1,0);
		solve(partial_level_vertex_list);
		forr(i,1,q)	cout<<ans[i]<<" \n"[i==q];
	}
	return 0;
}