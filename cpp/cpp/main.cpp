//
//  main.cpp
//  cpp
//
//  Created by Vlada Vlada on 27.09.2021.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail() || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter number (" << min << "-" << max <<") again:";
    }
    return x;
    
}
struct pipe
{
    int id = 0;
    double length = 0;
    double diameter = 0;
    bool sign = 1;
};

struct station
{
    int id_st = 0;
    string name;
    int tsekh = 0;
    int worktsekh = 0;
    double effect = 0;
};

void EditPipe(pipe& p)
{
    p.sign = (!p.sign);
}
void SavePipeandStation(const pipe& p, const station& s)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (!fout.is_open())
    {
        cout << "File open error!" << endl;
    }
    else
    {
        if (p.length != 0 && p.diameter != 0)
        {
            fout << p.id << endl <<  p.length << endl << p.diameter << endl << p.sign << endl;
        }
        else
            cout << "Pipe didn't create!" << endl;
        if (s.tsekh != 0)
        {
            fout << s.id_st << endl << s.name << endl << s.tsekh << endl << s.worktsekh  << endl << s.effect << endl;
        }
        else
            cout << "Station didn't create!" << endl;
        
    fout.close();
    }
}

 void LoadPipeandStation( pipe& p, station& s)
 {
    
    ifstream fin;
    fin.open("data.txt");
    if (!fin.is_open())
    {
        cout << "File open error!" << endl;
    }
    else
        {
            fin >> p.id;
            fin >> p.length;
            fin >> p.diameter;
            fin >> p.sign;
            fin >> s.id_st;
            fin >> s.name;
            fin >> s.tsekh;
            fin >> s.worktsekh;
            fin >> s.effect;
            
            }
    
     fin.close();

    }
 
void Printmenu()
{
    cout << "(1) Create Pipe" << endl
    << "(2) Print Pipe" << endl
    << "(3) Create Compressor station" << endl
    << "(4) Print Compressor station" << endl
    << "(5) Edit Pipe" << endl
    << "(6) Save to file" << endl
    << "(7) Load from file" << endl
    << "(0) Exit" << endl
    << "Enter number, please:" << endl;
}
ostream& operator << (ostream& out, const pipe& p)
{
    out << "Pipe id:" << p.id << "\tlength:" << p.length << "\tdiameter:" << p.diameter << "\tsign:" << endl;
    return out;
}
istream& operator >> (istream& in, pipe& p)
{
    cout << "Enter pipe id:";
    cin >> p.id;
    cout << "Enter length:";
    p.length = GetCorrectNumber(0.0, 1000.0);
    cout << "Enter diameter:";
    p.diameter = GetCorrectNumber(0.0, 1000.0);
    cout << "Enter sign:";
    cin >> p.sign;
    return in;
}

ostream& operator << (ostream& out, const station& s)
{
    out << "Station id:" << s.id_st << "\tname:" << s.name << "\ttsekh:" << s.tsekh << "\twork tsekh:" << s.worktsekh << "\tefficiency:" << s.effect << endl;
    return out;
}

istream& operator >> (istream& in, station& s)
{
    cout << "Enter station id:";
    cin >> s.id_st;
    cout << "Enter name:";
    cin.ignore(2000, '\n');
    getline(cin, s.name);
    cout << "Enter tsekh:";
    s.tsekh = GetCorrectNumber(0, 50);
    cout << "Enter  work tsekh:";
    s.worktsekh = GetCorrectNumber(0, 50);
    while (s.worktsekh > s.tsekh || s.worktsekh < 0)
    {
    cout << "Enter  work tsekh (<tsekh) again:";
    s.worktsekh = GetCorrectNumber(0, 50);
    }
    cout<<"Enter  efficiency:";
    cin >> s.effect;
    return in;
}

int main() {
    pipe p;
    station s;
    while (1)
    {
        Printmenu();
        switch (GetCorrectNumber(0, 7))
        {
            case 1:
            {
                cin >> p;
                break;
            }
            case 2:
            {
                cout << p << endl;
                break;
            }
            case 3:
            {
                cin >> s;
                break;
            }
            case 4:
            {
                cout << s << endl;
                break;
            }
            
            case 5:
            {
                EditPipe(p);
                break;
            }
            case 6:
            {
                SavePipeandStation(p,s);
                
                break;
            }
            case 7:
            {
                LoadPipeandStation(p,s);
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

