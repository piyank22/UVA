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
#define INF 0x3fffffff
#define inf 1000000000
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

int n,m;
int arr[110][110];
vvi adj;
vi vis;
vi top_arr;
vi dp;

void dfs_top_sort(int u)
{
    vis[u]=1;
    for( auto v: adj[u] )
        if( !vis[v] )
            dfs_top_sort(v);
    top_arr.pb(u);
}

int main()
{     
    boost
    test_case
    {
        string s;
        cin >> s >> n >> m;
        adj.assign( n*m , vi() );

        forr(i,0,n-1)   forr(j,0,m-1)   cin >> arr[i][j];

        int node1,node2;
        forr(i,0,n-1)   forr(j,0,m-1)
        {
            node1 = i*m+j;
            forr(dir,0,3)
            {
                int i1 = i + x_dir[dir];
                int j1 = j + y_dir[dir];
                if( i1<0 || i1>=n || j1<0 || j1>=m || arr[i1][j1] >= arr[i][j] )    continue;

                node2 = i1*m+j1;
                adj[node1].pb(node2);
            }
        }  

        vis.assign(n*m,0);
        top_arr.clear();

        forr(i,0,n*m-1)
            if( !vis[i] )
                dfs_top_sort(i); 

        int ans = 0;
        dp.assign(n*m,0);

        for( auto u: top_arr )
        {
            int mx=0;
            for( auto v: adj[u] )
                mx = max( mx , dp[v] );
            dp[u] =1+mx;
            ans = max(ans,1+mx);
        }

        cout << s << ": " << ans << endl;
    }
    return 0;
}

