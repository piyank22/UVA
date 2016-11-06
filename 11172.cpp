#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

#define PI acos(-1)
#define ll long long

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(a>b)
			printf(">\n");
		else if(a<b)
			printf("<\n");
		else
			printf("=\n");
	}
	return 0;
}