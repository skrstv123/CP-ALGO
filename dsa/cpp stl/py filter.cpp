/* just by using remove_if and an anonymous function :) */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
	// removing some special elements
	vector<int> v {1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator endfilter = remove_if(v.begin(),v.end(), [](int val){return val&1;});  
	for(auto valitr= v.begin();valitr!=endfilter;valitr++) cout<<*valitr<<' ';
	
    return 0;
}
