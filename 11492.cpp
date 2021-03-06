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

int n;
int m;
map<string,int> for_map;
string start_str , end_str;
vector<vii> adj;
int dis[26*4000+100];

int main()
{   
    boost
    while( cin >> m , m )
    {
        adj.assign( 26*4000 , vii() );
        for_map.clear();
        cin >> start_str >> end_str;
        n = 0;
        forr(i,0,m-1)
        {
            string a,b,c;
            cin >> a >> b >> c;
            int u,v;
            if( for_map.find(a) == for_map.end() )
            {    for_map[a] = n ; u = n ; n = n+26; }
            else 
                u = for_map[a];

            if( for_map.find(b) == for_map.end() )
            {    for_map[b] = n ; v = n ; n = n+26; }
            else
                v = for_map[b];

            int char_val = c[0]-97; 
            forr(k,0,25)
            {
                if(k==char_val) continue;
                adj[u+k].pb( mp( v+char_val,sz(c) ) );
                adj[v+k].pb( mp( u+char_val,sz(c) ) );
            }
        }

        priority_queue< ii , vii , greater<ii> > pq;

        forr(i,0,n-1)   dis[i] = 1e9;
        int start_index = ( for_map.find(start_str) == for_map.end() ? -1 : for_map[start_str] );

        if( start_index != -1 )
        {
            forr(i,0,25)
            {
                dis[start_index+i] = 0;
                pq.push( mp(0,start_index+i) );
            }

            while( !pq.empty() )
            {
                ii te = pq.top();   pq.pop();
                int d = te.xx;
                int u = te.yy;
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
        }

        int ans = 1e9;
        int end_index = ( for_map.find(end_str) == for_map.end() ? -1 : for_map[end_str] );
        if( end_index!=-1)
        {
            forr(i,0,25)
                ans = min(ans,dis[i+end_index]);
        }
        if( ans == 1e9 )    cout << "impossivel\n";
        else                cout << ans << endl;
    } 

    return 0;
}
