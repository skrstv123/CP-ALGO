#include <iostream>
#include <vector> //contiguous memory allocation
#include <algorithm> // to use sort function

using namespace std;

int main(){
    vector<int> v;
    
    v.push_back(5);
    v.push_back(6);
     v.push_back(7);
      v.push_back(5);
       v.push_back(1);
        v.push_back(7);
         v.push_back(2);
    
//	similar to pointers : iterators 
	vector<int>::iterator itr = v.begin();

// v.erase(v.begin(),v.begin()+1); // removes first
v.erase(v.begin()); // can also take just 1 pointer

//	vetor 1st : v.begin(); last : v.end();
for(;itr!=v.end();itr++){
	cout<<*(itr)<<" ";
}
	
    return 0;
}
