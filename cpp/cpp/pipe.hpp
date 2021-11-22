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

#endif /* pipe_hpp */

class pipe
{
    int id;
public:
    

    static int MaxID;
    double length;
    double diameter;
    bool vremont;
    
    pipe();

    void EditVremont(pipe& p);
    
    int GetID() const;
    void SetID();
    
    friend std::ostream& operator << (std::ostream& out, const pipe& p);
    friend std::istream& operator >> (std::istream& in, pipe& p);
   
};