/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:27:23 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 16:27:24 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

#include <iostream>
#include <string>
#include <ncurses.h>

class	GameEntity
{
	public:
		GameEntity(void);
		GameEntity(const int y, const int x, const int id);
		virtual ~GameEntity(void);
		GameEntity(GameEntity const & obj);
		GameEntity & operator=(GameEntity const & obj);

		void	setCoordX(int const x);
		int		getCoordX(void) const ;

		void	setCoordY(int const y);
		int		getCoordY(void) const ;

		int		getWidth(void) const ;
		int		getHeight(void) const ;

		int		shoutPosX(void) const ;
		int		shoutPosY(void) const ;

		int		getShoutPosX(void) const ;
		int		getShoutPosY(void) const ;

		char	getFormBullet(void) const;
		void	setFormBullet(char form);

		int		getDamage(void) const ;
		void	setDamage(int damage) ;

		int		getId(void) const ;

		int		takeDamage(int const dmg);

		int		get_hp() const;
		void	set_hp(int _hp);

		void	moveLeft(int const minwinX);
		void	moveRight(int const maxwinX);
		void	moveUp(int const minwinY);
		void	moveDown(int const maxwinX);

		void	drawEntity(void);

		std::string 	getForm(int index);

	protected:
		int			_id;
		int			_x;
		int			_y;
		int			_w;
		int			_h;
		int			_hp;
		int			_shoutPosX;
		int			_shoutPosY;
		std::string	_form[14];
		char		_form_bullet;
		int			_damage;

};

#endif
