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
int n,k;
int cnt=0;
int visit[111111];
queue<int> que;
int bfs(){
	visit[n]=1;
	while(!que.empty()){
		int size = que.size();
		for(int i=0;i<size;++i){
			int front = que.front();
			que.pop();
			visit[front] = 1;
			if(front == k ) return 0;
			if(front*2<=100000&&!visit[front*2])
				que.push(front*2);
	
			if(front-1>=0&&!visit[front-1])
				que.push(front-1);
			if(front+1<=100000&&!visit[front+1]) 
				que.push(front+1);
		}
		cnt++;
	}
	
}
int main(int argc, char* argv[]) {
	cin>>n>>k;
	que.push(n);
	bfs();
	cout<<cnt<<endl;
	return 0;
}