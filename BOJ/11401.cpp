#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <math.h>
#include <sstream>

using namespace std;

int C = 1000000007;

long long int power(int n,int k){
	if(k==0) return 1;
	long long int temp = power(n,k/2);
	if(k%2==0) return temp*temp%C;
	else return ((temp*temp)%C*n)%C;
	
}

int main(int argc, char* argv[]) {
	int n,k;
	long long int top,bot;
	top=bot=1;
	cin>>n>>k;
	for(int i=n;i>=n-k+1;--i)
		top=(top*i)%C;
	for(int i=k;i>=1;--i)
		bot=(bot*i)%C;
	
	cout<<((top%C)*(power(bot,C-2)%C))%C<<endl;
	
	return 0;
}
d