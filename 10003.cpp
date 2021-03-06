// #include <iostream>
// #include <cstdio>
// #include <math.h>
// #include <ctime>
// #include <cstring>
// #include <sstream>
// #include <algorithm>
// #include <stack>
// #include <queue>
// #include <list>
// #include <map>
// #include <set>
// #include <vector>

// #define PI acos(-1)
// #define endl '\n'
// #define ll long long
// #define llu long long unsigned
// #define pii pair<int,int>
// #define vi vector<int>
// #define mp make_pair
// #define pb push_back
// #define eb emplace_back
// #define xx first
// #define yy second
// #define sz(v) int(v.size())
// #define eps 1e-5
// #define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
// #define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
// #define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
// #define all(v) (v).begin(),(v).end()
// #define INF 0x3fffffff
// #define ten9 1000000000
// #define mod 1000000007
// #define zero(x) memset(&x,0,sizeof(x))
// #define minus(x) memset(&x,0xff,sizeof(x))
// #define trace1(x) cerr<<#x<<" = "<<x<<endl;
// #define trace2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
// #define trace3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<endl;

// using namespace std;

// template<class T, class U>
// ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
// template<class T>
// ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
// template<class T>
// ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
// template<class T>
// ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
// template<class T, class U>
// ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
// template<class T, class U>
// ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

// const int max_n = 2e4+40;
// int d[max_n] , h[max_n];

// int main()
// {
// 	// ios_base::sync_with_stdio(false);
// 	// cin.tie(NULL);

// 	int n,m;
// 	for(int i=1;i<=(int)1e9;i++) { ; }
// 	return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int l, n, A[55], memo[55][55] , root[55][55];

int cut() 
{
  for(int d=3;d<=n+1;d++)
  {
    for(int i=0;i<=n+1-d;i++)
    {
      int j=i+d;
      memo[i][j]=2e9;
      for( int rt = root[i][j-1] ; rt<=root[i+1][j] ; rt++ )
      {
        int cost = 0;
        cost += A[j] - A[i];
        cost += memo[i][rt];
        cost += memo[rt][j];
        if( memo[i][j] > cost)
          memo[i][j] = cost , root[i][j]=rt;
      }
    }
  }
  return memo[0][n+1];
}

int main() 
{
  while (scanf("%d", &l), l) 
  {
    A[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    A[n + 1] = l;

    memset(memo,  0, sizeof memo);
    memset(root,  0, sizeof root);
    for(int i=0;i<=n-1;i++) root[i][i+2] = i+1 , memo[i][i+2] = A[i+2]-A[i] ;
    printf("The minimum cutting is %d.\n", cut());
  }

  return 0;
}

// /*******************
// AUTHOR: HUMBLE_LOSER
// *******************/

// #include <iostream>
// #include <cstdio>
// #include <math.h>
// #include <ctime>
// #include <bitset>
// #include <iomanip>
// #include <cstring>
// #include <sstream>
// #include <algorithm>
// #include <stack>
// #include <queue>
// #include <list>
// #include <map>
// #include <set>
// #include <vector>

// using namespace std;

// #define PI acos(-1)
// #define EXP 2.7182818284590452353602874713527
// #define endl '\n'
// #define ll long long
// #define llu long long unsigned
// #define ii pair<int,int>
// #define vi vector<int>
// #define vii vector<ii>
// #define vvi vector<vi>
// #define vvii vector<vii>
// #define mp make_pair
// #define pb push_back
// #define eb emplace_back
// #define xx first
// #define yy second
// #define sz(v) int(v.size())
// #define eps 1e-5
// #define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
// #define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
// #define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
// #define all(v) (v).begin(),(v).end()
// #define inf 0x3f3f3f3f
// #define mod 20437
// #define zero(x) memset(&x,0,sizeof(x))
// #define minus(x) memset(&x,0xff,sizeof(x))
// #define boost cin.tie(0); ios_base::sync_with_stdio(0); 
// #define trace1(x) cerr << #x <<" = "<< x <<endl;
// #define trace2(x,y) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<endl;
// #define trace3(x,y,z) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<" , "<< #z <<" = "<< z <<endl;
// #define trace_arr(a,i,n) cerr << #a <<" : " ; forr(_i,i,n) cerr << a[_i] << " "; cerr << endl;
// #define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n){forr(_j,j,m) cerr << setw(6) << a[_i][_j] << " "; cerr << endl;}cerr<<endl;
// #define test_case int __T;cin >> __T; forr(tc, 1 , __T)     

// template<class T, class U>
// ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
// template<class T>
// ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
// template<class T>
// ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
// template<class T>
// ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
// template<class T, class U>
// ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
// template<class T, class U>
// ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

// int x_dir[4] = { -1,0,1,0}; // standard x-y axis NORTH - EAST - SOUTH - WEST
// int y_dir[4] = { 0,1,0,-1};

// int l,n;
// int arr[55];

// int parent[55][55] , dp[55][55];

// void solve()
// {
//     zero(parent);   zero(dp);
//     forr(i,0,n-1)   parent[i][i+2] = i+1 , dp[i][i+2] = arr[i+2]-arr[i];

//     forr(len,3,n+1)
//     {
//         forr(i,0,n-len+1)
//         {
//             int j = i+len;
//             dp[i][j] = inf;
//             int vv = arr[j] - arr[i];
//             forr( par , parent[i][j-1] , parent[i+1][j] )
//             {
//                 if ( vv + dp[i][par] + dp[par][j] < dp[i][j] )
//                 {
//                     parent[i][j] = par;
//                     dp[i][j] = vv + dp[i][par] + dp[par][j];
//                 }
//             }
//         }
//     }
// }

// int main()
// {     
//     // boost
//     while( cin >> l , l)
//     {
//         cin >> n;
//         forr(i,1,n)     cin >> arr[i];
//         arr[0] = 0;     arr[n+1] = l;
//         solve();
//         cout << "The minimum cutting is " << dp[0][n+1] << ".\n";
//     }

//     return 0;
// }

