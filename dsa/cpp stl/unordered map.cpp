#include <iostream>
#include <map>
#include <unordered_map> // more similar to python's dict; uses hash table so accessing elements is in O(1) 

using namespace std;

int main(){

	// a map uses pair container to represent key-value pair
	pair<int, int> p = make_pair(10,30);
//	cout<< p.first<<"-"<<p.second<<'\n';
	
//	defining a map
	unordered_map<int,int> mp;
	
	mp[4] = 400;
	mp[2] = 2000;
//	we can also.....
	mp.insert(make_pair(10,100));
	
//	ierating 
	map<int,int>::iterator it = mp.begin();
	for(;it!=mp.end();it++)
	{
		cout<<it->first<<"-"<<it->second<<'\n'; 
//		a unordered_map's keys donot maintain any order
	}
	
    return 0;
}
