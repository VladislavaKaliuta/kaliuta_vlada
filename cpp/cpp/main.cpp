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
#include <unordered_map>
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
    fout << "Pipe:" << endl << p.GetID() << endl << p.name << endl <<  p.length << endl << p.diameter << endl << p.vremont << endl;
        }
        /*else
            cout << "Pipe didn't create!" << endl;*/
       
    }

void SaveStation(ofstream& fout, const station& s)
{
    if (s.tsekh != 0)
    {
        fout << "Station:" << endl << s.GetID_ST() << endl << s.name_st << endl << s.tsekh << endl << s.worktsekh  << endl << s.effect << endl;
    }
    /*else
        cout << "Station didn't create!" << endl;*/
}

 pipe LoadPipe(ifstream& fin)
 {
     pipe p;
     // fin >> p.SetID();
     fin >> ws;
     getline(fin, p.name);
     fin >> p.length;
     fin >> p.diameter;
     fin >> p.vremont;
     
    
     return p;
    
}

station LoadStation(ifstream& fin)
{
    station s;
    //fin >> s.id_st;
    fin >> ws;
    getline(fin, s.name_st);
    fin >> s.tsekh;
    fin >> s.worktsekh;
    fin >> s.effect;
    return s;

               
}
 
void Printmenu()
{
    cout << "(1) Create Pipe" << endl
    << "(2) Create Compressor station" << endl
    << "(3) Print Pipe" << endl
    << "(4) Print Compressor station" << endl
    << "(5) Edit Pipe" << endl
    << "(6) Edit Station" << endl
    << "(7) Save to file" << endl
    << "(8) Load from file" << endl
    << "(9) Find Pipe by filter" << endl
    << "(10) Find Station by filter" << endl
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

void DeletePipe(vector<pipe>& pg)
{
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber (1u, (unsigned int) pg.size());
    pg.erase(pg.begin()+index );
    
}

void DeleteStation(vector<station>& sg)
{
    
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber (1u, (unsigned int) sg.size());
    sg.erase(sg.begin()+index);
}

template<typename T>
using Filter = bool(*)(const pipe& p, T param);
bool CheckByName (const pipe& p,string param)
{
    return p.name == param;
}
bool CheckByVremont (const pipe& p, bool param)
{
    return p.vremont == param;
}
template<typename T>
vector <int> FindPipeByFilter(const vector<pipe>& pgroup, Filter<T> f, T param)
{
    vector <int> res;
    int i = 0;
    for (auto& p : pgroup)
    {
        if (f(p, param))
            res.push_back(i);
        i++;
    }
    
    return res;
}


template<typename T>
using Filter_st = bool(*)(const station& s, T param);
bool CheckByName (const station& s,string param)
{
    return s.name_st == param;
}
bool CheckByPercentOfNonWorkTsekh (const station& s,double param)
{
    double procent = (s.tsekh-s.worktsekh)*100/s.tsekh;
    return procent == param;
}
template<typename T>
vector <int> FindStationByFilter(const vector<station>& sgroup, Filter_st<T> f, T param)
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
    unordered_map  <int, pipe> pgr = {};
    unordered_map  <int, station> sgr = {};
    pipe p;
    station cs;
    vector<pipe> pgroup;
    vector<station> sgroup;
    
   // pgroup.resize(3);
    
    while (1)
    {
        Printmenu();
        switch (GetCorrectNumber(0, 10))
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
                station s;
                cin >> s;
                sgroup.push_back(s);
                break;
            }
            case 3:
            {
                if (pgroup.size() != 0)
                {
                    for (const auto& p:pgroup)
                        cout << p << endl;
                }
                
                else
                    cout << "Pipe data didn't create! Please, enter them and try again." << endl;
                break;
               
            }
            case 4:
            {
                if (sgroup.size() != 0)
                {
                    for (auto& s:sgroup)
                        cout << s << endl;
                }
                
                else
                    cout << "Station data didn't create! Please, enter them and try again." << endl;
                
                break;
            }
            
            case 5:
            {
                if (pgroup.size() != 0)
                {
                    cout << "Do you want to edit all pipes or one? Please, enter '1' if all or '2' if multiple pipes: ";
                    switch (GetCorrectNumber(1, 2))
                    {
                        case 1:
                        {
                            for (auto&  p:pgroup)
                                EditPipe(p);
                            break;
                        }
                        case 2:
                        {
                            cout << "How many pipes do you want to edit? Please, enter integer value of pipes (1, " << pgroup.size() << "):";
                            int n = GetCorrectNumber(1u, (unsigned int) pgroup.size());
                            for (int i = 0; i < n; i++)
                                EditPipe(SelectPipe(pgroup));
                            break;
                        }
                    }
                }
                                
                else
                    cout << "Pipe data didn't create! Please, enter them and try again." << endl;
                break;
            }
            case 6:
            {
                if (sgroup.size() != 0)
                {
                    cout << "Do you want to edit all stations or one? Please, enter '1' if all or 2 if multiple stations: ";
                    switch (GetCorrectNumber(1, 2))
                    {
                        case 1:
                        {
                            for (auto& s:sgroup)
                                EditStation(s);
                            break;
                        }
                        case 2:
                        {
                            cout << "How many stations do you want to edit? Please, enter integer value of stations (1, " << sgroup.size() << "):";
                            int n = GetCorrectNumber(1u, (unsigned int) sgroup.size());
                            for (int i = 0; i < n; i++)
                                EditStation(SelectStation(sgroup));
                            break;
                        }
                    }
                }
                                
                else
                    cout << "Station data didn't create! Please, enter them and try again." <<endl;
                break;
            }
            case 7:
            {
                
                string filename;
                cout << "Enter file name, please:";
                cin >> ws;
                getline(cin, filename);
                ofstream fout;
                fout.open(filename + ".txt", ios::out);
   
                if (!fout.is_open())
                {
                    cout << "File open error!" << endl;
                }
                else
                {
                    fout << pgroup.size() << endl;
                    for(pipe& p:pgroup)
                        SavePipe(fout, p);
                    fout << sgroup.size() << endl;
                    for (station& s:sgroup)
                        SaveStation(fout, s);
                        
                        fout.close();
                }
                break;
            }
         
            case 8:
            {
                
                string filename;
                string str;
                cout << "Enter file name, please:";
                ifstream fin;
                fin.open(filename + ".txt", ios::in);
                
                if (!fin.is_open())
                {
                    cout << "File open error!" << endl;
                }
                else
                {
                    while (!fin.eof())
                    {
                        getline(fin, str);
                        {
                            if (str == "Pipe:")
                            pgroup.push_back(LoadPipe(fin));
                            
                        }
                        if (str == "Station:")
                        {
                            sgroup.push_back(LoadStation(fin));
                           
                        }
                    }
                                    
                   
                        //fin.close();
                    
                }
                break;
            }
            case 9:
            {
                string name = "Unknown";
               for (int i: FindPipeByFilter(pgroup, CheckByName, name))
                   cout << sgroup[i];
                break;
            }
            case 10:
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

