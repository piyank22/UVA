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

int n;
int adj[50010];
int num_scc;
int dfs_counter;
vi arr , visited , dfs_num , dfs_low , scc_id , scc_size ;

void tarjan_scc(int u)
{
    arr.pb(u);
    visited[u] = 1;
    dfs_num[u] = dfs_low[u] = dfs_counter++;

    int v = adj[u];
    if( dfs_num[v] == -1 )
        tarjan_scc(v);
    if( visited[v] )
        dfs_low[u] = min( dfs_low[u] , dfs_low[v] );

    if( dfs_low[u] == dfs_num[u] )
    {
        num_scc++;
        int temp;
        while(1)
        {
            temp = arr.back();
            arr.pop_back();
            visited[temp]=0;
            scc_id[temp] = num_scc;
            scc_size[num_scc]++;
            if(u==temp) 
                break;
        }
    }
}

int dp[50050];

int dfs(int u)
{
    int v = adj[u];
    int &res = dp[ scc_id[u] ];
    if( ~res )  return res;
    res = 0;
    if( scc_id[u] != scc_id[v] )
        res = dfs(v) + scc_size[ scc_id[v] ];

    return res;
}

int main()
{   
    boost
    test_case
    {
        cin >> n;
        forr(i,0,n-1)
        {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u] = v;
        }

        dfs_num.assign(n,-1);
        dfs_low.assign(n,0);
        visited.assign(n,0);
        scc_size.assign(n+1,0); // size of scc can be n
        scc_id.assign(n,0);
        minus(dp);

        dfs_counter = 0;
        num_scc = 0;
        arr.clear();

        forr(i,0,n-1)
            if( dfs_num[i] == -1 )
                tarjan_scc(i);

        int ans = 0;
        int reached = 0;
        
        forr(i,0,n-1)
        {
            int temp = dfs(i) + scc_size[ scc_id[i] ];
            if( temp > reached )
            {
                reached = temp;
                ans = i;
            }
        }

        cout << "Case " << tc << ": " << ans+1 << "\n";
    }
    return 0;
}
