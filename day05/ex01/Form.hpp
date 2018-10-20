/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:15:20 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:15:31 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIGGY_FORM_HPP
#define PIGGY_FORM_HPP

#include <string>

class Bureaucrat;

class Form {
public:
    Form(std::string name, int gradeRequiredSign, int gradeRequiredExecute);
    virtual ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    void  beSigned(Bureaucrat &Joy);
    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException();
        ~GradeTooHighException() throw();
        GradeTooHighException(const GradeTooHighException &other);
        GradeTooHighException &operator=(const GradeTooHighException &other);
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException();
        ~GradeTooLowException() throw();
        GradeTooLowException(const GradeTooLowException &other);
        GradeTooLowException &operator=(const GradeTooLowException &other);
        virtual const char* what() const throw();
    };
    bool  getSigned();
    int get_gradeRequiredSign();
    int get_gradeRequiredExecute();
    std::string const  getName();

private:
    std::string   name_;
    int const  gradeRequiredSign_;
    int const  gradeRequiredExecute_;
    bool  signed_;
};

std::ostream & operator<<(std::ostream &os, Form &f);


#endif //PIGGY_FORM_HPP
