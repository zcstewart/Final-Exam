///Final

/* 
 * Filename:        main.cpp
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       May 4, 2017, 8:30 AM
 */

//--------------------------------------------------------------------------//

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include "set.h"
#include "item.h"


//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//
//Main Function
//
//Inputs:       int argc, char** argv
//Outputs:      int
//
//Purpose:      Main program file. Other necessary files are included here 
//              in order to be run.

int main(int argc, char** argv) 
{
    srand(0);

    set<int> set_one;
    bool test;
    int temp;
    
    for(int i = 1; i < 100; i++)
    {
        set_one.insert(i);
        set_one.print(5);
    }
    
    cout << "Oh No" << endl;
    
    
    set_one.remove(100);
    set_one.remove(99);
    set_one.remove(98);
    
    set_one.print(5);
    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//


