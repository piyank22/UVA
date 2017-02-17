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

int n,m,q;
vector< set<ii> > adj;
set< pair< int , ii > > road;

class UNION_FIND
{
public:
    vi parent , size , rank;
    int num_sets;
    UNION_FIND( int n )
    {
        rank.assign(n,0);
        num_sets=n;
        parent.resize(n);
        forr(i,0,n-1)   parent[i] = i;
        size.assign(n,1);
    }
    bool is_same_ds( int u, int v)
    {
        return ( find_ds(u)==find_ds(v) );
    }
    int find_ds( int u )
    {
        return ( parent[u]==u ? u : find_ds(parent[u]) );
    }
    void merge_ds( int u, int v)
    {
        u = find_ds(u);
        v = find_ds(v);
        if( u==v )  return;
        num_sets--;
        if( rank[u]>rank[v] )
        {
            parent[v] = u;
            size[u] += size[v];
        }
        else
        {
            parent[u] = v;
            size[v] += size[u];
        }
        if( rank[u]==rank[v] )
            rank[v]++;
    }
};

int solve( int u , int v , int p )
{
    int ans = 0;
    for( auto q: adj[u] )
    {
        if( q.xx == p ) continue;
        if( q.xx == v )
            return q.yy;
        int t = solve(q.xx,v,u);
        if( t!=0 )
            t = max(t,q.yy);
        ans = max( ans, t );
    }
    return ans;
}

int main()
{   
    boost 
    int tc = 1;
    while( cin >> n >> m >> q , n|m|q )
    {
        if(tc!=1)   cout<<endl;
        road.clear();
        adj = vector< set<ii> >(n,set<ii>());

        forr(i,0,m-1)
        {
            int u , v , w;
            cin >> u >> v >> w;
            u--; v--;
            road.insert( mp(w,mp(u,v)) );
            adj[u].insert( mp(v,w) );
            adj[v].insert( mp(u,w) );
        }

        UNION_FIND uf(n);

        for( auto q: road )
            if( !uf.is_same_ds(q.yy.xx,q.yy.yy) )
                uf.merge_ds(q.yy.xx,q.yy.yy);
            else
            {
                adj[ q.yy.xx ].erase( mp(q.yy.yy,q.xx) );
                adj[ q.yy.yy ].erase( mp(q.yy.xx,q.xx) );
            }

        cout << "Case #" << tc++ << "\n";
        forr(i,0,q-1)
        {
            int u,v;
            cin >> u >> v;
            u--; v--;
            if( !uf.is_same_ds(u,v) )
                cout << "no path\n";
            else 
                cout << solve(u,v,-1) << endl;
        }
    }
    
    return 0;
}
