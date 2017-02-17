/*******************
AUTHOR: HUMBLE_LOSER
*******************/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define PI acos(-1)
#define EXP 2.7182818284590452353602874713527
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
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
#define inf 0x3f3f3f3f
#define mod 20437
#define zero(x) memset(&x,0,sizeof(x))
#define minus(x) memset(&x,0xff,sizeof(x))
#define boost cin.tie(0); ios_base::sync_with_stdio(0); 
#define trace1(x) cerr << #x <<" = "<< x <<endl;
#define trace2(x,y) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<endl;
#define trace3(x,y,z) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<" , "<< #z <<" = "<< z <<endl;
#define trace_arr(a,i,n) cerr << #a <<" : " ; forr(_i,i,n) cerr << a[_i] << " "; cerr << endl;
#define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n){forr(_j,j,m) cerr << setw(6) << a[_i][_j] << " "; cerr << endl;}cerr<<endl;
#define test_case int __T;cin >> __T; forr(tc, 1 , __T)     

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

int x_dir[4] = { -1,0,1,0}; // standard x-y axis NORTH - EAST - SOUTH - WEST
int y_dir[4] = { 0,1,0,-1};

int n;
string grid[13];
vvi adj;

int end_index;
int node_pos[30];
set<int> not_acceptable;

ii bfs( int s, int e)
{
	vi dis(n*n,inf);
	vi cnt(n*n,0);
	cnt[s] = 1;
	dis[s] = 0;

	queue<int> q;
	q.push(s);

	while( !q.empty() )
	{
		int u = q.front();	q.pop();
		for( auto v: adj[u] )
		{
			if( not_acceptable.find(v) != not_acceptable.end() )	continue;
			if( dis[v] == inf )
			{
				dis[v] = dis[u]+1;
				cnt[v] = cnt[u];
				q.push(v);
			}
			else if( dis[v] == dis[u]+1 )
				cnt[v] = ( cnt[v] + cnt[u] ) % mod;
		}
	}
	return mp( dis[e] , cnt[e] );
}

int main()
{     
    // boost
    int tc = 1;
    while( cin >> n , n )
    {
    	adj.assign(n*n,vi());
    	minus(node_pos);
    	not_acceptable.clear();


    	forr(i,0,n-1)	cin >> grid[i];

    	char end_char = 'A';
       	end_index = 0;

       	forr(i,0,n-1)	forr(j,0,n-1)	
    	{
    		int node = i*n+j;
    		char v = grid[i][j];
    		if( v == '#' )	continue;
    		if( v >= 'A' && v <= 'Z' )
			{
				int num = v - 'A';
				node_pos[num] = node;
				if( v > 'A' )		not_acceptable.insert(node);
				if( v > end_char ) 	end_char = v , end_index = num ; 
			}
    		forr( dir,0,3)
    		{
    			int i1 = i + x_dir[dir];
    			int j1 = j + y_dir[dir];
    			if( i1<0 || i1>=n || j1<0 || j1>=n || grid[i1][j1]=='#' )	continue;
    			int node2 = i1*n+j1;
    			adj[node].pb(node2);
    		}
    	}

    	ll ans = 1;
    	ll dis_ans = 0 ;
    	forr(i,1,end_index)
    	{
    		int s_node = node_pos[i-1];
    		int e_node = node_pos[i];
    		not_acceptable.erase( node_pos[i] );
    		
    		ii t = bfs( s_node , e_node );
    		
    		int temp = t.yy;
    		dis_ans = ( dis_ans + t.xx ) % mod;
    		if( temp == 0 )
    		{
    			ans = 0;
    			break;
    		}
    		ans = (ans*temp)%mod;
    	}

    	cout << "Case " << tc++ << ": ";
    	if( ans == 0 )	cout << "Impossible\n";
    	else			cout << dis_ans << " " << ans << "\n";
    }
    return 0;
}

