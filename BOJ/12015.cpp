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
	int n;
	cin>>n;
	vector<int>vec(n);
	vector<int>ans;
	for(int i=0;i<n;++i)
		scanf("%d",&vec[i]);
	ans.push_back(vec[0]);
	for(int i=1;i<n;++i){
		if(ans[ans.size()-1]<vec[i])
			ans.push_back(vec[i]);
		else{ 
			int pos = lower_bound(ans.begin(),ans.end(),vec[i])-ans.begin();
			ans[pos]=vec[i];
		}
	}
	cout<<ans.size()<<endl;
	return 0;
}