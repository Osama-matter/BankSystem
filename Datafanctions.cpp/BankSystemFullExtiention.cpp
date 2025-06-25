#include <iostream>
#include "ClsLogIn.h"
int main()

{
    // using While loop to avoid a sikular refrance  . 
    
    while (true)
    {
        if (!ClsLogIn::Login())
        {
            break; 
        }
    }


    return 0;
}