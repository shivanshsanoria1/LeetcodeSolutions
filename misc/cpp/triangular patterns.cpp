#include <iostream>
using namespace std;

void triangleQuad1(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad2(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad3(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=i; j<n; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad4(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad12(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<2*i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad23(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<=i; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<" ";
        for(int j=0; j<n-i-1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad34(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=0; j<2*n-1-2*i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad41(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

void triangleQuad1234(int n){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
            cout<<" ";
        for(int j=0; j<2*i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<" ";
        for(int j=0; j<2*n-3-2*i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<string(25, '-')<<endl<<endl;
}

int main(){
    int n = 8;
    
    cout<<"Triangular-patterns for n = "<<n<<": "<<endl<<endl;
    
    cout<<"Quad-1: "<<endl;
    triangleQuad1(n);
    cout<<"Quad-2: "<<endl;
    triangleQuad2(n);
    cout<<"Quad-3: "<<endl;
    triangleQuad3(n);
    cout<<"Quad-4: "<<endl;
    triangleQuad4(n);
    
    cout<<"Quad-12: "<<endl;
    triangleQuad12(n);
    cout<<"Quad-23: "<<endl;
    triangleQuad23(n);
    cout<<"Quad-34: "<<endl;
    triangleQuad34(n);
    cout<<"Quad-41: "<<endl;
    triangleQuad41(n);
    
    cout<<"Quad-1234: "<<endl;
    triangleQuad1234(n);

    return 0;
}
