/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:12:25 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 19:12:28 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
    if (grade > LOW_EXCEPT)
    {
        throw GradeTooLowException();
    }
    else if (grade < HIGH_EXCEPT)
    {
        throw GradeTooHighException();
    }
    grade_ = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade_ = other.grade_;
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

//++ --

Bureaucrat Bureaucrat::operator++ (int)
{
    Bureaucrat  incr(*this);

    if (grade_ - 1 < HIGH_EXCEPT)
    {
        throw GradeTooLowException();
    }
    grade_--;
    return (incr);
}

Bureaucrat Bureaucrat::operator++ ()
{
    if (grade_ - 1 < HIGH_EXCEPT)
    {
        throw GradeTooLowException();
    }
    --grade_;
    return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
    Bureaucrat  incr(*this);

    if (grade_ + 1 > LOW_EXCEPT)
    {
        throw GradeTooLowException();
    }
    grade_++;
    return (incr);
}

Bureaucrat Bureaucrat::operator--()
{
    if (grade_ + 1 > LOW_EXCEPT)
    {
        throw GradeTooLowException();
    }
    ++grade_;
    return (*this);
}

//stream

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
    return os;
}

//getters

int Bureaucrat::getGrade()
{
    return grade_;
}

std::string Bureaucrat::getName()
{
    return name_;
}
