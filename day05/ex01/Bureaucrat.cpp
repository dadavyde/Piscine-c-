/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:13:49 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:13:55 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
    if (grade > HIGH_EXCEPT)
    {
        throw GradeTooLowException();
    }
    else if (grade < LOW_EXCEPT)
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

Bureaucrat::GradeTooHighException::GradeTooHighException()
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &other)
{(void)other;}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &other)
{
    (void)other;
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Value of grade is too high!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &other)
{(void)other;}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &other)
{
    (void)other;
    return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Value of grade is too low!";
}

int Bureaucrat::getGrade()
{
    return grade_;
}

std::string Bureaucrat::getName()
{
    return name_;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << *this << " signed form " << form.getName() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << *this << " cannot sign form " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream & operator<<(std::ostream &os, Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
