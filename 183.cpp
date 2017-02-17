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

int n,m;
string s;
int pos;
string ans;
char arr[110][110];

void solve(int ss,int t,int n, int m)
{
    if( ss>n || t>m )  return;
    pos++;
    if(s[pos]=='1'||s[pos]=='0')
    {
        forr(i,ss,n)     forr(j,t,m)
        {
            arr[i][j] = s[pos];
        }
    }
    else
    {

        int n1 = (n+ss)/2;
        int m1 = (m+t)/2;

        solve(ss,t,n1,m1);
        solve(ss,m1+1,n1,m);
        solve(n1+1,t,n,m1);
        solve(n1+1,m1+1,n,m);
    }
}

void solve_a(int st,int en,int n,int m)
{
    if(n==0||m==0)  return;
    int c=0;
    forr(i,st,n+st-1)   forr(j,en,m+en-1)   c+=arr[i][j]-'0';
    if(c==0)
    {
        ans+="0";
        return;
    }
    if(c==n*m)
    {
        ans+="1";
        return;
    }

    ans+="D";
    int n1 = ceil(n/2.0);
    int m1 = ceil(m/2.0);

    solve_a(st,en,n1,m1);
    solve_a(st,en+m1,n1,m-m1);
    solve_a(st+n1,en,n-n1,m1);
    solve_a(st+n1,en+m1,n-n1,m-m1);
}

int main()
{
    char a;
    cin >> a;
    
    while(cin >> n >> m)
    {
        int nn,mm;
        printf("%c%4d%4d\n",(a=='D'?'B':'D'),n,m );
        if( a=='D')
        {
            s="";
            while(1)     
            {   
                string c;
                cin >> c;
                if((c[0]=='D'&&sz(c)==1 )||c[0]=='B'||c[0]=='#')
                {
                    a=c[0];
                    break;
                }
                s+=c;
            }
            ans = "";
            pos=-1;
            solve(1,1,n,m);
            forr(i,1,n) forr(j,1,m) ans += arr[i][j];
        }
        else
        {
            ans = "";
            int pos=0;
            forr(i,1,n) forr(j,1,m)     cin>>arr[i][j];
            solve_a(1,1,n,m);
            cin>>a;
        }
        int pr=0;
        while(pr<sz(ans))
        {
            cout<< ans[pr++];
            if(pr%50==0 || pr==sz(ans))    cout<<endl;
        }
        if(a=='#')
            break;
    }
    return 0;
}