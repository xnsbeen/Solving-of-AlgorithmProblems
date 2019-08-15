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

typedef pair<int,int> pii;
int dist[20001];
int v,e,s;
priority_queue<pii,vector<pii>,greater<pii>> que;
vector<pii> vec[20001];
/*다음 노드로 이동할 때 w는 누적된 거리 값을 가지고 간다.
우선순위 큐(minheap)를 사용하므로 먼저 계산된 것이 최소값이므로 이전에 거리가 계산된 경우
최솟값 비교가 필요없다. 즉, 거리가 계산되어 있다면 최소거리이므로 이후에 따져주는 값은 버린다*/
void dijk(int n){
	que.push({0,n});
	while(!que.empty()){
		int w = que.top().first;
		int node = que.top().second;
		que.pop();
		if(dist[node]!=-1) continue;
		dist[node]=w;
		for(int i=0;i<vec[node].size();++i){
			int next = vec[node][i].first;
			int cost = vec[node][i].second+w;
			if(dist[next]!=-1) continue;
			que.push({cost,next});			
		}
	}
}


int main(int argc, char* argv[]) {
	cin>>v>>e>>s;
	for(int i=0;i<e;++i){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vec[a].push_back({b,c});
	}
	memset(dist,-1,sizeof(dist)); // 1,0,-1로 초기화 가능
	dijk(s);
	for(int i=1;i<=v;++i){
		if(dist[i]==-1) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
	return 0;
}