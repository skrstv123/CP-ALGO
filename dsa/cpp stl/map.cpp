#include <iostream>
#include <map> //similar to python's dict

using namespace std;

int main(){

	// a map uses pair container to represent key-value pair
	pair<int, int> p = make_pair(10,30);
//	cout<< p.first<<"-"<<p.second<<'\n';
	
//	defining a map
	map<int,int> mp;
	
	mp[4] = 400;
	mp[2] = 2000;
//	we can also.....
	mp.insert(make_pair(10,100));
	
//	ierating 
	map<int,int>::iterator it = mp.begin();
	for(;it!=mp.end();it++)
	{
		cout<<it->first<<"-"<<it->second<<'\n'; 
//		a map's keys are stored in ascending order
	}
	
    return 0;
}
