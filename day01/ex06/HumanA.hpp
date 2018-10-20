/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:54:03 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 19:54:04 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void    attack();

private:
    std::string     name_;
    Weapon          &weapon_;
};

#endif
