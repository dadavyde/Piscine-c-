/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:49:24 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 21:49:24 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <ncurses.h>
#include <iostream>

Enemy::Enemy(const int y, const int x, const int id) : GameEntity(y, x, id) {

	this->_shoutPosX = 0;
	this->_shoutPosY = 2;
	this->_hp = 5;
	this->_h = 3;
	this->_w = 7;
	this->_form[0] = "  +<888";
	this->_form[1] = "+==<<-";
	this->_form[2] = "  +<888";
	_form_bullet = '*';
	return ;
}

Enemy::~Enemy(void) {

	return ;
}

Enemy::Enemy(Enemy const & obj) : GameEntity(obj) {

	return ;
}

Enemy &	Enemy::operator=(Enemy const & obj) {

	GameEntity::operator=(obj);
	return *this;
}
