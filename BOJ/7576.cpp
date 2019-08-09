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
int arr[1111][1111];
int n,m;
int cnt=0;
int dy[4] = {0,0,-1,1};
int dx[4] ={1,-1,0,0};
queue <pair<int,int>> que;

void bfs(){
	while(!que.empty()){
		int k=0;
		int size = que.size();
		for(int i=0;i<size;++i){
			pair<int,int> front = que.front();
			que.pop();
			for(int i=0;i<4;++i){
				int yy = front.first+dy[i];
				int xx = front.second+dx[i];
				if(arr[yy][xx]==0&&yy<=m&&xx<=n&&yy>0&&xx>0){
					k=1;	
					arr[yy][xx]=1;
					que.push({yy,xx});
				}
			}
		}
		if(k)cnt++;
	}
	
}
int main(int argc, char* argv[]) {
	int chk=0;
	string str;
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1) que.push({i,j});
		}
	bfs();
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			if(arr[i][j]==0){
				chk=1;
				break;
			}
	if(chk) cout<<-1<<endl;
	else cout<<cnt<<endl;
	return 0;
}