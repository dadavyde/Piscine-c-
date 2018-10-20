/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:04:01 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:04:02 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
public:
    explicit Weapon(std::string type);
    ~Weapon();
    std::string&        getType();
    void                setType(std::string type);

private:
    std::string         type_;
};

#endif
