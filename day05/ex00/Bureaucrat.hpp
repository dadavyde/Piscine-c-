/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:12:33 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 19:12:34 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

#define LOW_EXCEPT 150
#define HIGH_EXCEPT 1

class Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    Bureaucrat  operator++(int);
    Bureaucrat  operator++();
    Bureaucrat  operator--(int);
    Bureaucrat  operator--();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Value of grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Value of grade is too low!";
        }
    };

    std::string  getName(void);
    int  getGrade(void);

private:
    std::string  const name_;
    int  grade_;
};

std::ostream & operator<<(std::ostream &os, Bureaucrat &b);

#endif
