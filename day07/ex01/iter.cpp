/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:56:06 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/11 12:56:08 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(T *arr, size_t N, void func(T &element))
{
	for(size_t i = 0; i < N; i++)
		func(arr[i]);
}

template <typename T>
void	inc(T &a)
{
	a++;
	std::cout << a << "  ";
}

int  main()
{
	int arr[5] = {0, 1, 2 ,3 ,4};

	iter(arr, 5, inc);
	std::cout << std::endl;

	double darr[5] = {0.01, 1.01, 2.01 ,3.01 ,4.01};
	iter(darr, 5, inc);
	std::cout << std::endl;

	float farr[5] = {0.1f, 1.1f, 2.1f ,3.1f ,4.1f};
	iter(farr, 5, inc);
	std::cout << std::endl;

	std::string str("abcde");
	char *p = const_cast<char *>(str.data());
	iter(p, 5, inc);
	std::cout << std::endl;
}
