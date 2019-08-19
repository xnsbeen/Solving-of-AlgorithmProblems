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
int res=1;
/*
1번 기둥에 있는 n개의 원반 중 맨 아래에 있는 원반을 제외한 n-1원반을 3번 기둥을 이용하여 2번 기둥으로 옮긴다
1번 기둥 맨 아래에 있는 가장 큰 원반을 3번 기둥으로 옮긴다.
2번 기둥에 있는 n-1개의 원반을 1번 기둥을 이용하여 3번 기둥으로 옮긴다.
*/
void hanoi(int n,int s,int e,int t){ // s기둥에 있는 n-1개의 원반들을 t기둥을 이용하여 e기둥으로 옮긴다.
	if(n==1) 
		printf("%d %d\n",s,e);
	else{
		hanoi(n-1,s,t,e);
		printf("%d %d\n",s,e);
		hanoi(n-1,t,e,s);
	}
	
}
int main(int argc, char* argv[]) {
	int n;
	cin>>n;
	for(int i=0;i<n;++i) // 하노이의 경우의 수는 2^n-1 이다.
		res*=2;
	cout<<res-1<<endl;
	hanoi(n,1,3,2);
	return 0;
}