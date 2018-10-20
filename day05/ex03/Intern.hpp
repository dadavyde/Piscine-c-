/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:17:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 22:17:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	virtual ~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	Form  *makeForm(std::string nameForm, std::string targetForm);


    class BadNameForm : public std::exception
    {
    public:
	    BadNameForm();
	    ~BadNameForm() throw();
	    BadNameForm(const BadNameForm &other) throw();
	    BadNameForm &operator=(const BadNameForm &other);
	    virtual const char* what() const throw();
	};

};


#endif
