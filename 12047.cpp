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

int x_dir[4] = { -1,0,1,0}; // standard x-y axis NORTH - EAST - SOUTH - WEST
int y_dir[4] = { 0,1,0,-1};

vi call_dijkstra( vector< vii > &adj , int n , int st )
{
    vi dis(n,1e9);
    dis[st]=0;
    priority_queue< ii , vii , greater<ii> > pq;
    pq.push( mp(0,st) );
    while( !pq.empty() )
    {
        ii tr = pq.top();   pq.pop();
        int u = tr.yy;
        int d = tr.xx;
        if( d > dis[u] )    continue;

        for( auto rt: adj[u] )
        {
            int v = rt.xx;
            int w = rt.yy;
            if( dis[v] > dis[u] + w )
            {
                dis[v] = dis[u] + w;
                pq.push( mp(dis[v],v) );
            }
        }
    }
    return dis;
}

int main()
{   
    boost 
    test_case
    {
        int n,m,s,t,p;
        cin >> n >> m >> s >> t >> p;
        s--; t--;

        vector< vii >   adj_for(n,vii());
        vector< vii >   adj_rev(n,vii());
        vi              dis_for(n,1e9);
        vi              dis_rev(n,1e9);

        forr(i,1,m)
        {
            int u,v,w;
            cin >> u >> v >> w;
            u--; v--;
            adj_for[u].pb( mp(v,w) );
            adj_rev[v].pb( mp(u,w) );
        }

        dis_for = call_dijkstra( adj_for , n , s);
        dis_rev = call_dijkstra( adj_rev , n , t);

        int ans = -1;
        forr(i,0,n-1)
        {
            int w1,w2,w3;
            w1 = dis_for[i];
            for( auto v:adj_for[i] )
            {
                w2 = v.yy;
                w3 = dis_rev[v.xx];
                if( w1 + w2 + w3 <= p && ans < w2 )
                    ans = w2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
