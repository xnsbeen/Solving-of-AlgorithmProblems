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
/*	10^n으로 나눈 나머지를 구하는 경우 pisano period를 생각해볼 수 있다.
	나눌 수를 k라고 할 때 k=10^n이면 피사노 주기는 15*10^(n-1)이다.
	따라서 이 문제는 1,000,000으로 나누므로 n은 5이고 주기는 1,500,000이다.
*/
int main(int argc, char* argv[]) {
	//pisano period 1500000;
	int arr[1500001];
	int mod = 1000000;
	int pisano = 1500000;
	long long int n;
	arr[0]=0;
	arr[1]=1;
	cin>>n;
	for(int i=2;i<=1500000;++i)
		arr[i] = (arr[i-1]+arr[i-2])%mod;
	cout<<arr[n%pisano]<<endl;
	return 0;
}