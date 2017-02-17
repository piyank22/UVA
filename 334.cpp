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

int nn,n,m;
map<string,int> for_map;
map<int,string> rev_map;
string s;
int mat[410][410];

int main()
{   
    boost 
    int tc = 1;
    while( cin >> nn , nn )
    {
        zero(mat);
        for_map.clear();
        rev_map.clear();
        n = 0;
        forr(i,0,nn-1)
        {   
            cin >> m;
            if(m==0)    continue;
            getline(cin,s);
            stringstream ss(s);
            string temp;
            while( ss >> temp )
                if( for_map.find(temp) == for_map.end() )
                {
                    for_map[temp] = n;
                    rev_map[n] = temp;
                    n++;
                }

            stringstream sss(s);
            int u;
            int v;
            sss >> temp;
            u = for_map[temp];
            while( sss >> temp )
            {
                v = for_map[temp];
                mat[u][v] = 1;
                u = v;
            }
        }

        cin >> nn;
        while(nn--)
        {
            string temp,remt;
            cin >> temp >> remt;
            int u = for_map[temp] , v =for_map[remt];
            mat[u][v] = 1;
        }

        forr(k,0,n-1)
            forr(i,0,n-1)
                forr(j,0,n-1)
                    mat[i][j] = mat[i][j] | ( mat[i][k] & mat[k][j] );

        vii  ans;
        forr(i,0,n-1)
            forr(j,i+1,n-1)
                if( mat[i][j]==0 && mat[j][i]==0 )
                    ans.pb(mp(i,j));

        cout << "Case " << tc++ << ", ";
        if( !sz(ans) )   cout << "no concurrent events.\n";
        else
        {
            cout << sz(ans) << " concurrent events:\n";
            forr(i,0,min(sz(ans),2)-1)
            {
                ii a = ans[i];
                cout << "(" << rev_map[a.xx] << "," << rev_map[a.yy] << ") ";
            }
            cout << endl;
        }
    }

    return 0;
}
