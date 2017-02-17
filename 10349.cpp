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
#define infinity(x) memset(&x,0x3f,sizeof(x))
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

int n,m;
vvi adj,grid;
vi left_side,match,visited;

bool aug( int u )
{
    if( visited[u] )    return false;
    visited[u] = true;

    for( int v: adj[u] )
        if( match[v]==-1 || aug( match[v] ) )
        {
            match[v] = u;
            return true;
        }

    return false;
} 

int main()
{
    //boost

    test_case
    {
        cin >> n >> m;

        grid = vvi( n , vi(m,-1) );
        left_side = vi();
        adj = vvi();

        char c;
        forr(i,0,n-1)   forr(j,0,m-1)
        {
            cin >> c;
            if( c != '*' )  continue;

            grid[i][j] = sz( adj );
            left_side.pb( (i+j)%2 );
            adj.pb( vi() );

            if( i>0 && grid[i-1][j]>=0 )
            {
                adj[ grid[i-1][j] ].pb( grid[i][j] );
                adj[ grid[i][j] ].pb( grid[i-1][j] );
            }

            if( j>0 && grid[i][j-1]>=0 )
            {
                adj[ grid[i][j-1] ].pb( grid[i][j] );
                adj[ grid[i][j] ].pb( grid[i][j-1] );
            }
        }   

        match.assign( sz(adj) , -1 );

        int mcbm = 0;
        forr(i,0,sz(adj)-1)
            if( left_side[i] )
            {
                visited.assign( sz(adj) , 0 );
                mcbm += aug(i);
            }

        cout << sz(adj) - mcbm << endl;
    }

    return 0;
}
