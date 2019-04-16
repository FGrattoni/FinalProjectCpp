//
//  main.cpp
//  C++ Paris 1
//
//  Created by Lillian Haas on 21/03/2019.
//  Copyright © 2019 Lillian Haas. All rights reserved.
//

#include <iostream>

using namespace std; 
int main() {
    
    int a,b,c;
    
    cout<<"Number 1";
    cin>>a;
    cout<<"Number 2";
    cin>>b;
    cout<<"Number 3";
    cin>>c;
    
    if (a>b)
    {
        if (a<c) {
            cout<<"greatest number"<<a<<endl;
        } else {
            cout<<"greatest number"<<c<<endl;
        }
    } else {
        cout<<"greatest number"<<b<<endl;
    }
}
