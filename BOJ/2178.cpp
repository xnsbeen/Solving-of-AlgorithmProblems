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
int arr[111][111];
int cnt=0;
int n,m;
int dy[4] = {0,0,-1,1};
int dx[4] ={1,-1,0,0};

int bfs(){
	queue <pair<int,int>> que;
	que.push({1,1});
	arr[1][1]=0;
	while(1){
		int size = que.size();
		for(int i=0;i<size;++i){
			pair<int,int> front = que.front();
			que.pop();
			if(front.first==n&&front.second==m)
				return 0;
			for(int i=0;i<4;++i){
				int yy = front.first+dy[i];
				int xx = front.second+dx[i];
				if(arr[yy][xx]==1){
					arr[yy][xx]=0;
					que.push({yy,xx});
				}
			}
		}
		cnt++;
	}
}
int main(int argc, char* argv[]) {
	string str;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>str;
		for(int j=1;j<=m;++j)
			arr[i][j]=str[j-1]-'0';
	}
	bfs();
	cout<<cnt+1<<endl;
	return 0;
}