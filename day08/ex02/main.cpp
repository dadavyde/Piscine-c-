/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:57:18 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/13 16:57:21 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(3);
    mstack.push(17);
    std::cout << "add 3\nadd 17\ntop of stack: " << mstack.top() << std::endl;
    mstack.pop();
	std::cout << "delete top\ntop of stack: " << mstack.top() << std::endl;
    std::cout << "size of stack: " << mstack.size() << std::endl;
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    mstack.push(7);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
	std::cout << "add 4, add 5, add 6, add 7\nsize of stack: " << mstack.size() << std::endl;
	std::cout << "top of stack: " << mstack.top() << std::endl;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
	std::cout << std::endl;
    it = mstack.begin() + 2;
	std::cout << *mstack.begin() << ' ' << *mstack.begin() + 1;
	while (it != ite)
	{
		*it += 2;
		std::cout << " " << *it;
		++it;
	}
    std::stack<int> s(mstack);
    return 0;
}
