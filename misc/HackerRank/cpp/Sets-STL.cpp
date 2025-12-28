#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int q;
    cin>>q;
    
    set<int> s;
    
    while(q--){
        int type, val;
        cin>>type>>val;
        
        if(type == 1)
            s.insert(val);
        else if(type == 2)
            s.erase(val);
        else{
            if(s.find(val) != s.end())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
      
    return 0;
}
