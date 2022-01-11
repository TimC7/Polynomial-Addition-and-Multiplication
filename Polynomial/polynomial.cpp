/*
   File: polynomial.cpp
   Description: Implementation for the Polynomial class.
   Created: 4/19/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include "polynomial.h"

Polynomial::Polynomial()
{
    Term t;
    terms.push_front(t);
}

Polynomial::Polynomial(Term t)
{
    terms.push_front(t);
}



void Polynomial::add(Term t)
{
    terms.push_front(t);
}

Polynomial Polynomial::add(Polynomial& p)
{
    std::list<Term>::iterator iter2 = p.terms.begin();
    Polynomial result = *this; 
   
    while (iter2 != p.terms.end())
    {
        Term t = *iter2;
        result.terms.push_back(t); //parameter Polynomial is added to the end of the original
        iter2++;
    }
 
    result = combine_like_terms(result);
    return result;
}

void Polynomial::add_to_back(Term t)
{
    terms.push_back(t); //adds to back instead of front
}

Polynomial Polynomial::multiply(Polynomial& p)
{
    std::list<Term>::iterator iter1 = terms.begin();
    std::list<Term>::iterator iter2 = p.terms.begin();
    Polynomial result;
    Term temp_term; //term to be added to the result

    //iterates through the lists of both polynomials and multiplies them
    while (iter1 != terms.end())
    {
        Term t1 = *iter1;
        while (iter2 != p.terms.end())
        {
            Term t2 = *iter2;
            
            temp_term.set_coefficient(t1.get_coefficient() * t2.get_coefficient());

            temp_term.set_power(t1.get_power() + t2.get_power());
            
            result.add_to_back(temp_term);

            iter2++;
        }
        iter2 = p.terms.begin();
        iter1++;
    }

    result.terms.pop_front(); 
   
    result = combine_like_terms(result); //simplify

    return result;
}

Polynomial Polynomial::combine_like_terms(Polynomial& p)
{
    Polynomial result;
    std::list<Term>::iterator iter1 = p.terms.begin();
    std::list<Term>::iterator iter2 = std::next(iter1, 1); //is set equal to the next element so that the term is not added to itself
    std::list<Term>::iterator iter3 = result.terms.begin();

    bool no_like_terms = true, not_encountered_before = true; //first one is a flag to check whether the term has any other terms it can be added to
                                                              //second is a flag to check whether the term in the first list has been added already
    while (iter1 != p.terms.end())
    {
        Term t1 = *iter1;
        Term temp_term;
        iter3 = result.terms.begin();

        //check to see if term has already been added so it can be skipped. Makes a term that has already been combined is not added to the result.
        while (iter3 != result.terms.end())
        {
            Term t3 = *iter3;
            if (t1.get_power() == t3.get_power() && t3.get_coefficient() != 0)
            {
                not_encountered_before = false;

            }
            iter3++;
        }

        iter2 = std::next(iter1, 1);
        while (iter2 != p.terms.end() && not_encountered_before)
        {
            Term t2 = *iter2;

            if (t1.get_power() == t2.get_power()) //if powers are the same, the coefficients can be combined
            {
                no_like_terms = false; //a like term has been found so this is set to false
                if (temp_term.get_coefficient() == 0) //if this is the first combination with these exponents then the temp_term coefficient should be zero
                {
                    temp_term.set_coefficient(t1.get_coefficient() + t2.get_coefficient());
                }
                else //if temp_term is not zero, then the t2 term should be added to the already existing coefficient in temp_term. Should allow for correct addition even if there are more than 2 like terms.
                {
                    temp_term.set_coefficient(temp_term.get_coefficient() + t2.get_coefficient()); 
                }
                temp_term.set_power(t1.get_power());
            }

            iter2++;

        }
        if (no_like_terms && not_encountered_before)
        {
            temp_term.set_coefficient(t1.get_coefficient());
            temp_term.set_power(t1.get_power());
        }
     
        if (not_encountered_before)
        {
           result.add_to_back(temp_term);
        }

        //does not push a term onto the result if the term has already been added
 
        no_like_terms = true;
        not_encountered_before = true;
        iter1++;
    }

    result.terms.pop_front();

    return result;
}



void Polynomial::print()
{   
    Polynomial temp = *this;
    std::list<Term>::iterator iter = temp.terms.begin();
    Term t = *iter;

    //if statement for the first coefficient. If it is positive, it doesn't need a positive sign and should be treated differently than the rest of
    //the polynomial. If it is negative then the negative will be shown and will not include spaces, which will look better
    if (iter != temp.terms.end())
    {
        std::cout << t.get_coefficient();
    }
    while (iter != temp.terms.end()) 
    {
        t = *iter;
        
        if (t.get_power() > 1) //if it has a nonzero power, an x will be displayed
        {
            std::cout << "x^" << t.get_power();
        }
        else if (t.get_power() == 1) //if the power is only 1, then the "^" will not be displayed
        {
            std::cout << "x";
        }

        iter++;

        if (iter != temp.terms.end())
        { 
            t = *iter;
            
            if (t.get_coefficient() > 0)
            {
                std::cout << " + ";
                if (t.get_coefficient() != 1) //if coefficient is 1 or -1 then the one won't be displayed,
                {
                    std::cout << t.get_coefficient();
                }
                if (t.get_power() == 0 && t.get_coefficient() == 1) //makes sure 1 can be displayed if the power of the x value is 0
                {
                    std:: cout << t.get_coefficient(); 
                }
            }
            else if (t.get_coefficient() < 0)
            {
                std::cout << " - "; //spaces to make it easier to read
                
                if (t.get_coefficient() != -1)
                {
                    t.set_coefficient(t.get_coefficient() * -1); //allows the negative to be displayed as a subtraction sign instead of a negative sign right in front of the number
                    std::cout << t.get_coefficient();
                }
                if (t.get_power() == 0 && t.get_coefficient() == -1)
                {
                    t.set_coefficient(t.get_coefficient() * -1);
                    std::cout << t.get_coefficient();
                }
            }
            
        }
    }
    
}



