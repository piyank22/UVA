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
#define infinity(x) memset(&x,0x3f,sizeof(x))
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

vvii adj;
list<int> tour;

vi degree,parent;
int n;

void euler_tour( list<int>::iterator it , int u )
{
    for( auto &v: adj[u] )
    {
        if( v.yy )
        {
            v.yy = 0;
            for( auto &w: adj[v.xx] )
                if( w.xx == u and w.yy )
                {
                    w.yy = 0;
                    break;
                }
            euler_tour( tour.insert(it,u) , v.xx );
        }
    }
}

int find(int u) { return ( parent[u]==u ? u : find(parent[u]) ); }

int main()
{
    boost
    test_case
    {
        if( tc!=1 ) cout << endl;
        cout << "Case #" << tc << "\n"; 

        cin >> n;
        adj.assign(50,vii());
        degree.assign(50,0);
        parent.assign(50,0);

        forr(i,0,49)    parent[i]=i;
        
        forr(i,1,n)
        {
            int u,v;
            cin >> u >> v;
            u--;    v--;
            adj[u].pb( mp(v,1) ) , adj[v].pb( mp(u,1) );
            degree[u]++;
            degree[v]++;
            if( find(u) != find(v) )    parent[find(u)] = find(v);
        }

        tour = list<int>();

        bool flag = false;
        int start = -1;

        forr(i,0,49)    
            if( degree[i]%2 )   flag = true;
        
        set<int> check_connected;
        forr(i,0,49)
            if( degree[i] )
            {
                if( start == -1 )   start = i;
                check_connected.insert( find(i) );
            }

        if( sz(check_connected) != 1 )
            flag = true;

        if( !flag )
        {
            euler_tour( tour.begin() , start );
            for( auto x: tour )
            {
                cout << start+1 << " " << x+1 << "\n";
                start = x;
            }
        }
        else
            cout << "some beads may be lost\n";
    }
    return 0;
}

