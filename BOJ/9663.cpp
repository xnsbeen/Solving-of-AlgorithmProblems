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
/*퀸을 n개 놓으려면 같은 행이나 같은 열에 두개 이상 퀸을 놓지 못한다. 따라서 행을 기준으로 백트랙킹 dfs를 실시한다.
(1행 1열에 퀸이 놓일 경우 2행으로 넘어가 놓을 수 있는 열을 찾는다.)*/
int col[16];
int n;
int cnt =0;
/*대각선을 따질 때 행의 번호와 열의 번호의 차이의 절댓값이 같으면 같은 대각선에 위치한다*/
bool isPossible(int i){ 
	for(int j=1;j<i;++j)
		if(col[j]==col[i]||abs(col[i]-col[j])==i-j) return false;
	return true;
}

int nQueen(int c){ // c는 행의 번호
	if(c==n+1) cnt++; //마지막 행까지 확인해서 가능한 자리가 있는지를 따지므로 n+1일때 카운트
	else
		for(int i=1;i<=n;++i){
			col[c]=i; //c행 i열에 퀸을 놓는다
			if(isPossible(c))
				nQueen(c+1); // c행 i열에 퀸을 놓을 수 있으면 c+1행으로 넘어간다.
		}
	
}

int main(int argc, char* argv[]) {
	cin>>n;
	nQueen(1);
	cout<<cnt<<endl;
	return 0;
}