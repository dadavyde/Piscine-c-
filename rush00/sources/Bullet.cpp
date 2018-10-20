/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:16:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 20:16:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include <ncurses.h>

Bullet::Bullet(const int y, const int x, const int dirY, const int dirX, int const dmg, const char form) : GameEntity(y, x, -1) {

	this->_h = 0;
	this->_w = 1;
	this->_damage = dmg;
	this->_dirX = dirX;
	this->_dirY = dirY;
	this->_form = form;
	return ;
}

Bullet::~Bullet(void) {

	return ;
}

Bullet::Bullet(Bullet const & obj) : GameEntity(obj) {

	return ;
}

Bullet &	Bullet::operator=(Bullet const & obj) {

	GameEntity::operator=(obj);
	return *this;
}

void		Bullet::move(void) {

	_x += _dirX;
	_y += _dirY;
	return ;
}

char		Bullet::getForm(void) const {

	return _form;
}

int			Bullet::colision(GameEntity *Entities[], bool god) {

	int		x = _x + 1;
	int		y = _y;

	for (int e = 0; e < NUM_ENEMIES; ++e)
	{
		if (Entities[e])
		{
			if ((x <= Entities[e]->getCoordX() && Entities[e]->getCoordX() <= x + _w &&
				y <= Entities[e]->getCoordY() && Entities[e]->getCoordY() <= y + _h) ||
				(Entities[e]->getCoordX() <= x && x <= Entities[e]->getCoordX() + Entities[e]->getWidth() &&
				Entities[e]->getCoordY() <= y && y <= Entities[e]->getCoordY() + Entities[e]->getHeight()))
			{
				if (Entities[e]->takeDamage(_damage) < 0)
				{
					if ((e == 0 || e == 1) && god) {
						return 0;
					}
					system("afplay music/boom.mp3 &");
					int ret = Entities[e]->getId();
					delete Entities[e];
					Entities[e] = NULL;
					return ret;
				}
				return 0;
			}
		}
	}
	return -1;
}

