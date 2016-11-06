#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
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
#define INF 0x3fffffff
#define ten9 1000000000
#define mod 1000000007
#define zero(x) memset(&x,0,sizeof(x))
#define minus(x) memset(&x,0xff,sizeof(x))
#define trace1(x) cerr<<#x<<" = "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<endl;

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

#define	TwoPi  2*PI
ll A,B,C;
ll x, y, z;
int SolveP3(long double *x,long double a,long double b,long double c) 
{	// solve cubic equation x^3 + a*x^2 + b*x + c
	long double a2 = a*a;
    long double q  = (a2 - 3*b)/9; 
	long double r  = (a*(2*a2-9*b) + 27*c)/54;
    long double r2 = r*r;
	long double q3 = q*q*q;
	long double A,B;
    if(r2<q3) 
    {
        long double t=r/sqrtl(q3);
		if( t<-1) t=-1;
		if( t> 1) t= 1;
        t=acosl(t);
        a/=3; q=-2*sqrtl(q);
        x[0]=q*cosl(t/3)-a;
        x[1]=q*cosl((t+TwoPi)/3)-a;
        x[2]=q*cosl((t-TwoPi)/3)-a;
        return(3);
    } 
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> A >> B >> C;
		bool sol = false; 
		long double x[3];
		ll xx[3];
		SolveP3(x,-A,(A*A-C)/2.0,-B);
			
		forr(i,0,2)
			xx[i] = round(x[i]);

		sort(xx,xx+3);
		if( xx[0]!=xx[1] && xx[1]!=xx[2] && xx[0]!=xx[2] && xx[0]+xx[1]+xx[2]==A && xx[0]*xx[1]*xx[2]==B && xx[0]*xx[0]+xx[2]*xx[2]+xx[1]*xx[1]==C )
			sol=true;
		
		if(sol)
			cout<<xx[0]<<" "<<xx[1]<<" "<<xx[2]<<"\n";
		else
			cout<<"No solution.\n";
	}
	return 0;
}