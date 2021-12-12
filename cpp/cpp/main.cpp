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
#include <tuple>
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

/*void SavePipe(ofstream& fout, const pipe& p)
{
    if (p.length != 0 && p.diameter != 0)
    {
    fout << "Pipe:" << endl << p.GetID() << endl << p.name << endl <<  p.length << endl << p.diameter << endl << p.vremont << endl;
        }
        
       
    }

void SaveStation(ofstream& fout, const station& s)
{
    if (s.tsekh != 0)
    {
        fout << "Station:" << endl << s.GetID_ST() << endl << s.name_st << endl << s.tsekh << endl << s.worktsekh  << endl << s.effect << endl;
    }
   
}*/

void Load(ifstream& fin, unordered_map<int, pipe>& pgroup, unordered_map<int, station>& sgroup)
{
    pipe p;
    station s;
    int i = 0;
    int p_size;
    fin >> p_size;
    while (p_size != 0)
    {
        fin >> p;
        for (auto& [id, pipe] : pgroup)
        {
            if (p.GetID() == id)
                i++;
        }
        if (i == 0)
        {
            p.MaxID++;
            pgroup.emplace(p.MaxID, p);
        }
        else
            i = 0;
        --p_size;
    }

    int j = 0;
    int s_size;
    fin >> s_size;
    while (s_size != 0)
    {
        fin >> s;
        for (auto& [id, station] : sgroup)
        {
            if (s.GetID_ST() == id)
                j++;
        }
        if (j == 0)
        {
            s.MaxID_st++;
            sgroup.emplace(s.MaxID_st, s);
        }
        else
            j = 0;
        --s_size;
    }
}
 
void Printmenu()
{
    cout << "(1) Create Pipe" << endl
    << "(2) Create Compressor station" << endl
    << "(3) Print Pipe" << endl
    << "(4) Print Compressor station" << endl
    << "(5) Edit Pipe" << endl
    << "(6) Edit Station" << endl
    << "(7) Delete Pipe" << endl
    << "(8) Delete Station" << endl
    << "(9) Save to file" << endl
    << "(10) Load from file" << endl
    << "(11) Find by filter" << endl
    << "(0) Exit" << endl
    << "Enter number, please:" << endl;
}

pipe& SelectPipe(unordered_map<int, pipe>& p)
{
    /*if (p.size() == 0)
  cout << "Pipe data didn't create! Please, enter them and try again." << endl;
     else*/
    cout << "Enter index (1," << p.size() << "): ";
    unsigned int index = GetCorrectNumber(1u, (unsigned int) p.size());
    return p[index];
    
       
           
       
    
}
    
station& SelectStation(unordered_map<int, station>& s)
{
    /*if (s.size() == 0)
        cout << "Station data didn't create! Please, enter them and try again." << endl;
    else
    */
        cout << "Enter index (1," << s.size() << "): ";
        unsigned int index = GetCorrectNumber (1u, (unsigned int) s.size());
        return s[index];
    
    
    
}

void DeletePipe(unordered_map<int, pipe>& p)
{
    /*if (p.size() == 0)
  cout << "Pipe data didn't create! Please, enter them and try again." << endl;
     else*/
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber (1u, (unsigned int) p.size());
    p.erase(index );
    
}

void DeleteStation(unordered_map<int, station>& s)
{
    /*if (s.size() == 0)
        cout << "Station data didn't create! Please, enter them and try again." << endl;
    else
    */
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber (1u, (unsigned int) s.size());
    s.erase(index);
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
vector <int> FindPipeByFilter(const unordered_map<int, pipe>& pgroup, Filter<T> f, T param)
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
    double procent = (s.Gettsekh()-s.Getworktsekh())*100/s.Gettsekh();
    return procent == param;
}
template<typename T>
vector <int> FindStationByFilter(const unordered_map<int, station>& sgroup, Filter_st<T> f, T param)
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
    unordered_map  <int, pipe> pgroup = {};
    unordered_map  <int, station> sgroup = {};
    pipe p;
    station s;
    /*vector<pipe> pgroup;
    vector<station> sgroup;*/
    
    while (1)
    {
        Printmenu();
        switch (GetCorrectNumber(0, 11))
        {
            case 1:
            {
                
                cin >> p;
                pgroup.emplace (p.MaxID, p);
                break;
            }
            case 2:
            {
                
                cin >> s;
                sgroup.emplace (s.MaxID_st, s);
                break;
            }
            case 3:
            {
                if (pgroup.size() != 0)
                {
                    for (const auto& [id, p]: pgroup)
                    {
                        cout << id;
                        cout << p << endl;
                    }
                                        
                }
                
                else
                    cout << "Pipe data didn't create! Please, enter them and try again." << endl;
                break;
               
            }
            case 4:
            {
                if (sgroup.size() != 0)
                {
                    for (const auto& [id, s] : sgroup)
                    {
                        cout << id;
                        cout << s << endl;
                    }
                }
                
                else
                    cout << "Station data didn't create! Please, enter them and try again." << endl;
                
                break;
            }
            
            case 5:
            {
                if (pgroup.size() != 0)
                {
                    cout << "Please, enter '1' if you want to edit all pipes or '2' if several: ";
                    switch (GetCorrectNumber(1, 2))
                    {
                        case 1:
                        {
                            for (auto&  [id, p]:pgroup)
                                EditPipe(p);
                            break;
                        }
                        case 2:
                        {
                            cout << "Please, enter integer value of pipes (1, " << pgroup.size() << "):";
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
                    cout << "Please, enter '1' if you want to edit all stations or '2' if several : ";
                    switch (GetCorrectNumber(1, 2))
                    {
                        case 1:
                        {
                            for (auto& [id, s]:sgroup)
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
                DeletePipe(pgroup);
                break;
            }
            case 8:
            {
                DeleteStation(sgroup);
                break;
            }
            case 9:
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
                    /*fout << pgroup.size() << endl;
                    for(pipe& p:pgroup)
                        SavePipe(fout, p);
                    fout << sgroup.size() << endl;
                    for (station& s:sgroup)
                        SaveStation(fout, s);*/
                    fout << pgroup.size() << endl;
                    fout << sgroup.size() << endl;
                    for (const auto& [id, p] : pgroup)
                        fout << p;
                    for (const auto& [id, k] : sgroup)
                        fout << k;
                        
                        fout.close();
                }
                break;
            }
         
            case 10:
            {
                
                string filename;
                cout << "Enter file name, please:";
                cin.ignore(10000, '\n');
                getline(cin, filename);
                ifstream fin;
                fin.open(filename + ".txt", ios::in);
                
                if (!fin.is_open())
                {
                    cout << "File open error!" << endl;
                }
                else
                {
                    Load(fin, pgroup, sgroup);
                    fin.close();
                    
                }
                break;
            }
            
            case 11:
            {
                cout << "What do you want to do?" << endl
                << "(1) Filter pipes" << endl
                << "(2) Filter stations" << endl;
            switch (GetCorrectNumber(1,2))
            {
                case 1:
                {
                    cout << "What filter do you want to use?" << endl
                    << "(1) Check by name" << endl
                    << "(2) Check by sign 'under repair'" << endl;
                    switch (GetCorrectNumber(1,2))
                    {
                        case 1:
                        {
                            string name;
                            cin >> ws;
                            cin.ignore(2000, '\n');
                            cout << "Enter pipe name: ";
                            getline(cin, name);
                            for (int i: FindPipeByFilter(pgroup, CheckByName, name))
                            cout << pgroup[i];
                            break;
                        }
                        case 2:
                        {
                            cout << "Enter '0' if pipes don't work and '1' if pipes work: ";
                            bool vremont = GetCorrectNumber(0, 1);
                            for (int i: FindPipeByFilter(pgroup, CheckByVremont, vremont))
                            cout << pgroup[i];
                            break;
                        }
                    }
                    
                    break;
                }
                case 2:
                {
                    cout << "What filter do you want to use?" << endl
                    << "(1) Check by name" << endl
                    << "(2) Check by percent of non-working tsekh" << endl;
                    switch (GetCorrectNumber(1,2))
                    {
                        case 1:
                        {
                            string name;
                            cin >> ws;
                            cin.ignore(2000, '\n');
                            cout << "Enter station name: ";
                            getline(cin, name);
                            for (int i: FindStationByFilter(sgroup, CheckByName, name))
                            cout << sgroup[i];
                            break;
                        }
                        case 2:
                        {
                            break;
                        }
                    }
                    
                    break;
                }
                
                default:
                {
                    cout << "wrong action" << endl;
                }
                                    
            }
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

