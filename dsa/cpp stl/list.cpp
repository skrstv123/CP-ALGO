#include <iostream>
#include <list> //linked list
#include <algorithm> // to use sort function
//we cannot use sort func to sort a bidirectional container : a doubly linked list


using namespace std;

int main(){
    list<int> v;
    
    v.push_back(5);
    v.push_back(6);
     v.push_back(7);
      v.push_back(5);
       v.push_back(1);
        v.push_back(7);
         v.push_back(2);
    
    cout<<"size => "<< v.size()<<endl;
//    cout<< v[0]<< endl;
//	  v.clear();  //deletes contents
//	  cout<<v.size()<<'\n';		 

//	similar to pointers : iterators 
	list<int>::iterator itr = v.begin();
	
	cout<<*(itr)<<'\n';
	
//	vetor 1st : v.begin(); last : v.end();
for(;itr!=v.end();itr++){
	cout<<*(itr)<<" ";
}
	
    return 0;
}
