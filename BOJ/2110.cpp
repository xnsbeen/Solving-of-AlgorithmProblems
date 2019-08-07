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
	int n,m,ans;
	cin>>n>>m;
	vector<int> vec(n);
	for(int i=0;i<n;++i)
		scanf("%d",&vec[i]);
	sort(vec.begin(),vec.end());
	int left = 1;
	int right = vec[vec.size()-1]-vec[0];
	int mid;	
	while(left<=right){
		int cnt=1;
		int wf=vec[0];
		mid = (left+right)/2;
		for(int i=0;i<n;++i){
			if(vec[i]-wf>=mid){
				cnt++;
				wf = vec[i];
			}
		}
		if(cnt>=m)
			left = mid+1;
		else if(cnt<m)
			right = mid-1;
	}
	cout<<left-1<<endl;
	return 0;
}