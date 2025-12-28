#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
private:
    int age;
    string first_name;
    string last_name;
    int standard;

public:
    int get_age(){
        return this->age;
    }
    
    void set_age(int age) {
        this->age = age;
    }
    
    string get_first_name(){
        return this->first_name;
    }
    
    void set_first_name(string first_name) {
        this->first_name = first_name;
    }
    
    string get_last_name(){
        return this->last_name;
    }
    
    void set_last_name(string last_name) {
        this->last_name = last_name;
    }
    
    int get_standard(){
        return this->standard;
    }
    
    void set_standard(int standard) {
        this->standard = standard;
    }
    
    void to_string() {
        cout<<this->age<<","<<this->first_name<<","<<this->last_name<<","<<this->standard;  
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int age;
    string first_name;
    string last_name;
    int standard;
    
    cin>>age>>first_name>>last_name>>standard;
    
    Student st1;
    
    st1.set_age(age);
    st1.set_first_name(first_name);
    st1.set_last_name(last_name);
    st1.set_standard(standard);
    
    cout<<st1.get_age()<<endl;
    cout<<st1.get_last_name()<<", "<<st1.get_first_name()<<endl;
    cout<<st1.get_standard()<<endl;
    cout<<endl;
    st1.to_string();
    
    return 0;
}
