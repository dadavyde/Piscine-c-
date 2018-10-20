/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:51:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/06 19:51:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
#define STARS_HPP

#include "GameEntity.hpp"

class Stars : public GameEntity
{
public:
	Stars(void);
	//Stars(const int y, const int x, const int h, const int w);
	virtual ~Stars(void);
	Stars(Stars const & obj);
	Stars & operator=(Stars const & obj);
	void	drawStars(int win_y, int win_x, WINDOW *win, int star_deley);

private:
	bool		**_stars;


	//84x364(90x370)
};


#endif //CLION_RUSH00_STARS_HPP
