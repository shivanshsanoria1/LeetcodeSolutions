#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    // name -> marks
    map<string, int> mp; 
    
    int q;
    cin>>q;
    
    while(q--){
        int type;
        cin>>type;
        
        if(type == 1){
            string name;
            int marks;
            cin>>name>>marks;
            
            mp[name] += marks;
        }
        else if(type == 2){
            string name;
            cin>>name;
            
            mp.erase(name);
        }
        else{
            string name;
            cin>>name;
            
            if(mp.find(name) != mp.end())
                cout<<mp[name]<<endl;
            else
                cout<<0<<endl;
        }
    }
     
    return 0;
}
