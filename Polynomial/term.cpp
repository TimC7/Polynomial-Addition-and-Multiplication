/*
   File: term.cpp
   Description: Implementation of the Term class.
   Created: 4/19/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include "term.h"

Term::Term()
{
    coefficient = 0;
    power = 0;
}

Term::Term(int _coefficient, int _power)
{
    coefficient = _coefficient;
    power = _power;
} 

int Term::get_coefficient()
{
    return coefficient;
}

int Term::get_power()
{
    return power;
}

void Term::set_coefficient(int c)
{
    coefficient = c;
}

void Term::set_power(int p)
{
    power = p;
}