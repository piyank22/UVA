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
#define ten9 1000000000
#define mod 1000000007
#define zero(x) memset(&x,0,sizeof(x))
#define minus(x) memset(&x,0xff,sizeof(x))
#define boost cin.tie(0); ios_base::sync_with_stdio(0) ; 
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

int n,s,t,m;
vvi adj;
int res[110][110];
vi parent;
vi vis;
int flow,max_flow;

void augument_path(int u, int min_edge)
{
    if(u==s)    flow = min_edge;
    else if( parent[u] != -1 )
    {
        augument_path( parent[u] , min( min_edge , res[parent[u]][u] ) );
        res[ parent[u] ][u] -= flow;
        res[u][ parent[u] ] += flow;
    }
}

int main()
{   
    boost
    int tc=1;
    while( cin >> n , n )
    {
        zero(res);
        adj.assign(n,vi());
        max_flow = 0;
        flow = 0;

        cin >> s >> t >> m;
        s--;    t--;
        while( m-- )
        {
            int u,v,c;
            cin >> u >> v >> c;
            u--;    v--;
            res[u][v] += c;
            res[v][u] += c;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        while(1)
        {
            vis.assign(n,0);
            vis[s]=1;
            parent.assign(n,-1);
            queue<int> q;
            q.push(s);

            while( !q.empty() )
            {
                int u = q.front();  q.pop();
                if(u==t)    break;
                for( auto v: adj[u] )
                    if( !vis[v] && res[u][v]>0 )
                    {
                        parent[v]=u;
                        q.push(v);
                        vis[v]=true;
                    }
            }

            flow = 0;
            augument_path(t,1e9);
            if( flow == 0 ) break;
            max_flow += flow;
        }
        cout << "Network " << tc++ << "\nThe bandwidth is " << max_flow << ".\n\n";
    }   
    return 0;
}

