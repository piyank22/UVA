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
#define boost cin.tie(0); ios_base::sync_with_stdio(0) ; 
#define trace1(x) cerr << #x <<" = "<< x <<endl;
#define trace2(x,y) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<endl;
#define trace3(x,y,z) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<" , "<< #z <<" = "<< z <<endl;
#define trace_arr(a,i,n) cerr << #a <<" : " ; forr(_i,i,n) cerr << a[_i] << " "; cerr << endl;
#define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n) { forr(_j,j,m) cerr << setw(6) << a[_i][_j] << " "; cerr << endl; } cerr << endl;
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

int n,m;
vector< vi > adj;

vi dfs_low , dfs_num , dfs_parent , articulation ;
int dfs_counter , dfs_head , head_child;

vii sol;

void critical(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for( auto v : adj[u] )
    {
        if( dfs_num[v]==-1 )
        {
            dfs_parent[v]=u;
            if( u==dfs_head )   head_child++;

            critical(v);
            if( dfs_num[u] <= dfs_low[v] )
                articulation[u]++;

            dfs_low[u] = min ( dfs_low[u] , dfs_low[v] );
        }
        else if( v != dfs_parent[u] )
            dfs_low[u] = min ( dfs_low[u] , dfs_num[v] );            
    }
}

int main()
{   
    boost 
    while( cin >> n >> m , n|m )
    {
        adj = vector< vi > ( n , vi() );
        while(1)
        {
            int u,v;
            cin >> u >> v ;
            if( u+v == -2 )     break;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        dfs_num.assign(n,-1);       dfs_low.assign(n,0);    dfs_parent.assign(n,-1);
        articulation.assign(n,0);

        dfs_counter = 0;

        int no_of_disconnected_comp = 0;
        forr(i,0,n-1)
            if(dfs_num[i]==-1)
            {
                no_of_disconnected_comp++;
                dfs_head = i;
                head_child = 0;
                critical(i);
                articulation[i] = head_child-1 ;
            }

        sol.clear();
        forr(i,0,n-1)
            sol.pb( mp(i,articulation[i]+no_of_disconnected_comp) );

        sort( all(sol) , [](ii a , ii b ){ return ( a.yy>b.yy or ( (a.yy==b.yy) and (a.xx<b.xx) ) );} );
        int cnt = 0;
        forr(i,0,m-1)
        {
            ii a = sol[i];
            cout << a.xx << " " << a.yy << endl;
        }
        cout << endl;
    }
    return 0;
}
