/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:09:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:09:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EX02_C_HPP
#define EX02_C_HPP

#include "Base.hpp"

class C : public Base
{
public:
	C();
	virtual ~C();
	C(const C &other);
	C &operator=(const C &other);
};


#endif //EX02_C_HPP
