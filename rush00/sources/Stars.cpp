/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:51:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/06 19:51:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Stars.hpp"

Stars::Stars()
{
	int  idx;
	int  idx2;

	_stars = new bool* [90];
	for(int i = 0; i < 90; i++)
	{
		_stars[i] = new bool [370];
		idx = rand() % 15;
		if (idx)
		{
			for(int j = 0; j < 370; j++)
			{
				idx2 = rand() % 45;
				_stars[i][j] = !idx2;
			}
		}
	}
}

Stars::~Stars(void)
{
	for(int i = 0; i < 90; i++)
	{
		delete [] _stars[i];
	}
	delete [] _stars;
}

Stars::Stars(Stars const & obj)
{
	_stars = new bool* [90];
	for(int i = 0; i < 90; i++)
	{
		_stars[i] = new bool [370];
		for(int j = 0; j < 370; j++)
		{
			_stars[i][j] = obj._stars[i][j];
		}
	}
}

Stars &	Stars::operator=(Stars const & obj) {

	if (this != &obj) {
		*this = obj;
	}
	return *this;
}


void		Stars::drawStars(int win_y, int win_x, WINDOW *win, int star_deley) {

	//mvwprintw(win, 5, 5, "*");
	for(int y = 0; y < 90; y++)
		_stars[y][369] = _stars[y][0];
	werase(win);
	werase(win);
	for(int x = 1; x < 370; x++)
	{
		for(int y = 1; y < 90; y++)
		{

			if (_stars[y][x] && y < win_y - 2 && x < win_x)
				mvwprintw(win, y, x, ".");

			if (!(star_deley % 2))
				_stars[y][x - 1] = _stars[y][x];
		}
	}
	//wrefresh(win);
}