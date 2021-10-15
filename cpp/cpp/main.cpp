//
//  main.cpp
//  cpp
//
//  Created by Vlada Vlada on 27.09.2021.
//

#include <iostream>
#include <fstream>
using namespace std;
struct pipe
{
    int id = 0;
    double length = 0;
    double diameter = 0;
    bool vremont = false;
};
struct station
{
    int id;
    string name;
    int tsekh;
    int worktsekh;
    double effect;
};

pipe CreatePipe()
{
    pipe p;
    p.id=0;
    do
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter length:";
        cin >> p.length;
    }while (cin.fail() || p.length <= 0);
    do
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter diameter:";
        cin >> p.diameter;
    }while (cin.fail() || p.diameter <= 0);
    return p;
}
station CreateStation()
{
    station s;
    s.id=0;
    cout << "Enter name:";
    cin >> s.name;
    do
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter tsekh (integer):";
        cin >> s.tsekh;
    }while (cin.fail() || s.tsekh <= 0);
    do
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter worktsekh (integer):";
        cin >> s.worktsekh;
    }while (cin.fail() || s.worktsekh <= 0);
    
    return s;
}
void PrintPipe(const pipe& p)
{
    cout << "Pipe length:" << p.length << "\tdiameter:" << p.diameter << endl;
}
void PrintStation(const station& s)
{
    cout << "Station name:" << s.name << "\ttsekh:" << s.tsekh << "\tworktsekh:" << s.worktsekh << endl;
}
void EditPipe(pipe& p)
{
    p.length-=1;
}
void SavePipeandStation(const pipe& p, const station& s)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open())
    {
        fout << p.length << endl << p.diameter << endl << s.name << endl << s.tsekh << endl << s.worktsekh  << endl;
    fout.close();
    }
}
pipe LoadPipe()
{
    pipe p;
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open())
    {
    fin >> p.length;
    fin >> p.diameter;
    fin.close();
    }
    return p;
    
}
station LoadStation()
{
    station s;
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open())
    {
        fin >> s.name;
    fin >> s.tsekh;
    fin >> s.worktsekh;
    fin.close();
    }
    return s;
    
}

void Printmenu()
{
    cout << "(1) Enter Pipe" << endl
    << "(2) Enter Station" << endl
    << "(3) Print Pipe" << endl
    << "(4) Print Station" << endl
    << "(5) Save to file" << endl
    << "(6) Load from file" << endl
    << "(7) Edit Pipe" << endl
    << "(0) Exit" << endl
    << "Enter number, please:" << endl;
}


int main() {
    pipe p;
    station s;
    while (1)
    {
        Printmenu();
        int i = 0;
        cin >> i;
        switch (i)
        {
            case 1:
            {
                CreatePipe();
                break;
            }
            case 2:
            {
                CreateStation();
                break;
            }
            case 3:
            {
                PrintPipe(p);
                break;
            }
            case 4:
            {
                PrintStation(s);
                break;
            }
            
            case 5:
            {
                SavePipeandStation(p,s);
                break;
            }
            case 6:
            {
                LoadPipe();
                LoadStation();
                break;
            }
            case 7:
            {
                EditPipe(p);
                break;
            }
            case 0:
            {
               return 0;
            }
            default:
                
            {
                cout << "wrong action" << endl;
            }
        }
    }
    
    return 0;
}

