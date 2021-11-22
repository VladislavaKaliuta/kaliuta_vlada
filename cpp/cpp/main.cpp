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
#include "pipe.hpp"
#include "station.hpp"
#include "utils.h"


using namespace std;

void EditPipe(pipe& p)
{
    p.EditVremont(p);
}

void EditStation(station& s)
{
    s.EditWorktsekh(s);
}

void SavePipe(ofstream& fout, const pipe& p)
{
    if (p.length != 0 && p.diameter != 0)
    {
    fout << "Pipe:" << endl << p.GetID() << endl <<  p.length << endl << p.diameter << endl << p.vremont << endl;
        }
        /*else
            cout << "Pipe didn't create!" << endl;*/
       
    }

void SaveStation(ofstream& fout, const station& s)
{
    if (s.tsekh != 0)
    {
        fout << "Station:" << endl << s.GetID_ST() << endl << s.name << endl << s.tsekh << endl << s.worktsekh  << endl << s.effect << endl;
    }
    /*else
        cout << "Station didn't create!" << endl;*/
}

 void LoadPipeandStation(ifstream& fin, pipe& p, station& s)
 {
     
    
        //p={};
        //s={};
        //return;
    
     while (!fin.ios_base::eof())
    {
        string str;
        fin>>ws;
        getline(fin, str);
        if (str == "Pipe:")
        {
           // fin >> p.SetID();
            fin >> p.length;
            fin >> p.diameter;
            fin >> p.vremont;
        }
        else if (str == "Station:")
        {
            //fin >> s.id_st;
            fin >> ws;
            getline(fin, s.name);
            fin >> s.tsekh;
            fin >> s.worktsekh;
            fin >> s.effect;
        }
    }
    
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
    << "(9) Find Station by name" << endl
    << "(0) Exit" << endl
    << "Enter number, please:" << endl;
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
template<typename T>
using Filter = bool(*)(const station & s, T param);
bool CheckByName (const station& s,string param)
{
    return s.name == param;
}
/*bool CheckByName (const station& s,string param)
{
    return s.name == param;
}*/
template<typename T>
vector <int> FindStationByFilter(const vector<station>& sgroup, Filter<T> f, T param)
{
    vector <int> res;
    int i = 0;
    for (auto& s : sgroup)
    {
        if (f(s, param))
            res.push_back(i);
        i++;
    }
    
    return res;
}

int main() {
    vector<pipe> pgroup;
    vector<station> sgroup;
    
   // pgroup.resize(3);
    
    while (1)
    {
        Printmenu();
        switch (GetCorrectNumber(0, 9))
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
                for (const auto& p:pgroup)
                cout << p << endl;
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
                for (auto& s:sgroup)
                cout << s << endl;
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
                    fout << pgroup.size() << endl;
                    for(pipe p:pgroup)
                        SavePipe(fout, p);
                    fout << sgroup.size() << endl;
                    for (station s:sgroup)
                        SaveStation(fout, s);
                        
                        fout.close();
                }
                break;
            }
         
            case 8:
            {
                ifstream fin;
                fin.open("data.txt");
                if (!fin.is_open())
                {
                    cout << "File open error!" << endl;
                }
                else
                {
                    int count;
                    fin >> count;
                    while (count--)
                         //group.push_back(LoadPipeandStation(fin,p,s));
                        fin.close();
                    
                }
                break;
            }
            case 9:
            {
                string name = "Unknown";
               for (int i: FindStationByFilter(sgroup, CheckByName, name))
                   cout << sgroup[i];
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

