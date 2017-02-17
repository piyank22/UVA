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
    // cout << "Adding edge between " << u << " to " << v << " of capacity " << cap << endl; 
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
    // trace2(u,max_flow);
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
        // cout << "new one\n";
        if( !bfs() )   break;
        ptr.assign(n,0);
        while(ll pushed = dfs(s,inf) )
            flow += pushed ;//,trace1(pushed) ;
    }
    return flow;
}

/*************************************************************************************************************************
*************************************************************************************************************************/

int x_cordinate[110];
int y_cordinate[110];
int num_of_peng[110];
int max_jmp_off[110];

inline int get_node_in(int k)
{
    return 2*k-1;
}

inline int get_node_out(int k)
{
    return 2*k;
}

int main()
{   
    boost 
    test_case
    {
        int num;
        double dis;
        cin >> num >> dis;
        
        n = 2*num+1;
        
        adj.assign(n,vi());
        edge_list.clear();
        s = 0;

        int totol_no_peng = 0;

        forr(k,1,num)
        {
            cin >> x_cordinate[k] >> y_cordinate[k] >> num_of_peng[k] >> max_jmp_off[k];

            totol_no_peng += num_of_peng[k];

            int node_in = get_node_in(k);
            int node_out = get_node_out(k);
            
            add_edge( node_in , node_out , max_jmp_off[k] );

            if( num_of_peng[k] )    add_edge( s , node_in , num_of_peng[k] );
        }

        forr(k,1,num)
            forr(kl,1,num)
            {
                if( k==kl ) continue;
                double apart = hypot( x_cordinate[k] - x_cordinate[kl] , y_cordinate[k] - y_cordinate[kl] );
                if( apart <= dis + eps )
                {
                    // node_out of k to node_in of kl
                    // node_out of kl to node_in of k
                    add_edge( get_node_out(k) , get_node_in(kl) , inf );
                    add_edge( get_node_out(kl) , get_node_in(k) , inf );
                }
            }

        vi  ans;
        vvi adj_calculated = adj;
        vector<edge> edge_list_calculated = edge_list;

        forr(k,1,num)
        {
            adj = adj_calculated;
            edge_list = edge_list_calculated;
            t = get_node_in(k);
            if( dinic_algorithm_max_flow() == totol_no_peng )   ans.pb(k-1);
        }

        if( sz(ans) )
        {
            forr(i,0,sz(ans)-1)
                cout << ans[i] << " \n"[i==sz(ans)-1];
        }
        else            cout << "-1\n";
    }
    
    return 0;
}

