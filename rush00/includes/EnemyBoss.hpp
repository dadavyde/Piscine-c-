/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBoss.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:38:43 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/07 21:38:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EnemyBoss_HPP
# define EnemyBoss_HPP

#include "GameEntity.hpp"
#include "Bullet.hpp"
#include <ncurses.h>

class EnemyBoss : public GameEntity
{
	public:
		EnemyBoss(void);
		EnemyBoss(const int y, const int x, const int id);
		virtual ~EnemyBoss(void);
		EnemyBoss(EnemyBoss const & obj);
		EnemyBoss & operator=(EnemyBoss const & obj);

};

#endif
