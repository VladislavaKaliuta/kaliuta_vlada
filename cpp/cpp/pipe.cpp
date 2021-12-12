//
//  pipe.cpp
//  cpp
//
//  Created by Vlada Vlada on 21.11.2021.
//

#include "pipe.hpp"
#include "utils.h"

using namespace std;

int pipe::MaxID = 0;

pipe::pipe()
{
    id = MaxID++;
    name = "Unknown";
    length = 0;
    diameter = 0;
    vremont = false;
    
}

int pipe::GetID() const
{
    return id;
}

 void pipe::SetID()
{
     id = MaxID;
}


ostream& operator << (ostream& out, const pipe& p)
{
    out <<  "MaxID:" << pipe::MaxID << "\tpipe id:" << p.id << "\tname:" << p.name <<"\tlength:" << p.length << "\tdiameter:" << p.diameter << "\tsign:" << endl;
    if (p.vremont)
            out << "Pipe needs repair" << endl;
    return out;
}
istream& operator >> (istream& in, pipe& p)
{
    //cout << "Enter pipe id:";
    cout << "Enter name:";
    //cin.ignore(2000, '\n');
    cin>>ws;
    getline(cin, p.name);
    cout << "Enter length:";
    p.length = GetCorrectNumber(0.0, 1000.0);
    cout << "Enter diameter:";
    p.diameter = GetCorrectNumber(0.0, 1000.0);
    //p.vremont = false;
    return in;
}
std::ifstream& operator >> (std::ifstream& in, pipe& p)
{
    in >> p.id;
    in >> p.name;
    in >> p.diameter;
    in >> p.length;
    in >> p.vremont;
    return in;
}

std::ofstream& operator << (std::ofstream& out, const pipe& p)
{
    out << p.GetID() << endl
        << p.name << endl
        << p.diameter << endl
        << p.length << endl
        << p.vremont << endl;
    return out;
}


void pipe::EditVremont(pipe& p)
{
    p.vremont = (!p.vremont);
}
