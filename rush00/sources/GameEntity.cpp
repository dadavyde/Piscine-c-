/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:27:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 16:27:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity() {

	return ;
}

GameEntity::GameEntity(const int y, const int x, const int id)  {

	if (x >= 0)
		_x = x;
	if (y >= 0)
		_y = y;
	_damage = 5;
	_hp = 100;
	_id = id;
	return ;
}

GameEntity::~GameEntity(void) {

	return ;
}

GameEntity::GameEntity(GameEntity const & obj) {

	if (this != &obj) {
		*this = obj;
	}
	return ;
}

GameEntity & GameEntity::operator=(GameEntity const & obj) {

	this->_x = obj.getCoordX();
	this->_y = obj.getCoordY();
	this->_w = obj.getWidth();
	this->_h = obj.getHeight();

	return *this;
}

		
void	GameEntity::setCoordX(int const x) {

	this->_x = x;
	return ;
}
		
int		GameEntity::getCoordX(void) const {

	return this->_x;
}

		
void	GameEntity::setCoordY(int const y) {

	this->_y = y;
	return ;
}
		
int		GameEntity::getCoordY(void) const {

	return this->_y;
}

int		GameEntity::getWidth(void) const {

	return this->_w;
}

int		GameEntity::getHeight(void) const {

	return this->_h;
}


void	GameEntity::moveLeft(int const minwinX) {

	if (this->_x > minwinX) {
		this->_x--;
	}
	return ;
}

void	GameEntity::moveRight(int const maxwinX) {

	if (this->_x + this->_w < maxwinX) {
		this->_x++;
	}
	return ;
}

void	GameEntity::moveUp(int const minwinY) {

	if (this->_y > minwinY) {
		this->_y--;
	}
	return ;
}

void	GameEntity::moveDown(int const maxwinY) {

	if (this->_y + this->_h + 1 < maxwinY) {
		this->_y++;
	}
	return ;
}

int		GameEntity::getShoutPosX(void) const {

	return this->_shoutPosX;
}

int		GameEntity::getShoutPosY(void) const {

	return this->_shoutPosY;
}

std::string		GameEntity::getForm(int index) {

	if (index < 0 || index > this->_h){
		return "";
	}
	return this->_form[index];
}

int			GameEntity::get_hp() const
{
	return _hp;
}

void		GameEntity::set_hp(int _hp)
{
	GameEntity::_hp = _hp;
}

char		GameEntity::getFormBullet(void) const {

	return _form_bullet;
}

void		GameEntity::setFormBullet(char form) {

	_form_bullet = form;
	return ;
}

int			GameEntity::getDamage(void) const {

	return this->_damage;
}

void		GameEntity::setDamage(int damage) {

	this->_damage = damage;
	return ;
}

int			GameEntity::takeDamage(int const dmg) {

	_hp -= dmg;
	if (_hp <= 0)
		return -1;
	return 0;
}

int		GameEntity::getId(void) const {

	return _id;
}
