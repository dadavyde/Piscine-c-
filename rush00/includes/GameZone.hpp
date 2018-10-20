/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameZone.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:44:47 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 13:44:47 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEZONE_HPP
# define GAMEZONE_HPP

# include <ncurses.h>
# include <iostream>
# include "Enemy.hpp"
# include "GameEntity.hpp"
# include "Player.hpp"
# include <ncurses.h>
# include <unistd.h>
# include <ctime>
# include <sstream>
# include <iomanip>
# include "Stars.hpp"
# include "EnemyBoss.hpp"
# include "EnemyElite.hpp"

# define NUM_ENEMIES 70

class	GameZone {

	public:
		GameZone(void);
		GameZone(GameZone const & obj);
		virtual ~GameZone(void);
		GameZone & operator=(GameZone const & obj);

		WINDOW	*getWindow(void);

		void	resizeWindow(void);

		int		getWidth(void);
		int		getHeight(void);

		void	play(void);

	private:
		GameEntity		*_Entities[NUM_ENEMIES];
		Bullet			*_bullets[320];
		WINDOW			*_win;
		int				_numEnemy;
		int				_numEnemyElite;
		int				_width;
		int				_height;
		int				_stx;
		int				_sty;
		int				_key;
		unsigned int	_delay;
		std::tm			_start_time;
		Stars			_stars;
		int				_score;
		int				_maxEnemy;
		bool			_multiPlayer;
		bool			_god;
		bool			_pause;
		int				_bossFight;
		bool			_winner;
		int				_level;
		int				stars_delay;

		int 			_usleep;

		void	drawEntities(void);

		void	createEnemy(void);
		void	moveEnemy(void);

		void	shout(GameEntity *who, int dirx, int diry);

		void	set_panel(GameEntity **Players, int _level, int _score);
		void	set_panel_time();
		void	set_panel_level_score_hp(GameEntity **Players, int level, int score);
		void	set_start_time();

		int		colision(GameEntity *element);

		void	shoutEnemis(void);

		void	player1_action(void);
		void	player2_action(void);

		void	cheatingIsSlavery(void);
		void	fillThePowerOfGod(int power);

		void	game(void);

		void	init_game(void);

		void	drawMenu(int menukey);

		void	Boss(void);

		void	gameover(void);

		void 	wingame(void);

		void	init_colors();
		void	init_pairs();

};

#endif
