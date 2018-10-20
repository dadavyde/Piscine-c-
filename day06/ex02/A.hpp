/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:09:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:09:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EX02_A_HPP
#define EX02_A_HPP

#include "Base.hpp"

class A : public Base
{
public:
	A();
	virtual ~A();
	A(const A &other);
	A &operator=(const A &other);
};


#endif //EX02_A_HPP
