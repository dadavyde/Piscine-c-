/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:35:23 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:35:24 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

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
        GradeTooHighException(const GradeTooHighException &other) throw();
        GradeTooHighException &operator=(const GradeTooHighException &other);
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException();
        ~GradeTooLowException() throw();
        GradeTooLowException(const GradeTooLowException &other) throw();
        GradeTooLowException &operator=(const GradeTooLowException &other);
        virtual const char* what() const throw();
    };

    class FormNotSigned : public std::exception
    {
        public:
        FormNotSigned();
        ~FormNotSigned() throw();
        FormNotSigned(const FormNotSigned &other) throw();
        FormNotSigned &operator=(const FormNotSigned &other);
        virtual const char* what() const throw();
    };

    bool  getSigned() const;
    int get_gradeRequiredSign();
    int get_gradeRequiredExecute();
    std::string const  getName() const;

    void  execute(Bureaucrat const & executor) const;//не меняет переменные

    // Abstract method
    virtual void  action() const = 0;


private:
    std::string   name_;
    int const  gradeRequiredSign_;
    int const  gradeRequiredExecute_;
    bool  signed_;
};

std::ostream & operator<<(std::ostream &os, Form &f);


#endif //PIGGY_FORM_HPP
