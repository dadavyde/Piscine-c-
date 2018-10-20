/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:53:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 16:53:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <ncurses.h>

Player::Player(const int y, const int x, const int id) : GameEntity(y, x, id) {

	this->_shoutPosX = 6;
	this->_shoutPosY = 2;
	this->_hp = 100;
	this->_h = 5;
	this->_w = 7;
	this->_form[0] = "8>-";
	this->_form[1] = "  <<=";
	this->_form[2] = "{}==->";
	this->_form[3] = "  <<=";
	this->_form[4] = "8>-";
	_form_bullet = '=';
	return ;
}

Player::~Player(void) {

	return ;
}

Player::Player(Player const & obj) : GameEntity(obj) {

	return ;
}

Player &	Player::operator=(Player const & obj) {

	GameEntity::operator=(obj);
	return *this;
}
