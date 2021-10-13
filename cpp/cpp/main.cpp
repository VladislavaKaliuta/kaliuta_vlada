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
    double diameter;
};
struct station
{
    int id;
    string name;
    int tsekh;
    int worktsekh;
};
pipe P;
station S;

pipe CreatePipe()
{
    pipe p;
    p.id=0;
    cout<<"Enter length:";
    cin>>p.length;
    cout<<"Enter diameter:";
    cin>>p.diameter;
    return p;
}
station CreateStation()
{
    station s;
    s.id=0;
    cout<<"Enter name:";
    cin>>s.name;
    cout<<"Enter tsekh:";
    cin>>s.tsekh;
    cout<<"Enter worktsekh:";
    cin>>s.worktsekh;
    return s;
}
void PrintPipe(const pipe& p)
{
    cout<<"Pipe length:"<<p.length<<"\tdiameter:"<<p.diameter<<endl;
}
void PrintStation(const station& s)
{
    cout<<"Station name:"<<s.name<<"\ttsekh:"<<s.tsekh<<"\tworktsekh:"<<s.worktsekh<<endl;
}
void EditPipe(pipe& p)
{
    p.length-=1;
}


int main() {
    pipe p=CreatePipe();
    station s=CreateStation();
    PrintPipe(p);
    PrintStation(s);
    EditPipe(p);
    return 0;
}
