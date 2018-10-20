/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBoss.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:39:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/07 21:39:37 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyBoss.hpp"
#include <ncurses.h>
#include <iostream>

EnemyBoss::EnemyBoss(const int y, const int x, const int id) : GameEntity(y, x, id) {

	this->_shoutPosX = 0;
	this->_shoutPosY = 3;
	this->_hp = 1000;
	this->_h = 9;
	this->_w = 59;
	this->_form[0] = "                         _______________________";
	this->_form[1] = "              _-_       (|_____________________/";
	this->_form[2] = " ______.-----'---`-----._____/___/";
	this->_form[3] = " \\_____ ------:-:------ _________}   _____________________";
	this->_form[4] = "       `---------------'   \\     \\  (|___________________/";
	this->_form[5] = "             `-_-'         _\\     \\___|  |_____.";
	this->_form[6] = "                          |           |__|     |(-";
	this->_form[7] = "                        -)| <----BOCAL     ,---\'";
	this->_form[8] = "                          |______.--------'";
	_form_bullet = '#';
	_damage = 40;
	return ;
}

EnemyBoss::~EnemyBoss(void) {

	return ;
}

EnemyBoss::EnemyBoss(EnemyBoss const & obj) : GameEntity(obj) {

	return ;
}

EnemyBoss &	EnemyBoss::operator=(EnemyBoss const & obj) {

	GameEntity::operator=(obj);
	return *this;
}

