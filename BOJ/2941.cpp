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
int main(int argc, char* argv[]) {
	string words[8] = {"c=","c-","d-","lj","nj","s=","dz=","z="};
	string str;
	cin>>str;
	for(int i=0;i<8;++i)
		while(str.find(words[i])!=string::npos){
			str.replace(str.find(words[i]),words[i].length(),"+");
		}
	cout<<str.length()<<endl;
	return 0;
}