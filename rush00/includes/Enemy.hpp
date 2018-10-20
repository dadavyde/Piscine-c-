/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:49:28 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 21:49:29 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Enemy_HPP
# define Enemy_HPP

#include "GameEntity.hpp"
#include "Bullet.hpp"
#include <ncurses.h>




class Enemy : public GameEntity
{
	public:
		Enemy(void);
		Enemy(const int y, const int x, const int id);
		virtual ~Enemy(void);
		Enemy(Enemy const & obj);
		Enemy & operator=(Enemy const & obj);

};

#endif
