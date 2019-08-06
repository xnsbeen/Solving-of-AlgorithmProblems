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
#include <limits.h>
using namespace std;

int main(int argc, char* argv[]) {
	int n,k;
	cin>>n>>k;
	vector<int> vec(n);
	for(int i=0;i<n;++i)
		scanf("%d",&vec[i]);
	sort(vec.begin(),vec.end());
	long long left = 0;
	long long right = LLONG_MAX;
	long long mid;	
	while(left<=right){
		long long cnt=0;
		mid = (left+right)/2;
		for(int i=0;i<n;++i)
			cnt+=vec[i]/mid;
		if(cnt<k)
			right = mid-1;
		else if(cnt>=k)
			left = mid+1;
	}
	cout<<right<<endl;
	return 0;
}