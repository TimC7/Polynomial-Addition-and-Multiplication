/*
   File: polynomial.h
   Description: Header file for the Polynomial class. contains a linked list of type Term to store an entire polynomial.
   Created: 4/19/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"
#include <list>
#include <iterator>
#include <iostream>

class Polynomial
{
private:

    std::list<Term> terms;

public:

    /**
    default constructor
    */
    Polynomial();

    /**
    constructor
    @param Term object is pushed onto front of linked list
    */
    Polynomial(Term t);

    /**
    @param pushes term onto front of list
    */
    void add(Term t);

    /**
    @param Term is added to back of linked list
    */
    void add_to_back(Term t);
    
    /**
    @param Polynomial is added onto end of calling Polynomial
    @return returns a result Polynomial
    */
    Polynomial add(Polynomial& p);

    /**
    @param Polynomial is multiplied by calling Polynomial
    @return the result of the multiplication
    */
    Polynomial multiply(Polynomial& p);

    /**
    @param Polynomial that needs like terms to be combined
    @return result of combined terms
    */
    Polynomial combine_like_terms(Polynomial& p);

    /**
    prints the polynomial with x variables and apporiate signs
    */
    void print();
};

#endif


