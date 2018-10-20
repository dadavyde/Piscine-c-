/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:13:59 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:14:04 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include "Form.hpp"

#define LOW_EXCEPT 0
#define HIGH_EXCEPT 150

class Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException();
        virtual ~GradeTooHighException() throw();
        GradeTooHighException(const GradeTooHighException &other);
        GradeTooHighException &operator=(const GradeTooHighException &other);
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException();
        virtual ~GradeTooLowException() throw();
        GradeTooLowException(const GradeTooLowException &other);
        GradeTooLowException &operator=(const GradeTooLowException &other);
        virtual const char* what() const throw();
    };

    std::string  getName(void);
    int  getGrade(void);
    void  signForm(Form &form);


private:
    std::string  const name_;
    int  grade_;
};


std::ostream & operator<<(std::ostream &os, Bureaucrat &b);

#endif //PIGGY_BUREAUCRAT_HPP
