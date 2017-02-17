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
vector< set<int> > adj;

map<string,int> for_map;
map<int,string> rev_map;

vi dfs_low , dfs_num , visited;
int dfs_counter;
vi arr;

void tarjan_scc(int u)
{
    visited[u] = 1;
    dfs_num[u] = dfs_low[u] = dfs_counter++;

    arr.pb(u);

    for( auto v: adj[u])
    {
        if( dfs_num[v] == -1 )
            tarjan_scc(v);
        if( visited[v] == 1 )
            dfs_low[u] = min( dfs_low[u] , dfs_low[v] );
    }

    if( dfs_low[u] == dfs_num[u] )
        while(1)
        {
            int v = arr.back();     arr.pop_back();
            visited[v] = 0;
            cout << rev_map[v] ;
            if( u == v )
            {
                cout << endl;
                break;
            }
            else cout << ", ";
        }
}

int main()
{   
    boost 
    int tc = 1;
    bool a = false;
    while( cin >> n >> m , n|m )
    {
        if( a ) cout << endl;
        a = true;
        for_map.clear();
        rev_map.clear();
        adj = vector< set<int> >( n , set<int>() );
        int cnt = 0;
        forr(i,0,m-1)
        {
            string str,trs;
            cin >> str >> trs;
            int u,v;
            if( for_map.find(str) == for_map.end() )
            {
                u = cnt;
                for_map[str] = cnt;
                rev_map[cnt] = str;
                cnt++;
            }
            else    u = for_map[str];
            str = trs;
            if( for_map.find(str) == for_map.end() )
            {
                v = cnt;
                for_map[str] = cnt;
                rev_map[cnt] = str;
                cnt++;
            }
            else    v = for_map[str];
            adj[u].insert(v);
        }

        dfs_num.assign(n,-1);   dfs_low.assign(n,0);
        visited.assign(n,0);
        arr.clear();
        dfs_counter = 0;

        cout << "Calling circles for data set " << tc++ << ":\n";
        forr(i,0,n-1)
            if( dfs_num[i] == -1 )
                tarjan_scc(i);
    }
    return 0;
}
