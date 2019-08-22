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

int n,m,t,s,g,h;
long long arr[2001];
priority_queue<pii,vector<pii>,greater<pii>> que;

vector<long long> dijk(vector<pii>vec[],int s){
	vector<long long> dist(2001,INF);
	que.push({0,s});
	while(que.size()){
		long long w = que.top().first;
		int node =que.top().second;
		que.pop();
		if(dist[node]!=INF) continue;
		dist[node] = w;
		for(int i=0;i<vec[node].size();++i){
			int next = vec[node][i].first;
			long long cost = vec[node][i].second+w;
			if(dist[next]!=INF) continue;
			que.push({cost,next});
		}
	}
	return dist;
}


int main(int argc, char* argv[]) {
	int test;
	cin>>test;
	while(test--){
		vector<pii> vec[2001];
		vector<int> cand;
		vector<int> res;
		cin>>n>>m>>t>>s>>g>>h;
		for(int i=0;i<m;++i){
			int a,b,d;
			scanf("%d %d %d",&a,&b,&d);
			vec[a].push_back({b,d});
			vec[b].push_back({a,d});
		}
		for(int i=0;i<t;++i){
			int x;
			scanf("%d",&x);
			cand.push_back(x);
		}
		vector<long long> stoN= dijk(vec,s);
		vector<long long> case1 = dijk(vec,g);
		vector<long long> case2 = dijk(vec,h);
		for(int i=1;i<=n;++i)
			arr[i] = min(stoN[g]+case1[h]+case2[i],stoN[h]+case2[g]+case1[i]);
		for(int i=0;i<t;++i){
			if(stoN[cand[i]]!=arr[cand[i]]) continue;
			res.push_back(cand[i]);
		}
		sort(res.begin(),res.end());
		for(int i=0;i<res.size();++i)
			cout<<res[i]<<' ';
		cout<<endl;
		
	}
	return 0;
}