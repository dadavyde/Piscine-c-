/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:14:57 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:15:07 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeRequiredSign, int gradeRequiredExecute)
        : name_(name), gradeRequiredSign_(gradeRequiredSign),
         gradeRequiredExecute_(gradeRequiredExecute), signed_(false)
{}

Form::~Form()
{}

Form::Form(const Form &other)
        : gradeRequiredSign_(other.gradeRequiredSign_), gradeRequiredExecute_(other.gradeRequiredExecute_),
          signed_(other.signed_)
{}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->signed_ = other.signed_;
    }
    return *this;
}

void Form::beSigned(Bureaucrat &Joy)
{
    if (Joy.getGrade() > gradeRequiredSign_)
        throw GradeTooLowException();
    signed_ = true;
}

//getters

bool Form::getSigned()
{
    return signed_;
}

int Form::get_gradeRequiredExecute()
{
    return gradeRequiredExecute_;
}

int Form::get_gradeRequiredSign()
{
    return gradeRequiredSign_;
}

std::string const Form::getName()
{
    return name_;
}

//stream

std::ostream & operator<<(std::ostream &os, Form &f)
{
    os << "Form " << f.getName() << ((f.getSigned()) ? " is " : " is not ") 
    << "signed, grade required sign: " << f.get_gradeRequiredSign() 
    << ", grade required execute: " << f.get_gradeRequiredExecute();
    return (os);
}

//exceptions

Form::GradeTooHighException::GradeTooHighException()
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &other)
{(void)other;}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(const Form::GradeTooHighException &other)
{
    (void)other;
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Value of bureaucrat's grade is too high!";
}

Form::GradeTooLowException::GradeTooLowException()
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &other)
{(void)other;}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(const Form::GradeTooLowException &other)
{
    (void)other;
    return *this;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Value of bureaucrat's grade is too low!";
}
