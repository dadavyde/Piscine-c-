/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyElite.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:38:04 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/07 21:38:05 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EnemyElite_HPP
# define EnemyElite_HPP

#include "GameEntity.hpp"
#include "Bullet.hpp"
#include <ncurses.h>

class EnemyElite : public GameEntity
{
	public:
		EnemyElite(void);
		EnemyElite(const int y, const int x, const int id);
		virtual ~EnemyElite(void);
		EnemyElite(EnemyElite const & obj);
		EnemyElite & operator=(EnemyElite const & obj);

};

#endif

