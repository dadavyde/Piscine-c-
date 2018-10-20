/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:53:12 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 16:53:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "GameEntity.hpp"
#include "Bullet.hpp"
#include <ncurses.h>

class Player : public GameEntity
{
	public:
		Player(void);
		Player(const int y, const int x, const int id);
		virtual ~Player(void);
		Player(Player const & obj);
		Player & operator=(Player const & obj);

};

#endif
