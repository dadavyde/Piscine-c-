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
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <ctime>

int main()
{
    Bureaucrat Misery("Misery", 45);
    Bureaucrat Joy("Joy", 20);

    srand(time(0));
    // Polymorphism example
    Form *AForm;

    AForm = new ShrubberyCreationForm("home");
    try
    {
        std::cout << " \tTry signed ShrubberyCreationForm" << std::endl;
        Joy.signForm(*AForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\tTry execute ShrubberyCreationForm" << std::endl;
        Misery.executeForm(*AForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete AForm;

    AForm = new RobotomyRequestForm("Piggy");
    try
    {
        std::cout << "\tTry signed RobotomyRequestForm" << std::endl;
        Joy.signForm(*AForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\tTry execute RobotomyRequestForm" << std::endl;
        Misery.executeForm(*AForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete AForm;

    AForm = new PresidentialPardonForm("Obama");
    try
    {
        std::cout << "\tTry signed PresidentialPardonForm" << std::endl;
        Joy.signForm(*AForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\tTry execute PresidentialPardonForm" << std::endl;
        Misery.executeForm(*AForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete AForm;

}


//    try
//    {
//        this->getSigned();
//    }
//    catch(std::exception &e)
//    {
//        std::cout << e.what() << std::endl;
//        return;
//    }

