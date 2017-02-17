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
#define mod 1000000007
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

ll a[80][80];
int n,k;
ll memo[80][80][7][5]; // r,c,k,next_step

ll solve( int x, int y, int k, int next_step ) // next_step is 0 for down , 1 for left and 2 for right
{
	if( x<=0 || x>n || y<=0 || y>n )	return -inf;

	ll v = a[x][y];
	ll &ret = memo[x][y][k][next_step];
	if( v < 0 )	k--;
	if( k < 0 )			return ret = -inf;
	if( x==1 and y==1 )	return ret = a[x][y];

	if( ret != inf )	return ret;

	ret = -inf;
	if( next_step != 2 )
	{
		ll t = solve(x,y+1,k,1);
		if( t != -inf )	ret = max(t+v,ret);
	}
	if( next_step != 1 )
	{
		ll t = solve(x,y-1,k,2);
		if( t != -inf )	ret = max(t+v,ret);
	}
	ll t = solve(x-1,y,k,0);
	if( t != -inf )		ret = max(t+v,ret);
	return ret;
}

int main()
{     
    boost
    int tc = 1;
    while( cin >> n >> k , n|k )
    {
    	fill(&memo[0][0][0][0], &memo[79][0][0][0], inf);

    	forr(i,1,n)	forr(j,1,n)	cin >> a[i][j];
    
    	cout << "Case " << tc++ << ": ";
    	if( solve(n,n,k,0) == -inf )	cout << "impossible\n";
    	else							cout << memo[n][n][k][0] << "\n";
    }
    return 0;
}

