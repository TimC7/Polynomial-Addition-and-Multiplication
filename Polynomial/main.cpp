/*
   File: main.cpp
   Description: Stores polynomials in a class Polynomial as a linked list of class Term, which contains the coefficient and the power of x. It then demonstrates that
            the polynomials can be added, multiplied, and printed.
   Created: 4/19/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include <iostream>

#include "polynomial.h"


int main()
{
    Polynomial p(Term(-10, 0));
    p.add(Term(-1, 1));
    p.add(Term(9, 7));
    p.add(Term(5, 10));

    std::cout << "The starting polynomial: ";

    p.print();

    Polynomial q = p.add(p);

    std::cout << std::endl << "The polynomial added to an identical polynomial: ";
    
    q.print();
    
    std::cout << std::endl << "The original polynomial multiplied by an identical polynomial: ";

    q = p.multiply(p);

    q.print();

    return 0;
}

