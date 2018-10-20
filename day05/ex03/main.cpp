/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:35:30 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:35:31 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main()
{
    Intern  someRandomIntern;
    Form*   rrf;

    try
    {
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Obama");
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Cat");
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        rrf = someRandomIntern.makeForm("ShrubberyCreationorm", "BadCase");
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}


