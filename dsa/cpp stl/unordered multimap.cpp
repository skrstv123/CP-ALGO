#include <iostream>
#include <unordered_map> // more similar to python's dict; uses hash table so accessing elements is in O(1) 

using namespace std;

int main(){

	// a map uses pair container to represent key-value pair
	pair<int, int> p = make_pair(10,30);
//	cout<< p.first<<"-"<<p.second<<'\n';
	
//	defining a map
	unordered_multimap<int,int> mp;
	
// 	mp[4] = 400;   we cannot use subscript operator [] because overwritting any key's value is not allowed
// 	mp[2] = 2000;  every time we insert a pair a new key-value pair is created 
// 	mp[2] = 2000;

//	we can only.....
	mp.insert(make_pair(10,100));
	mp.insert(make_pair(12,10));
	mp.insert(make_pair(3,1000));
	mp.insert(make_pair(10,1));
	mp.insert(make_pair(1,12));
	
//	ierating 

	for(auto it = mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<"-"<<it->second<<'\n'; 
//		a map's keys are stored in ascending order
	}
	
    return 0;
}
