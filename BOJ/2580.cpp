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

int arr[10][10];

vector<pair<int,int>>vec;

bool col(int x,int num){
	for(int i=1;i<=9;++i)
		if(arr[i][x]==num) return false;
	return true;
}
int row(int y,int num){
	for(int i=1;i<=9;++i)
		if(arr[y][i]==num) return false;
	return true;
}
int square(int y,int x,int num){
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if(arr[(y-1)/3*3+i][(x-1)/3*3+j]==num) return false;
	return true;
}
void printSudoku(){
	for(int i=1;i<=9;++i){
		for(int j=1;j<=9;++j)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}
int sudoku(int index){
	if(index == vec.size()){ printSudoku(); exit(0);}; // 답이 여러개 있을 경우 처리, 답 한개 출력하고 exit로 프로그램 종료
		for(int i=1;i<=9;++i){
			int y = vec[index].first;
			int x = vec[index].second;
			if(col(x,i)&&row(y,i)&&square(y,x,i)){
				arr[y][x]=i;
				sudoku(index+1);
				arr[y][x]=0;
			}
		}
	
}
int main(int argc, char* argv[]) {
	for(int i=1;i<=9;++i)
		for(int j=1;j<=9;++j){
			scanf("%d",&arr[i][j]);
			if(!arr[i][j]) vec.push_back({i,j}); 
		}
	sudoku(0);
	return 0;
}