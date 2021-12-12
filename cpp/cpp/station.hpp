//
//  station.hpp
//  cpp
//
//  Created by Vlada Vlada on 21.11.2021.
//

#ifndef station_hpp
#define station_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

#endif /* station_hpp */

class station
{
    int id_st;
    int tsekh;
    int worktsekh;
public:

    static int MaxID_st;
    std::string name_st;
    
    double effect;
    
    station();
    
    static void EditWorktsekh(station& s);
    
    int GetID_ST() const;
    void SetID_ST();
    int Gettsekh() const;
        void Settsekh();
        int Getworktsekh() const;
        void Setworktsekh();

    
    friend std::ostream& operator << (std::ostream& out, const station& s);
    friend std::istream& operator >> (std::istream& in, station& s);
    friend std::ifstream& operator >> (std::ifstream& in, station& cs);
    friend std::ofstream& operator << (std::ofstream& out, const station& cs);
   
};

