//
//  pipe.hpp
//  cpp
//
//  Created by Vlada Vlada on 21.11.2021.
//

#ifndef pipe_hpp
#define pipe_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

#endif /* pipe_hpp */

class pipe
{
    int id;
public:
    

    static int MaxID;
    std::string name;
    double length;
    double diameter;
    bool vremont;
    
    pipe();

    void EditVremont(pipe& p);
    
    int GetID() const;
    void SetID();
    
    friend std::ostream& operator << (std::ostream& out, const pipe& p);
    friend std::istream& operator >> (std::istream& in, pipe& p);
    friend std::ifstream& operator >> (std::ifstream& in, pipe& p);
        friend std::ofstream& operator << (std::ofstream& out, const pipe& p);
   
};
