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
		cout<<round(ratio*1000)/1000<<'%'<<endl;
	}
	return 0;
}