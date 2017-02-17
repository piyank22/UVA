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

string str;
int no_of_users;
int res[50][50];
vi parent;
int flow;

void augument_path(int v,int minEdge)
{
    if(v==0)    { flow = minEdge ; return; }
    else if( parent[v] != -1 )
    {
        augument_path( parent[v],min( minEdge , res[parent[v]][v] ) );
        res[parent[v]][v] -= flow;
        res[v][parent[v]] += flow;
    }
}

int main()
{   
    while(getline(cin,str))
    {
        zero(res);
        no_of_users = 0;

        do
        {
            stringstream ss(str);
            char t;
            ss >> t;
            int u = t-'A'+1;
            ss >> t;
            no_of_users += t-'0';
            res[0][u] = t-'0';
            while( ss >> t , t!=';')
            {
                int v = t-'0'+27;
                res[u][v] = 1;
            }

        }while(getline(cin,str),str!="");

        forr(i,27,36)   res[i][37]=1;

        string ans = "----------";

        int max_flow=0;
        while(1)
        {
            queue<int> q;
            q.push(0);
            vector<bool> vis(38,false);
            parent.assign(38,-1);
            vis[0]=true;
            while( !q.empty() )
            {
                int u=q.front();        q.pop();
                if(u==37) break;
                forr(v,0,37)
                    if(res[u][v]>0 && !vis[v])
                    {
                        vis[v]=true;
                        parent[v]=u;
                        q.push(v);
                    }
            }
            flow=0;
            augument_path(37,100); // 100 is my infinity
            if( flow == 0 ) break;
            max_flow += flow;
        }
        if( max_flow != no_of_users )   cout << "!\n";
        else
        {
            forr(i,27,36) 
            {
                bool alloc = false;
                forr(j,1,26)
                {
                    if (res[i][j]) 
                    {
                        printf("%c", j + 'A' - 1);
                        alloc = true;
                        break;
                    }
                }   
                if (!alloc)
                    printf("_");
            }
            printf("\n");
        }
    }
    return 0;
}

