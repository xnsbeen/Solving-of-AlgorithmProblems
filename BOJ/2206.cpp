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
int n,m;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int arr[1111][1111];
int dist[1111][1111][2];
queue <pair<int,pair<int,int>>> que;
int bfs(){
	que.push({1,{1,0}});
	dist[1][1][0] = 1;
	while(!que.empty()){
		pair<int,pair<int,int>> front = que.front();
		que.pop();
		int y = front.first,x=front.second.first, w =front.second.second;
		if(y== n&&x==m) return dist[y][x][w];
		for(int j=0;j<4;++j){
			int yy = y+dy[j];
			int xx = x+dx[j];
			if(yy>n||xx>m||xx<=0||yy<=0) continue;
			if(dist[yy][xx][w]) continue;
			if(arr[yy][xx]==0){
				dist[yy][xx][w] = dist[y][x][w]+1;
				que.push({yy,{xx,w}});
			}
			if(arr[yy][xx]==1&&w==0){
				dist[yy][xx][1]=dist[y][x][w]+1;
				que.push({yy,{xx,1}});
			}
		}
	}
	return -1;
}
int main(int argc, char* argv[]) {
	string str;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>str;
		for(int j=1;j<=m;++j)
			arr[i][j]=str[j-1]-'0';
	}
	cout<<bfs()<<endl;
	
	return 0;
}