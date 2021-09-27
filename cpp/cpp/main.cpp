//
//  main.cpp
//  cpp
//
//  Created by Vlada Vlada on 27.09.2021.
//

#include <iostream>
using namespace std;
struct pipe
{
    int id;
    double length;
};
//struct cs
//{
//    int id;
 //   int ;
//};
void PrintPipe(pipe&p)
{
    cout<<"You entered:"<<p.length<<endl;
}
pipe CreatePipe()
{
    pipe p;
    p.id=0;
    cout<<"Enter length:";
    cin>>p.length;
    return p;
}



int main() {
    // insert code here...
    pipe p=CreatePipe();
    PrintPipe(p);
    return 0;
}
