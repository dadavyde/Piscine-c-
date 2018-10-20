/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:12:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/11 11:12:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
T min(T const & n1, T const & n2)
{
	return (n1 < n2) ? n1 : n2;
}

template <typename T>
T max(T const & n1, T const & n2)
{
	return (n1 > n2) ? n1 : n2;
}

template <typename T>
void swap(T &n1, T &n2)
{
	T temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

int main()
{
	int  num1 = -2;
	int  num2 = 42;
	double  d_num1 = -0.25;
	double  d_num2 = -0.251;
	char  char1 = 'a';
	char  char2 = '-';

	std::cout << '\n' << ::max(num1, num2) << " is larger then " << ::min(num1, num2) << std::endl;
	std::cout << ::max(d_num1, d_num2) << " is larger then " << ::min(d_num1, d_num2) << std::endl;
	std::cout << '\'' << ::max(char1, char2) << '\'' << " has larger ASCII value then "
			  << '\'' << ::min(char1, char2) << '\'' << std::endl;

	std::cout << "\n\tBefore swap:" << std::endl;
	std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
	std::cout << "d_num1 = " << d_num1 << ", d_num2 = " << d_num2 << std::endl;
	std::cout << "char1 = \'" << char1 << "\', char2 = \'" << char2 << '\''<< std::endl;
	::swap(num1, num2);
	::swap(d_num1, d_num2);
	::swap(char1, char2);
	std::cout << "\n\tAfter swap:" << std::endl;
	std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
	std::cout << "d_num1 = " << d_num1 << ", d_num2 = " << d_num2 << std::endl;
	std::cout << "char1 = \'" << char1 << "\', char2 = \'" << char2 << '\''<< std::endl;
}
