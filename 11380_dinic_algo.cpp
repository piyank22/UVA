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


/*************************************************************************************************************************
AUTHOR: PIYANK SARAWAGI
        HUMBLE_LOSER
*************************************************************************************************************************/

//    MAX FLOW TEMPLATE

// #define inf 1e9 // incase of long long required do 1LL << 55 and change int to long long accordingly

struct edge
{
    int a,b,cap,flow;
    edge(int _a,int _b,int _cap,int _flow) : a(_a) , b(_b) , cap(_cap) , flow(_flow) { }
};

vector<edge> edge_list;
vvi adj;

vi dis , ptr; // distance , ptr is the pointer which is to keep track that we do not traverse the same path again and again in dfs
int n;   // no of nodes in our flow network
int s,t;    // source and sink

void initialize_max_flow(int _n,int source, int sink)
{
    n = _n;
    adj.assign(n,vi());
    edge_list.clear();
    s = source;
    t = sink;
}

void add_edge(int u,int v,int cap)
{
    edge e1 = edge(u,v,cap,0);
    edge e2 = edge(v,u,0,0);        // if bidirectional make its capacity also equal to cap
    adj[u].pb(sz(edge_list));   edge_list.pb(e1);
    adj[v].pb(sz(edge_list));   edge_list.pb(e2);
}

bool bfs()
{
    queue<int> q;
    q.push(s);
    dis.assign(n,-1);
    dis[s]=0;
    while( !q.empty() && dis.at(t)==-1 )
    {
        int u = q.front();  q.pop();
        for( auto id: adj[u] )
        {
            int v = edge_list[id].b;
            if( dis[v]==-1 and edge_list[id].flow < edge_list[id].cap )
            {
                q.push(v);
                dis[v] = dis[u]+1;
            }
        }
    }
    return ( dis[t] != -1 );
}

int dfs(int u,int max_flow)
{
    if(max_flow==0)     return 0;
    if(u==t)            return max_flow;

    for( ; ptr[u] < sz(adj[u]) ; ++ptr[u] )
    {
        int id = adj[u][ptr[u]];
        int v  = edge_list[id].b;
        if( dis[v] != dis[u] + 1 )  continue;
        int pushed = dfs( v , min( max_flow , edge_list[id].cap - edge_list[id].flow ) );
        if( pushed )
        {
            edge_list[id].flow += pushed;
            edge_list[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

ll dinic_algorithm_max_flow()
{
    ll flow = 0;
    while(1)
    {
        if( !bfs() )   break;
        ptr.assign(n,0);
        while(ll pushed = dfs(s,inf) )
            flow += pushed ;
    }
    return flow;
}

/*************************************************************************************************************************
*************************************************************************************************************************/



int main()
{   
    while( cin >> r >> c >> p )
    {
        initialize_max_flow(1802,0,1801);

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
                    add_edge(node_in,node_out,1);
                else
                    add_edge(node_in,node_out,inf);
            }
        }
        forr(i,0,r-1)   forr(j,0,c-1)
        {
            int node1 = get_node_out(i,j);
            if( ocean[i][j] == '*' )    add_edge(0,node1-1,inf);
            if( ocean[i][j] == '#' )    add_edge(node1,1801,p);
            
            forr(dir,0,3)
            {
                int i1 = i + x_dir[dir];
                int j1 = j + y_dir[dir];
                if( i1<0 || i1>=r || j1<0 || j1>=c || ocean[i][j]=='~' || ocean[i1][j1]=='~' )  continue;
                int node2 = get_node_in(i1,j1);
                add_edge(node1,node2,inf);
            }    
        }
        cout << dinic_algorithm_max_flow() << endl;
    }
    
    return 0;
}

