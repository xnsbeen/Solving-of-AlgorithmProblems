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
#define INF 1987654321
typedef pair<int,int> pii;

int n,m,a,b,c;
bool cycle =false;
vector<pii>vec[501];

vector<long long> bfa(){
	vector<long long>dist(501,INF);
	dist[1]=0;
	/*왜 n-1번 해야 하는가
		예시
		6 8
		1 2 10
		1 6 8
		2 4 2
		3 1 1
		4 3 -2
		5 4 -1
		5 2 -4
		6 4 1
	*/
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=0;k<vec[j].size();++k){
				int next = vec[j][k].first;
				long long w = vec[j][k].second;
				if(dist[j]!=INF&&dist[next]>dist[j]+w){
					dist[next] = dist[j]+w;
					if(i==n) cycle = true;
				}
			}
			
		}
	}
	return dist;
}


int main(int argc, char* argv[]) {
	vector<long long>res;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&a,&b,&c);
		vec[a].push_back({b,c});
	}
	res = bfa();
	if(cycle==true) cout<<-1<<endl;
	else{
		for(int i=2;i<=n;++i){
			if(res[i]==INF) printf("%d\n",-1);
			else printf("%lld\n",res[i]);
		}
	}
	return 0;
}