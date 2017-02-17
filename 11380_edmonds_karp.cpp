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

int res[1805][1805];
string ocean[33];

int r,c,p;
int get_node_in( int i ,int j)
{
    return 2*(i*c+j)+1;
}
int get_node_out( int i, int j)
{
    return 2*(i*c+j)+2;
}

/////////////////////////////////////////////////////////////////////
/* EDMONDS KARP IMPLEMENTATION */
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

int n,s,t;
int flow;
int max_flow;
vi parent, vis;
vvi adj;

void augument_path( int v, int min_edge)
{
    if( v==0 )  flow = min_edge;
    else if( parent[v]!=-1 )
    {
        augument_path(parent[v] , min( min_edge , res[parent[v]][v] ) );
        res[ parent[v] ][v] -= flow;
        res[v][ parent[v] ] += flow;
    }
}

void print_path( int v)
{
    if(v==0) cout << v << "\t";
    else if( parent[v] != -1 )
    {
        print_path( parent[v] );
        cout << v << "\t";
    }
}

int edmonds_karp()
{
    max_flow = 0;
    while(1)
    {
        parent.assign(n,-1);
        vis.assign(n,0);
        vis[s]=1;

        queue<int> q;
        q.push(s);

        while(!q.empty())
        {
            int u = q.front();  q.pop();
            if( u==t )  break;
            for( auto v: adj[u] )
                if( !vis[v] && res[u][v] > 0 )
                {
                    vis[v]=1;
                    q.push(v);
                    parent[v]=u;
                }
        }

        flow = 0;
        augument_path(1801,inf);
        // trace1(flow);
        // print_path(1801);
        if( flow == 0 ) break;
        max_flow += flow;
    }
    return max_flow;
}

/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

int main()
{   
    while( cin >> r >> c >> p )
    {
        zero(res);
        adj.assign(1805,vi());

        string str;
        getline(cin,str);
        forr(i,0,r-1)
        {
            getline(cin,str);
            ocean[i]=str;
            forr(j,0,c-1)
            {
                int node_in = get_node_in(i,j);
                int node_out= get_node_out(i,j);
                if( str[j] == '~' )     continue;
                else if( str[j] == '.' || str[j] == '*' )
                    res[node_in][node_out] = 1;
                else
                    res[node_in][node_out] = inf;

                adj[node_in].pb(node_out);
                adj[node_out].pb(node_in);
            }
        }

        forr(i,0,r-1)   forr(j,0,c-1)
            forr(dir,0,3)
            {
                int i1 = i + x_dir[dir];
                int j1 = j + y_dir[dir];
                if( i1<0 || i1>=r || j1<0 || j1>=c || ocean[i][j]=='~' || ocean[i1][j1]=='~' )  continue;
                int node1 = get_node_out(i,j);
                int node2 = get_node_in(i1,j1);
                res[node1][node2] = inf;

                adj[node1].pb(node2);   adj[node2].pb(node1);
                
                if( ocean[i][j] == '*' )    res[0][node1-1] = inf       , adj[0].pb(node1-1) , adj[node1-1].pb(0);
                if( ocean[i][j] == '#' )    res[node1][1801] = p    , adj[node1].pb(1801) , adj[1801].pb(node1);
            }
            
        // no of nodes , source , sink
        n = 1802;
        s = 0;
        t = 1801;
        cout << edmonds_karp() << endl;
    }
    
    return 0;
}

