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

#define PI acos(-1)
#define EXP 2.7182818284590452353602874713527
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define pii pair<int,int>
#define vi vector<int>
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
#define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n) { forr(_j,j,m) cerr << a[_i][_j] << " "; cerr << endl; } cerr << endl;
#define test_case int __T;cin >> __T; forr(tc, 1 , __T)		

using namespace std;

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

ll n,m,k;
ll ar[120][120];

int main()
{
    int T;
    cin >> T;
    forr(tc,1,T)
    {
        cin >> n >> m >> k;
        forr(i,1,n) forr(j,1,m)
        {
            cin >> ar[i][j];
            ar[i][j] += ar[i][j-1];
        }

        ll max_area = 0;
        ll cost = 0;
        forr(j1,1,m) forr(j2,j1,m)
        {
            ll curr_area = j2-j1+1;
            ll temp_area = 0;
            ll temp_cost = 0;

            ll runn_cost=0;
            ll runn_area=0;
            ll curr_cost;
            forr(jj,1,n)
            {   
                runn_cost = runn_area = 0;
                forr(i,jj,n)
                {
                    curr_cost = ar[i][j2]-ar[i][j1-1];
                    if(runn_cost+curr_cost<=k)
                    {
                        runn_area += curr_area;
                        runn_cost += curr_cost;
                    }
                    else if(curr_cost<=k)
                    {
                        runn_area = curr_area;
                        runn_cost = curr_cost;
                    }
                    else
                    {
                        runn_area = 0;
                        runn_cost = 0;
                    }
                    
                    if(temp_area<runn_area || (temp_area==runn_area && runn_cost<temp_cost))     
                        temp_area = runn_area , temp_cost = runn_cost;
                }
                if(max_area<temp_area || (max_area==temp_area && temp_cost<cost))          
                    max_area  = temp_area , cost = temp_cost;
            }
        }
        cout<<"Case #"<<tc<<": "<< max_area <<" "<< cost <<"\n";   
    }
    return 0;
}