/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyElite.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:38:10 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/07 21:38:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyElite.hpp"
#include <ncurses.h>
#include <iostream>

EnemyElite::EnemyElite(const int y, const int x, const int id) : GameEntity(y, x, id) {

	this->_shoutPosX = 0;
	this->_shoutPosY = 4;
	this->_hp = 100;
	this->_h = 8;
	this->_w = 11;
	this->_form[0] = "     __";
	this->_form[1] = "       |\\";
	this->_form[2] = "       / \\";
	this->_form[3] = "      / =/";
	this->_form[4] = "(}-==( :[| ";
	this->_form[5] = "      \\ =\\";
	this->_form[6] = "       \\ /";
	this->_form[7] = "     __|/";
	_form_bullet = '+';
	_damage = 20;
	return ;

}

EnemyElite::~EnemyElite(void) {

	return ;
}

EnemyElite::EnemyElite(EnemyElite const & obj) : GameEntity(obj) {

	return ;
}

EnemyElite &	EnemyElite::operator=(EnemyElite const & obj) {

	GameEntity::operator=(obj);
	return *this;
}

