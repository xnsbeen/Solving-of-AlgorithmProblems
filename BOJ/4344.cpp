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
#include <set>
using namespace std;
int main(int argc, char* argv[]) {
	double arr[1001];
	int test;
	cin>>test;
	while(test--){
		int n;
		double sum=0;
		double cnt=0;
		double ratio;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>arr[i];
			sum+=arr[i];
		}
		for(int i=0;i<n;++i)
			if(sum/n<arr[i]) cnt++;
		ratio = 100*cnt/n;
		cout<<fixed; // 소숫점 아래 자릿수 고정한다.
		cout.precision(3); // 소숫점 아래를 3으로 고정한다.
		cout<<ratio<<'%'<<endl;
	}
	return 0;
}