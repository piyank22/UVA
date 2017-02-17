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
#define mod 20437
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

int n;
int __root;
int max_dis;

vi degree , dist;
set<int> maxi_vec;
vvi adj;

void dfs( int u, int p)
{
    dist[u] = dist[p]+1;
    max_dis = max(max_dis,dist[u]);
    for( auto v: adj[u] )
        if( v != p )
            dfs(v,u);
}

void calulate_best_root()
{
    int maxi=0;
    queue<int> q;
    dist.assign(n+1,inf);
    forr(i,1,n) if(degree[i]==1)    q.push(i) , dist[i]=0; 

    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for( auto v: adj[u] )
        {
            if( --degree[v] == 1 )
            {
                q.push(v);
                dist[v] = dist[u]+1;
                maxi = max(maxi,dist[v]);
            }
        }
    }

    forr(i,1,n) if( dist[i]==maxi ) cout << " " << i , __root = i; 
    // there can be at max two different parents
}

void calulate_worst_root()
{
    max_dis = 1;
    dist.assign(n+1,0);
    
    dfs( __root , 0 );
    // cout << dist << endl;
    forr(i,1,n) if( dist[i] == max_dis )    maxi_vec.insert(i) , __root = i;

    max_dis = 1;
    dist.assign(n+1,0);
    dfs( __root , 0 );
    // cout << dist << endl;
    forr(i,1,n) if( dist[i] == max_dis )    maxi_vec.insert(i);
}

int main()
{     
    // boost
    while( cin >> n )
    {
        adj = vvi(n+1);
        degree = vi(n+1);
        forr(i,1,n)
        {
            cin >> degree[i];
            forr(k,0,degree[i]-1)
            {
                int v;
                cin >> v;
                adj[i].pb(v);
            }
        }

        cout << "Best Roots  :" ;
        calulate_best_root();

        cout << "\nWorst Roots :" ;
        maxi_vec = set<int>();
        calulate_worst_root();
        for( auto b: maxi_vec ) cout << " " << b;   cout << endl;
    }
    return 0;
}

