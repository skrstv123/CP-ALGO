#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main(){
	
	// stack of integers 
	stack<int, list<int>> is; // stack of linked list, we can also use vector by default it is deque
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
