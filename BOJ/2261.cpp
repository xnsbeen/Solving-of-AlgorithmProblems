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

#define INF 1987654321;
typedef pair<int,int> pii;

vector<pii>vec;

bool cmpx(const pii &a,const pii &b){
	return a.first<b.first;
}
bool cmpy(const pii &a,const pii &b){
	return a.second<b.second;
}

int dist(pii a, pii b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
} 

int shottestLine(int start,int end,int n){
	if(n == 1) return INF;
	if(n == 2) return dist(vec[start],vec[end]);
	if(n == 3) return min(min(dist(vec[start],vec[start+1]),dist(vec[start+1],vec[start+2])),dist(vec[start],vec[start+2]));
	int mid = (start+end)/2;
	int lineX = (vec[mid].first+vec[mid+1].first)/2;
	int d = min(shottestLine(start,mid,mid-start),shottestLine(mid,end,end-mid));
	vector<pii>avail;
	
	for(int i=start;i<end;++i)
		if((lineX-vec[i].first)*(lineX-vec[i].first)<d)
			avail.push_back(vec[i]);
	sort(vec.begin(),vec.end(),cmpy);
	for(int i=0;i<avail.size()-1;++i)
		for(int j=i+1;j<avail.size()&&j<i+7;++j)
			d=min(d,dist(avail[i],avail[j]));
	
	return d;
}

int main(int argc, char* argv[]) {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		vec.push_back({a,b});
	}
	sort(vec.begin(),vec.end(),cmpx);
	cout<<shottestLine(0,n,n)<<endl;
	return 0;
}