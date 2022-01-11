/*
   File: term.h
   Description: Header file for the Term class. Contains a coefficient and the power of x.
   Created: 4/19/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#ifndef TERM_H
#define TERM_H

class Term
{
private:

    int coefficient, power; //the coefficient and the power of x

public:

    /**
    default constructor
    */
    Term();

    /**
    constructor
    @param sets the member variables
    */
    Term(int _coefficient, int _power);

    /**
    @return the coefficient variable
    */
    int get_coefficient();

    /**
    @return the power variable
    */
    int get_power();

    /**
    @param sets the coefficient variable
    */
    void set_coefficient(int c);

    /**
    @param sets the power variable
    */
    void set_power(int p);


};

#endif