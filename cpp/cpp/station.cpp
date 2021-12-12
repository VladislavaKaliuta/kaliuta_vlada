//
//  station.cpp
//  cpp
//
//  Created by Vlada Vlada on 21.11.2021.
//

#include "station.hpp"
#include "utils.h"

using namespace std;

int station::MaxID_st = 0;

station::station()
{
    id_st = MaxID_st++;
    name_st = "Unknown";
    tsekh = 0;
    worktsekh = 0;
    effect = 0;
}

int station::GetID_ST() const
{
    return id_st;
}

 void station::SetID_ST()
{
     id_st = MaxID_st;
}


ostream& operator << (ostream& out, const station& s)
{
    out << "MaxID_ST:" << station::MaxID_st << "\tstation id:" << s.id_st << "\tname:" << s.name_st << "\ttsekh:" << s.tsekh << "\twork tsekh:" << s.worktsekh << "\tefficiency:" << s.effect << endl;
    return out;
}

istream& operator >> (istream& in, station& s)
{
    //cout << "Enter station id:";
    
    cout << "Enter name:";
    //cin.ignore(2000, '\n');
    cin>>ws;
    getline(cin, s.name_st);
    cout << "Enter tsekh:";
    s.tsekh = GetCorrectNumber(0, 50);
    cout << "Enter  work tsekh:";
    s.worktsekh = GetCorrectNumber(0, s.tsekh);
    cout<<"Enter  efficiency:";
    s.effect = GetCorrectNumber(0,10);
    return in;
}

ifstream& operator >> (std::ifstream& in, station& s)
{
    in >> s.id_st;
    in >> s.name_st;
    in >> s.tsekh;
    in >> s.worktsekh;
    in >> s.effect;
    return in;
}

ofstream& operator << (std::ofstream& out, const station& s)
{
    out << s.GetID_ST() << endl
        << s.name_st << endl
        << s.Gettsekh() << endl
        << s.Getworktsekh() << endl
        << s.effect << endl;
    return out;
}


void station::EditWorktsekh(station& s)
{
    if (s.tsekh != 0)
        {
            
            cout << "Enter a new number  of work tsekh:";
             s.worktsekh = GetCorrectNumber(0,s.tsekh);
        }
        else
            cout << "Number of tsekh = 0. Add tsekh to edit work tsekh!" << endl;
}

