#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main(){
	
// queue of integers 
	queue<int, list<int>> is; // queue of linked list, we cannot use vector by default it is deque
	is.push(6);
	is.push(9);
	is.push(5);
	is.push(1);
	is.push(10);
	
// 	cout<<is.top()<<'\n';
	while(!is.empty())
	{
	    cout<<is.front()<<'\n';
	    cout<<is.back()<<'\n';
	    
		is.pop();
	}
	
    return 0;
}
