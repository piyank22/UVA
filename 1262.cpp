#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <bitset>
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

int k;
char a[10][10];
vector< set<int> > b;
vector<char> curr;
set< vector<char> > ans;

bool solve(int pos)
{   
    if(pos==6)
    {
        bool check = true;
        forr(i,1,5) 
            if(b[i].find(curr[i])==b[i].end())
                check = false;
        if(check)
        {
            ans.insert(curr);
            if(sz(ans)==k)
            {
                forr(i,1,5) cout<<curr[i];
                cout<<endl;
                return true;
            }
        }
        return false;
    }
    forr(k,1,6)
    {
        curr[pos]=a[pos][k];
        if(solve(pos+1))    return true;
    }
    return false;
}

int main()
{
    boost
    test_case
    {
        b = vector< set<int> >(6,set<int>());
        curr = vector<char>(6);
        ans.clear();
        cin >> k;
        forr(i,1,6) forr(j,1,5)     cin >> a[j][i];
        forr(i,1,6) forr(j,1,5) 
        {
            char temp;
            cin>> temp;
            b[j].insert(temp);
        }
        forr(i,1,5)     sort(a[i]+1,a[i]+7);
        if(!solve(1))    cout<<"NO\n";
    }
    return 0;
}