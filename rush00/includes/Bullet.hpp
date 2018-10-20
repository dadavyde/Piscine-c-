/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:16:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 20:16:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include "GameEntity.hpp"
#include <ncurses.h>

# define NUM_ENEMIES 70

class Bullet : public GameEntity
{
	public:
		Bullet(void);
		Bullet(const int y, const int x, const int dirY, const int dirX, int const dmg, const char form);
		virtual ~Bullet(void);
		Bullet(Bullet const & obj);
		Bullet & operator=(Bullet const & obj);

		int		getDamage(void) const;
		char	getForm(void) const;

		void	setDamage(int dmg) const;
		void	setForm(char form) const;

		void	move(void);

		int		colision(GameEntity *elemet[], bool god);

	private :
		int		_dirX;
		int		_dirY;
		int		_damage;
		char	_form;
};

#endif
