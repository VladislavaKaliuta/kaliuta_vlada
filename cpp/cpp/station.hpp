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

#endif /* station_hpp */

class station
{
    int id_st;
    
public:

    static int MaxID_st;
    std::string name_st;
    int tsekh;
    int worktsekh;
    double effect;
    
    station();
    
    void EditWorktsekh(station& s);
    
    int GetID_ST() const;
    void SetID_ST();
    
    friend std::ostream& operator << (std::ostream& out, const station& s);
    friend std::istream& operator >> (std::istream& in, station& s);
};

