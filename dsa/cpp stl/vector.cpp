//This is a demo program to illustrate the various operations that can be done in a vector in cpp.
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
    
//    cout<<"size => "<< v.size()<<endl;
//    cout<< v[0]<< endl;
//	  v.clear();  //deletes contents
//	  cout<<v.size()<<'\n';		 

//	similar to pointers : iterators 
	vector<int>::iterator itr = v.begin();
	
	
//	cout<<*(itr)<<'\n';
//	cout<<*(itr+1)<<'\n';

//sorting the vector
sort(v.begin(),v.end());

//	vetor 1st : v.begin(); last : v.end();
for(;itr!=v.end();itr++){
	cout<<*(itr)<<" ";
}
	
    return 0;
}
