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
#include <string.h>
using namespace std;
int arr[21][21];
int chk[21];
int n;
int res=1987654321;
/*팀을 반반 나누므로 한팀을 n/2명을 고르게 뽑아낸다. 뽑아낸 인원들의 상호작용 팀점수를 계산한다.
남은 인원들로 이루어진 또 하나의 팀 점수를 계산하여 팀 점수 차이의 최솟값을 추출한다.*/
int dfs(int idx,int size){
	if(size==n/2){
		vector<int> tstart,tlink;
		int start=0,link=0;
		for(int i=0;i<n;++i){
			if(chk[i]) tstart.push_back(i);
			else tlink.push_back(i);
		}
		for(int i=0;i<tstart.size();++i){
			for(int j=i+1;j<tstart.size();++j){
				start += arr[tstart[i]][tstart[j]]+arr[tstart[j]][tstart[i]];
				link += arr[tlink[i]][tlink[j]]+arr[tlink[j]][tlink[i]];
			}
		}
		res = min(res,abs(link-start));
		return 0;
	}
	for(int i=idx;i<n;++i)
		if(!chk[i]){
			chk[i]=1;
			dfs(i,size+1);
			chk[i]=0;
		}
}

int main(int argc, char* argv[]) {
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&arr[i][j]);
	dfs(0,0);
	cout<<res<<endl;
	return 0;
}