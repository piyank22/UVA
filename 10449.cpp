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

int n,m,q;
vector< pair<ii,int> > edge_list;
vi dis;
int busy[210];

int main()
{   
    boost 
    int tc=1;
    while( cin >> n )
    {
        forr(i,0,n-1)   cin >> busy[i];

        cin >> m;
        edge_list.clear();
        forr(i,0,m-1)
        {
            int u,v,w;
            cin >> u >> v;  u--; v--;
            w = busy[v]-busy[u];
            w = w*w*w;
            edge_list.pb( mp( mp(u,v) , w ) );
        }

        dis.assign(n+1,1e9);
        dis[0]=0;
        forr(i,1,n-1)
            for( auto e: edge_list)
            {
                int u = e.xx.xx;
                int v = e.xx.yy;
                int w = e.yy;
                if( dis[v] > dis[u] + w && dis[u]!=1e9 )
                    dis[v] = dis[u] + w;
            }

        forr(i,1,n)
            for( auto e: edge_list)
            {
                int u = e.xx.xx;
                int v = e.xx.yy;
                int w = e.yy;
                if( dis[v] > dis[u] + w && dis[u]!=1e9 )
                    dis[v] = -1e9;
            }

        cout << "Set #" << tc++ << "\n";
        cin >> q;
        while(q--)
        {
            int v;
            cin >> v;
            v--;
            if( dis[v] < 3 || dis[v] == 1e9 )   cout << "?\n";
            else                                cout << dis[v] << endl;
        }

    } 
    return 0;
}
