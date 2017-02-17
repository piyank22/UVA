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

string str;
int cnt;
map<int,int> m;
vi adj[25];
char mapping[25];
int visited[25];

bool no_back_edge(int u)
{
    for( auto v : adj[u] )
        if( visited[v] )    return false;
    return true;
}

bool solve(string str)
{
    if( str.size() == cnt )
    {
        forr(i,0,cnt-1)
            cout << str[i] << " \n"[i==cnt-1];
        return true;
    }

    bool ans = false;
    forr(i,0,cnt-1)
    {
        if( !visited[i] && no_back_edge(i) )
        {
            visited[i] = true;
            ans = solve(str+mapping[i]) || ans;
            visited[i] = false;
        }
    }

    return ans;
}

int main()
{   
    int tc;
    scanf("%d\n\n",&tc);
    while(tc--)
    {
        m.clear();
        forr(i,0,24)    adj[i].clear();

        getline(cin,str);
        stringstream ss(str);
        cnt = 0;
        char a;

        set<char> temp;
        temp.clear();
        while( ss >> a )
            temp.insert(a);

        for( auto a: temp)
        {
            m[a] = cnt;
            mapping[cnt] = a;
            cnt++;
        }

        getline(cin,str);
        stringstream sss(str);
        while( sss >> str )
            adj[ m[str[0]] ].pb( m[str[2]] );

        zero(visited); // all white

        if( !solve("") )
            cout<<"NO\n";

        if(tc)  cout<<endl;

        getline(cin,str);
    }
    
    return 0;
}
