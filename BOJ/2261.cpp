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
using namespace std;

vector<pair<int,int> >vec;

bool cmp(pair<int,int>&a, pair<int,int>&b){
	return a.first<b.first;
}

int dist(pair<int,int> a,pair<int,int>b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
} 

int shottestLine(int start,int end ){
	if(end == 2) return dist(vec[0],vec[1]);
	if(end == 3) return min(min(dist(vec[0],vec[1]),dist(vec[0],vec[2])),dist(vec[1],vec[2]));
	int minn = 1987654321;
	int mid = (start+end)/2;
	int mid_line = (vec[start].first+vec[end].first)/2;
	minn = min(shottestLine(start,mid),shottestLine(mid+1,end));
	
	int pos_left = lower_bound(vec.begin(),vec.end(),mid_line-sqrt(minn),cmp);
	int pos_right = lower_bound(vec.begin(),vec.end(),mid_line+sqrt(minn),cmp);
}

int main(int argc, char* argv[]) {
	int n;
	int res;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d %d",&a,&b);
		vec.push_back({a,b});
	}
	sort(vec.begin(),vec.end());
	res = min(0,n);
	
	return 0;
}