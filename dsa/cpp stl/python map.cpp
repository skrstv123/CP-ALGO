#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
	
	// applying some function to each element of container using transform
	vector<int> v {1,2,3,4,5,6,7,8,9,10};
	vector<int> v2 ;
	transform(v.begin(),v.end(),back_inserter(v2), [](int val){return val*val;});
	// back_inserter uses push_back to append mapped elements to result list(v2)
	
	for(auto val: v2) cout<<val<<' ';
	
    return 0;
}
