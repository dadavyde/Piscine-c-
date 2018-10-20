/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:17:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 22:17:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::Intern(const Intern &other)
{
	(void)other;
}


Form* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	Form    **p;
	Form	*Aform;

	if (nameForm != "PresidentialPardonForm" && nameForm != "RobotomyRequestForm" && nameForm != "ShrubberyCreationForm")
	{
		throw BadNameForm();
	}
	if (nameForm == "PresidentialPardonForm")
		Aform = new PresidentialPardonForm(targetForm);
	else if (nameForm == "RobotomyRequestForm")
		Aform = new RobotomyRequestForm(targetForm);
	else if (nameForm == "ShrubberyCreationForm")
		Aform = new ShrubberyCreationForm(targetForm);
	p = &Aform;
	std::cout << "Intern creates " << nameForm << std::endl;
	return *p;
}


Intern::BadNameForm::BadNameForm()
{}

Intern::BadNameForm::~BadNameForm() throw()
{}

Intern::BadNameForm::BadNameForm(const Intern::BadNameForm &other) throw()
{(void)other;}

Intern::BadNameForm& Intern::BadNameForm::operator=(const Intern::BadNameForm &other)
{
    (void)other;
    return *this;
}

const char* Intern::BadNameForm::what() const throw()
{
    return "Error creating!";
}
