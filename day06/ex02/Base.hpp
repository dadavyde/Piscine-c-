/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:06:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:06:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
public:
	Base();
	virtual ~Base();
	Base(const Base &other);
	Base &operator=(const Base &other);

};


#endif
