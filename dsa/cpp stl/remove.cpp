// remove overwrites the elememts tobe removed and returns a pointer to the begining of the redundant part (which should be erased)
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
	vector<int>::iterator itr = remove(v.begin(),v.end(),5);
	
	for(vector<int>::iterator itr = v.begin();itr!=v.end();itr++){
	cout<<*(itr)<<" ";
}

    v.erase(itr, v.end()); // erasing the redundant part
    cout<<'\n';
    
//	vetor 1st : v.begin(); last : v.end();
for(vector<int>::iterator itr = v.begin();itr!=v.end();itr++){
	cout<<*(itr)<<" ";
}
	
    return 0;
}
