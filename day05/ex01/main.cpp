/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:14:11 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 20:14:12 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Misery("Misery", 130);
    Form A346N43("A346N43", 60, 70);
    Form A544("A544", 140, 135);

    Misery.signForm(A346N43);
    std::cout << A346N43 << std::endl;
    Misery.signForm(A544);
    std::cout << A544 << std::endl;
}
