#include <iostream>
#include <set>

using namespace std;

int main(){
	//=-----------------------=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-==
	// using comparators to alter the default sorting method
	set<int ,greater<int>> s;
	// same can also be done with maps
	
	s.insert(1);
	s.insert(12);
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(6);
	
	// set stores values in sorted order by default 
	for(auto &val: s){
		cout<<val<<' ';
	}
	
    return 0;
}
