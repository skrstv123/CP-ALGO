#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	// queue of integers 
	priority_queue<int, vector<int>, less<int>> is; // priority_queue of vector, we cannot use list by default it is deque, default comparator is less
	is.push(6);
	is.push(9);
	is.push(5);
	is.push(1);
	is.push(10);
	
// 	cout<<is.top()<<'\n';
	while(!is.empty())
	{
	    cout<<is.top()<<'\n';
		is.pop();
	}
	
    return 0;
}
