#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
	vector<int> v {1,2,3,4,5};
	int fact5 = accumulate(v.begin(),v.end(),1,[](int a, int b){return a*b;});
	cout<<fact5<<endl;
    return 0;
}
