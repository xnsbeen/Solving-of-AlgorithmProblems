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
	int n,k,ans;
	cin>>n>>k;
	int left = 1;
	int right = k;
	int mid;
	while(left<=right){
		mid = (left+right)/2;
		int cnt = 0;
		for(int i=1;i<=n;++i)
			cnt+=min(n,mid/i);
		if(cnt>=k){
			ans=mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}