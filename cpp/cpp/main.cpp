//
//  main.cpp
//  cpp
//
//  Created by Vlada Vlada on 27.09.2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    int id;
    double length = 0;
    double diameter = 0;
    bool vremont = 1;
};

struct station
{
    int id_st;
    string name;
    int tsekh = 0;
    int worktsekh = 0;
    double effect = 0;
};

void EditPipe(pipe& p)
{
    p.vremont = (!p.vremont);
}
void EditStation(station& s)
{
    if (s.tsekh != 0)
        {
            
            cout << "Enter a new number  of work tsekh:";
             s.worktsekh = GetCorrectNumber(0,s.tsekh);
        }
        else
            cout << "Number of tsekh = 0. Add tsekh to edit work tsekh!" << endl;
}
void SavePipe(ofstream& fout, const pipe& p)
{
    if (p.length != 0 && p.diameter != 0)
    {
    fout << "Pipe:" << endl << p.id << endl <<  p.length << endl << p.diameter << endl << p.vremont << endl;
        }
        /*else
            cout << "Pipe didn't create!" << endl;*/
       
    }

void SaveStation(ofstream& fout, const station& s)
{
    if (s.tsekh != 0)
    {
        fout << "Station:" << endl << s.id_st << endl << s.name << endl << s.tsekh << endl << s.worktsekh  << endl << s.effect << endl;
    }
    /*else
        cout << "Station didn't create!" << endl;*/
}

 void LoadPipeandStation(ifstream& fin, pipe& p, station& s)
 {
     
     ifstream fin;
    fin.open("data.txt");
    if (!fin.is_open())
    {
        cout << "File open error!" << endl;
        p={};
        s={};
        return;
    }
     while (!fin.ios_base::eof())
    {
        string str;
        fin>>ws;
        getline(fin, str);
        if (str == "Pipe:")
        {
            fin >> p.id;
            fin >> p.length;
            fin >> p.diameter;
            fin >> p.vremont;
        }
        else if (str == "Station:")
        {
            fin >> s.id_st;
            fin >> ws;
            getline(fin, s.name);
            fin >> s.tsekh;
            fin >> s.worktsekh;
            fin >> s.effect;
        }
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
    << "(6) Edit Station" << endl
    << "(7) Save to file" << endl
    << "(8) Load from file" << endl
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
    //cout << "Enter pipe id:";
    p.id = 0;
    cout << "Enter length:";
    p.length = GetCorrectNumber(0.0, 1000.0);
    cout << "Enter diameter:";
    p.diameter = GetCorrectNumber(0.0, 1000.0);
    //cout << "Enter sign:";
    p.vremont = false;
    return in;
}

ostream& operator << (ostream& out, const station& s)
{
    out << "Station id:" << s.id_st << "\tname:" << s.name << "\ttsekh:" << s.tsekh << "\twork tsekh:" << s.worktsekh << "\tefficiency:" << s.effect << endl;
    return out;
}

istream& operator >> (istream& in, station& s)
{
    //cout << "Enter station id:";
    s.id_st = 0;
    cout << "Enter name:";
    //cin.ignore(2000, '\n');
    cin>>ws;
    getline(cin, s.name);
    cout << "Enter tsekh:";
    s.tsekh = GetCorrectNumber(0, 50);
    cout << "Enter  work tsekh:";
    s.worktsekh = GetCorrectNumber(0, s.tsekh);
   /* while (s.worktsekh > s.tsekh || s.worktsekh < 0)
    {
    cout << "Enter  work tsekh (<tsekh) again:";
    s.worktsekh = GetCorrectNumber(0, 50);
    }*/
    cout<<"Enter  efficiency:";
    s.effect = GetCorrectNumber(0,10);
    return in;
}

pipe& SelectPipe(vector<pipe>& pg)
{
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber (1u, (unsigned int) pg.size());
    return pg[index-1];
}

station& SelectStation(vector<station>& sg)
{
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber (1u, (unsigned int) sg.size());
    return sg[index-1];
}

int main() {
    vector<pipe> pgroup;
    vector<station> sgroup;
    while (1)
    {
        Printmenu();
        switch (GetCorrectNumber(0, 8))
        {
            case 1:
            {
                pipe p;
                cin >> p;
                pgroup.push_back(p);
                break;
            }
            case 2:
            {
                //if (p.id == 0)
                cout << SelectPipe(pgroup) << endl;
               // else
                   // cout << "Pipe didn't create!" << endl;
                break;
            }
            case 3:
            {
                station s;
                cin >> s;
                sgroup.push_back(s);
                break;
            }
            case 4:
            {
                //if (s.id_st == 0)
                cout << SelectStation(sgroup) << endl;
                //else
                    //cout << "Station didn't create!" << endl;
                break;
            }
            
            case 5:
            {
                //if (p.id == 0)
                EditPipe(SelectPipe(pgroup));
                //else
                    //cout << "Pipe didn't create!" << endl;
                break;
            }
            case 6:
            {
                //if (s.id_st == 0)
                EditStation(SelectStation(sgroup));
                //else
                    //cout << "Station didn't create!" <<endl;
                break;
            }
            case 7:
            {
                ofstream fout;
                fout.open("data.txt", ios::out);
                if (!fout.is_open())
                {
                    cout << "File open error!" << endl;
                }
                else
                {
                    for(pipe p:pgroup)
                        SavePipe(fout, p);
                    for (station s:sgroup)
                        SaveStation(fout, s);
                        
                        fout.close();
                }
                break;
            }
         
            case 8:
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

