/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameZone.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:44:41 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 13:44:42 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameZone.hpp"
#include <sys/time.h>
#include <sstream>
#include <iomanip>

GameZone::GameZone(void) : _width(), _height(), _key(), _stars() {

	_win = initscr();
	cbreak();
	noecho();
	curs_set(0);
	timeout(0);
	_stx = 0;
	_sty = 0;
	_god = false;
	_pause = false;
	resizeWindow();
	keypad(_win, TRUE);
	srand(time(NULL));
	set_start_time();
	_delay = 1;
	start_color();
	for (int i = 0; i < NUM_ENEMIES; ++i) {
		_Entities[i] = NULL;
	}
	for (int i = 0; i < 320; ++i) {
		_bullets[i] = NULL;
	}
	init_colors();
	init_pairs();
	_usleep = 25000;
	return ;
}

GameZone::GameZone(GameZone const & obj) {

	if (this != &obj) {
		*this = obj;
	}
	return ;
}

GameZone::~GameZone(void) {

	delwin(_win);
	endwin();
	for (int i = 0; i < 320; ++i) {
		if (_bullets[i] != NULL)
			delete _bullets[i];
	}
	for (int i = 0; i < NUM_ENEMIES; ++i) {
		if (_Entities[i] != NULL)
			delete _Entities[i];
	}
	return ;
}

GameZone & GameZone::operator=(GameZone const & obj) {

	_win = obj._win;
	_width = obj._width;
	_height = obj._height;
	_sty = obj._sty;
	_stx = obj._stx;
	_key = obj._key;
	_start_time = obj._start_time;
	return *this;
}

WINDOW	* GameZone::getWindow(void) {

	return _win;
}

void	GameZone::resizeWindow(void) {

	getmaxyx(_win, _height, _width);
	wresize(_win, _height, _width);
	if (_height < 40 || _width < 88) {
		delwin(_win);
		endwin();
		std::cout << "Error: window is to small!" << std::endl;
		system("pkill afplay &");
		exit(1);
	}
	box(_win, 0, 0);
	return ;
}

int		GameZone::getWidth(void) {

	return _width;
}

int		GameZone::getHeight(void) {

	return _height;
}

void GameZone::set_start_time()
{
	std::time_t		t = std::time(0);
	_start_time = *std::localtime(&t);
}

void  GameZone::set_panel(GameEntity **Players, int level, int score)
{
	std::string  space(_width, ' ');

	attron(COLOR_PAIR(1));
	mvwprintw(_win, _height - 2, 0, space.data());
	set_panel_time();
	set_panel_level_score_hp(Players, level, score);
	attroff(COLOR_PAIR(1));
}

void GameZone::set_panel_time()
{
	std::time_t		t = std::time(0);
	std::tm*		now = std::localtime(&t);
	std::string		time_line("Time: 00:00:00");

	now->tm_sec -= _start_time.tm_sec;
	if (now->tm_sec < 0)
	{
		now->tm_sec += 60;
		now->tm_min--;
	}
	now->tm_min -= _start_time.tm_min;
	if (now->tm_min < 0)
	{
		now->tm_min += 60;
		now->tm_hour--;
	}
	now->tm_hour -= _start_time.tm_hour;
	time_line[6] = (char)('0' + now->tm_hour / 10);
	time_line[7] = (char)('0' + now->tm_hour % 10);
	time_line[9] = (char)('0' + now->tm_min / 10);
	time_line[10] = (char)('0' + now->tm_min % 10);
	time_line[12] = (char)('0' + now->tm_sec / 10);
	time_line[13] = (char)('0' + now->tm_sec % 10);
	mvwprintw(_win, _height - 2, 4, time_line.data());
}

void GameZone::set_panel_level_score_hp(GameEntity **Player, int level, int score)
{
	std::ostringstream		vStream;
	int 			x;

	vStream << "Level: " << level;
	mvwprintw(_win, _height - 2, 22, vStream.str().data());
	vStream.str("");
	vStream << "Score: " << score;
	mvwprintw(_win, _height - 2, _width - 54, vStream.str().data());
	vStream.str("");
	x = _width - 40;//TODO
	for (int i = 0; i < 2; i++)
	{

		if (Player[i])
		{
			if (Player[i]->get_hp() < 35)
				attron(COLOR_PAIR(6));
			vStream << "HP Player " << i << ": " << Player[i]->get_hp();
			mvwprintw(_win, _height - 2, x, vStream.str().data());
			vStream.str("");
			x += 20;//TODO
			if (Player[i]->get_hp() < 35)
			{
				attroff(COLOR_PAIR(6));
				attron(COLOR_PAIR(1));
			}
		}
	}

}

void	GameZone::player1_action(void) {

	switch (_key)
	{
		case KEY_LEFT:
			_Entities[0]->moveLeft(1);
			break ;
		case 10:
			shout(_Entities[0], 0, 1);
			break ;
		case KEY_RIGHT:
			_Entities[0]->moveRight(_width);
			break ;
		case KEY_UP:
			_Entities[0]->moveUp(1);
			break ;
		case KEY_DOWN:
			_Entities[0]->moveDown(_height - 1);
			break ;
		default :
			break ;
	}
}

void	GameZone::player2_action(void) {

	switch (_key)
	{	
		case 97:
			_Entities[1]->moveLeft(1);
			break ;
		case 32:
			shout(_Entities[1], 0, 1);
			break ;
		case 100:
			_Entities[1]->moveRight(_width);
			break ;
		case 119:
			_Entities[1]->moveUp(1);
			break ;
		case 115:
			_Entities[1]->moveDown(_height - 1);
			break ;
		default :
			break ;
	}
}

void	GameZone::fillThePowerOfGod(int power) {

	if (_Entities[0])
	{
		_Entities[0]->set_hp(100 * power);
		_Entities[0]->setDamage(10 * power);
		if (power == 1) {
			_Entities[0]->setFormBullet('=');
		} else {
			_Entities[0]->setFormBullet('$');
		}
	}
	if (_Entities[1])
	{
		_Entities[1]->set_hp(100 * power);
		_Entities[1]->setDamage(10 * power);
		if (power == 1) {
			_Entities[1]->setFormBullet('=');
		} else {
			_Entities[1]->setFormBullet('$');
		}
	}
	return ;
}

void	GameZone::cheatingIsSlavery(void) {

	static	int cheat = 0;

	switch (_key)
	{	
		case 117:
			if (cheat == 0)
				++cheat;
			else
				cheat = 0;
			break ;
		case 110:
			if (cheat == 1)
				++cheat;
			else
				cheat = 0;
			break ;
		case 105:
			if (cheat == 2)
				++cheat;
			else
				cheat = 0;
			break ;
		case 116:
			if (cheat == 3)
				++cheat;
			else
				cheat = 0;
			break ;
		default :
			cheat = 0;
			break ;
	}
	if (cheat == 4) {
		if (_god) {
			_god = false;
			fillThePowerOfGod(1);
		}
		else {
			fillThePowerOfGod(10000000);
			_god = true;
		}
		cheat = 0;
	}
	return ;
}

void	GameZone::Boss(void) {

	// static int x = 0;
	static int y = 0;

	if (_Entities[_bossFight] != NULL)
	{
		if (y < 10) {
			_Entities[_bossFight]->moveUp(0);
			y++;
		} else if (y >= 10 && y <= 20){
			_Entities[_bossFight]->moveDown(_height - 10);
			y++;
		} else {
			y = 0;
		}
		if (rand() % 17 == 0) {
			shout(_Entities[_bossFight], 0, -2);
			shout(_Entities[_bossFight], 1, -4);
			shout(_Entities[_bossFight], -1, -4);
		}
	}
	if (_Entities[_bossFight]) {
		if (_Entities[0] && !(_Entities[_bossFight]->getCoordX() + _Entities[_bossFight]->getWidth() < _Entities[0]->getCoordX() ||
			_Entities[_bossFight]->getCoordX() > _Entities[0]->getCoordX() + _Entities[0]->getWidth() ||
			_Entities[_bossFight]->getCoordY() + _Entities[_bossFight]->getHeight() < _Entities[0]->getCoordY() ||
			_Entities[_bossFight]->getCoordY() > _Entities[0]->getCoordY() + _Entities[0]->getHeight()))
		{
			if (!_god) {
				delete _Entities[0];
				_Entities[0] = NULL;
			}
			delete _Entities[_bossFight];
			_Entities[_bossFight] = NULL;
			_winner = true;
		}
		else if (_multiPlayer) {
			if (_Entities[1] && !(_Entities[_bossFight]->getCoordX() + _Entities[_bossFight]->getWidth() < _Entities[1]->getCoordX() ||
				_Entities[_bossFight]->getCoordX() > _Entities[1]->getCoordX() + _Entities[1]->getWidth() ||
				_Entities[_bossFight]->getCoordY() + _Entities[_bossFight]->getHeight() < _Entities[1]->getCoordY() ||
				_Entities[_bossFight]->getCoordY() > _Entities[1]->getCoordY() + _Entities[1]->getHeight()))
			{
				if (!_god) {
					delete _Entities[1];
					_Entities[1] = NULL;
				}
				delete _Entities[_bossFight];
				_Entities[_bossFight] = NULL;
				_winner = true;
			}
		}
	}
	return ;
}

void	GameZone::game(void) {

	while (42) {

		_key = wgetch(_win);
		if (((_key >= 258 && _key <= 261) || _key == 10) && _Entities[0]) {
			player1_action();
		}
		else if (_Entities[1] && (_key == 32 || _key == 97 || _key == 119 || _key == 115 || _key == 100)) {
			player2_action();
		}
		else
			switch (_key) {
				case 27:
					if (_Entities[0] || _Entities[1]) {
						_pause = true;
					}
					return ;
				case KEY_RESIZE:
					resizeWindow();
					break ;
				default :
					if (_key != ERR)
						cheatingIsSlavery();
					break ;
		}
		if (_delay % 15 == 0 && _numEnemy < _maxEnemy) {
			_numEnemy++;
			createEnemy();
		}
		_stars.drawStars(_height, _width, _win, stars_delay);
		set_panel(_Entities, _level, _score);
		drawEntities();
		if (_god) {
			mvwprintw(_win, 1, _width / 2, "CHEATING IS SLAVERY!");
		}
		box(_win, 0, 0);
		wrefresh(_win);
		stars_delay++;
		if (stars_delay > 1000)
			stars_delay = 0;
		if (_score > 200 && _score < 400)
			_usleep = 20000;
		if (_score > 400 && _score < 1000)
			_usleep = 15000;
		else if (_score > 1000)
			_usleep = 8000;
		usleep(_usleep);
		if (_numEnemy > 0 || _numEnemyElite > 0) {
			if (_bossFight) {
				Boss();
			} else {
				moveEnemy();
			}
		}
		if (_delay % 250 == 0 && _maxEnemy < 50)
			_maxEnemy++;
		_delay++;
		if (_delay % 50 == 0 && !_bossFight) {
			shoutEnemis();
		}
		if (_delay > 600)
			_delay = 0;
		if (!_Entities[0] && !_Entities[1]) {
			gameover();
			return ;
		}
		if (_winner) {
			wingame();
			return ;
		}
	}
}

void	GameZone::wingame(void) {

	wclear(_win);
	mvwprintw(_win, 15, _width / 2 - 25, " |\\  \\     |\\  \\ |\\  \\ |\\   ___  \\        |\\  \\");
	mvwprintw(_win, 16, _width / 2 - 25, " \\ \\  \\    \\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\       \\ \\  \\");
	mvwprintw(_win, 17, _width / 2 - 25, "  \\ \\  \\  __\\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\       \\ \\  \\");
	mvwprintw(_win, 18, _width / 2 - 25, "   \\ \\  \\|\\__\\_\\  \\\\ \\  \\\\ \\  \\\\ \\  \\       \\ \\__\\");
	mvwprintw(_win, 19, _width / 2 - 25, "    \\ \\____________\\\\ \\__\\\\ \\__\\\\ \\__\\       \\|__|");
	mvwprintw(_win, 20, _width / 2 - 25, "     \\|____________| \\|__| \\|__| \\|__|           ___ ");
	mvwprintw(_win, 21, _width / 2 - 25, "                                                |\\__\\ ");
	mvwprintw(_win, 22, _width / 2 - 25, "                                                \\|__| ");
	wrefresh(_win);
	usleep(1000000);
}

void	GameZone::gameover(void) {

	wclear(_win);
	mvwprintw(_win, 20, _width / 2 - 48, "	 ________  ________  _____ ______   _______           ________  ___      ___ _______   ________");
	mvwprintw(_win, 21, _width / 2 - 48, "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         |\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\  ");
	mvwprintw(_win, 22, _width / 2 - 48, "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\ ");
	mvwprintw(_win, 23, _width / 2 - 48, " \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__       \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\ ");
	mvwprintw(_win, 24, _width / 2 - 48, "  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\|");
	mvwprintw(_win, 25, _width / 2 - 48, "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\");
	mvwprintw(_win, 26, _width / 2 - 48, "    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|_______|\\|__|/       \\|_______|\\|__|\\|__|");
	wrefresh(_win);
	usleep(1000000);
}

void	GameZone::init_game(void) {

	for (int i = 0; i < NUM_ENEMIES; ++i) {
		if (_Entities[i] != NULL) {
			delete _Entities[i];
		}
		_Entities[i] = NULL;
	}
	for (int i = 0; i < 320; ++i) {
		if (_bullets[i] != NULL) {
			delete _bullets[i];
		}
		_bullets[i] = NULL;
	}
	_Entities[0] = new Player(_height / 4, 1, 0);
	if (_multiPlayer)
		_Entities[1] = new Player(_height / 2, 2, 1);
	else
		_Entities[1] = NULL;
	nodelay(_win, TRUE);
	_bossFight = 0;
	_score = 0;
	_numEnemy = 0;
	_maxEnemy = 1;
	_numEnemyElite = 0;
	_winner = false;
	_god = false;
	_level = 1;
	stars_delay = 0;
	set_start_time();
}

void	GameZone::drawMenu(int menukey) {

	attron(COLOR_PAIR(7));
	mvwprintw(_win, 5, _width / 2 - 50, " ___  ___      ________       ___      _________        ___   ___       _______");
	mvwprintw(_win, 6, _width / 2 - 50, "|\\  \\|\\  \\    |\\   ___  \\    |\\  \\    |\\___   ___\\     |\\  \\ |\\  \\     /  ___  \\");
	mvwprintw(_win, 7, _width / 2 - 50, "\\ \\  \\\\\\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\   \\|___ \\  \\_|     \\ \\  \\\\_\\  \\   /__/|_/  /|");
	mvwprintw(_win, 8, _width / 2 - 50, " \\ \\  \\\\\\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\       \\ \\  \\       \\ \\______  \\  |__|//  / /");
	mvwprintw(_win, 9, _width / 2 - 50, "  \\ \\  \\\\\\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\       \\ \\  \\       \\|_____|\\  \\     /  /_/__");
	mvwprintw(_win, 10, _width / 2 - 50, "   \\ \\_______\\   \\ \\__\\\\ \\__\\   \\ \\__\\       \\ \\__\\             \\ \\__\\   |\\________\\");
	mvwprintw(_win, 11, _width / 2 - 50, "    \\|_______|    \\|__| \\|__|    \\|__|        \\|__|              \\|__|    \\|_______|");

	mvwprintw(_win, 12, _width / 2 - 58, " ________  _________                   ________      _______       _________    ________      ________ ");
	mvwprintw(_win, 13, _width / 2 - 58, "|\\  _____\\|\\___   ___\\                |\\   __  \\    |\\  ___ \\     |\\___   ___\\ |\\   __  \\    |\\   __  \\");
	mvwprintw(_win, 14, _width / 2 - 58, "\\ \\  \\__/ \\|___ \\  \\_|  ____________  \\ \\  \\|\\  \\   \\ \\   __/|    \\|___ \\  \\_| \\ \\  \\|\\  \\   \\ \\  \\|\\  \\");
	mvwprintw(_win, 15, _width / 2 - 58, " \\ \\   __\\     \\ \\  \\  |\\____________\\ \\ \\   _  _\\   \\ \\  \\_|/__       \\ \\  \\   \\ \\   _  _\\   \\ \\  \\\\\\  \\");
	mvwprintw(_win, 16, _width / 2 - 58, "  \\ \\  \\_|      \\ \\  \\ \\|____________|  \\ \\  \\\\  \\|   \\ \\  \\_|\\ \\       \\ \\  \\   \\ \\  \\\\  \\|   \\ \\  \\\\\\  \\");
	mvwprintw(_win, 17, _width / 2 - 58, "   \\ \\__\\        \\ \\__\\                  \\ \\__\\\\ _\\    \\ \\_______\\       \\ \\__\\   \\ \\__\\\\ _\\    \\ \\_______\\");
	mvwprintw(_win, 18, _width / 2 - 58, "    \\|__|         \\|__|                   \\|__|\\|__|    \\|_______|        \\|__|    \\|__|\\|__|    \\|_______|");
	attroff(COLOR_PAIR(7));

	attron(COLOR_PAIR(8));
    if (_pause && menukey == 0)
        mvwprintw(_win, _height / 2 - 2, _width / 2 - 5, ">Contiune<");
    else if (menukey == 1)
        mvwprintw(_win, _height / 2 - 1, _width / 2 - 5, ">New Game<");
    else if (menukey == 2)
        mvwprintw(_win, _height / 2, _width / 2 - 6, ">Multiplayer<");
    else if (menukey == 3)
        mvwprintw(_win, _height / 2 + 1, _width / 2 - 3, ">QUIT<");
    attroff(COLOR_PAIR(8));
    attron(COLOR_PAIR(9));
    if (_pause && menukey != 0)
        mvwprintw(_win, _height / 2 - 2, _width / 2 - 5, " Contiune");
    if (menukey != 1)
        mvwprintw(_win, _height / 2 - 1, _width / 2 - 5, " New Game");
    if (menukey != 2)
        mvwprintw(_win, _height / 2, _width / 2 - 6, " Multiplayer");
    if (menukey != 3)
        mvwprintw(_win, _height / 2 + 1, _width / 2 - 3, " QUIT");
    attroff(COLOR_PAIR(9));
}

void	GameZone::play(void) {

	int		menukey = 1;

	nodelay(_win, FALSE);
	while (42) {

		wclear(_win);
		drawMenu(menukey);
		box(_win, 0, 0);
		wrefresh(_win);
		_key = wgetch(_win);
		if (menukey == 0 && _key == 10) {
			_pause = false;
			nodelay(_win, TRUE);
			game();
			nodelay(_win, FALSE);
		}
		if (menukey == 1 && _key == 10) {
			_multiPlayer = false;
			init_game();
			game();
			nodelay(_win, FALSE);
		}
		else if (menukey == 2 && _key == 10) {
			_multiPlayer = true;
			init_game();
			game();
			nodelay(_win, FALSE);
		}
		else if (menukey == 3 && _key == 10) {
			return ;
		}
		switch (_key) {
			case KEY_UP:
				menukey--;
				break ;
			case KEY_DOWN:
				menukey++;
				break ;
			case KEY_RESIZE:
				resizeWindow();
				break ;
			default:
				break;
		}
		if (menukey > 3) {
			if (_pause) {
				menukey = 0;
			} else {
				menukey = 1;
			}
		}
		else if (menukey < 0 || (!_pause && menukey < 1)) {
			menukey = 3;
		}
	}
	return ;
}

void		GameZone::shoutEnemis(void) {

	for (int i = 2; i < NUM_ENEMIES; ++i) {
		if (_Entities[i] != NULL) {
			if (rand() % 2) {
				shout(_Entities[i], 0, -1);
			}
		}
	}
}

void		GameZone::moveEnemy(void) {

	for (int i = 2; i < NUM_ENEMIES; ++i) 
	{
		if (_Entities[i] != NULL)
		{
			if (_delay % 2)
				_Entities[i]->moveLeft(0);
			if (_Entities[0] && !(_Entities[i]->getCoordX() + _Entities[i]->getWidth() < _Entities[0]->getCoordX() ||
				_Entities[i]->getCoordX() > _Entities[0]->getCoordX() + _Entities[0]->getWidth() ||
				_Entities[i]->getCoordY() + _Entities[i]->getHeight() < _Entities[0]->getCoordY() ||
				_Entities[i]->getCoordY() > _Entities[0]->getCoordY() + _Entities[0]->getHeight()))
			{
				if (!_god) {
					delete _Entities[0];
					_Entities[0] = NULL;
				}
				delete _Entities[i];
				_Entities[i] = NULL;
			}
			else if (_multiPlayer) {
				if (_Entities[1] && !(_Entities[i]->getCoordX() + _Entities[i]->getWidth() < _Entities[1]->getCoordX() ||
					_Entities[i]->getCoordX() > _Entities[1]->getCoordX() + _Entities[1]->getWidth() ||
					_Entities[i]->getCoordY() + _Entities[i]->getHeight() < _Entities[1]->getCoordY() ||
					_Entities[i]->getCoordY() > _Entities[1]->getCoordY() + _Entities[1]->getHeight()))
				{
					if (!_god) {
						delete _Entities[1];
						_Entities[1] = NULL;
					}
					delete _Entities[i];
					_Entities[i] = NULL;
				}
			}
		}
	}
	return ;
}

void		GameZone::createEnemy(void) {

	int	y = rand() % _height;

	y = y / 3 * 3;
	if (y >= _height - 10)
		y -= 10;
	else if (y <= 10)
		y += 10;
	for (int i = 2; i < NUM_ENEMIES; ++i) {
		if (_Entities[i] == NULL) {
			if (_score > 400 && _score < 1000 && _numEnemyElite < 4 && rand() % 2) { // TODO add lvl
				_Entities[i] = new EnemyElite(y, _width - 11, 3);
				++_numEnemyElite;
				if (_level == 1)
					_level = 2;
			}
			else if (_score >= 1000)
			{
				if (_bossFight) {
					return ;
				}
				if (_numEnemyElite)
					return ;
				_Entities[i] = new EnemyBoss(_height / 2, _width - 59, 4);
				_bossFight = i;
				if (_level == 2)
					_level = 3;
			}
			else if (_score < 1000)
				_Entities[i] = new Enemy(y, _width - 8, 2);
			return ;
		}
	}
	return ;
}

void		GameZone::drawEntities(void) {

	int	y;
	int	x;
	int i;

	attron(COLOR_PAIR(5));
	for (int p = 0; p < 2; ++p)
	{
		if (_Entities[p]) {

			y = _Entities[p]->getCoordY();
			x = _Entities[p]->getCoordX();
			for (i = 0; i < _Entities[p]->getHeight(); ++i, ++y)
			{
				mvwprintw(_win, y, x, "%s", (_Entities[p]->getForm(i)).c_str());
			}
		}
	}
	attroff(COLOR_PAIR(5));
	attron(COLOR_PAIR(3));
	for (int e = 2; e < 50; ++e)
	{
		if (_Entities[e]) {
			y = _Entities[e]->getCoordY();
			x = _Entities[e]->getCoordX();
			if (x == 1) {
				if (_Entities[e]->getId() == 3) {
					_numEnemyElite--; 
				}
				delete _Entities[e];
				_Entities[e] = NULL;
				_score -= 10;
				_numEnemy--;
			}
			else {
				for (i = 0; i < _Entities[e]->getHeight(); ++i, ++y) {
					mvwprintw(_win, y, x, "%s", (_Entities[e]->getForm(i)).c_str());
				}
			}
		}
	}

	attroff(COLOR_PAIR(3));
	int kill;
	attron(COLOR_PAIR(4));
	for (i = 0; i < 320; ++i)
	{
		if (_bullets[i] != NULL)
		{
			x = _bullets[i]->getCoordX();
			y = _bullets[i]->getCoordY();
			if (x == 1 || x >= _width) 
			{
				delete _bullets[i];
				_bullets[i] = NULL;
			}
			else
			{
				mvwprintw(_win, y, x, "%c", _bullets[i]->getForm());
				_bullets[i]->move();
				kill = _bullets[i]->colision(_Entities, _god);
				if (kill >= 0) {
					delete _bullets[i];
					_bullets[i] = NULL;
					if (kill == 2) {
						_numEnemy--;
						_score += 20;
					}
					else if (kill == 3) {
						_numEnemyElite--;
						_score += 40;
					}
					else if (kill == 4) {
						_winner = true;
					}
					else
						_score += 5;
				}
			}
		}
	}
	attroff(COLOR_PAIR(4));

	return ;
}

void		GameZone::shout(GameEntity *who, int const dirY, int const dirX) {

	for (int i = 0; i < 320; ++i) {
		if (_bullets[i] == NULL) {
			system("afplay music/hit.mp3 &");
			_bullets[i] = new Bullet(who->getShoutPosY() + who->getCoordY() + dirY, who->getShoutPosX() + who->getCoordX() + dirX, dirY, dirX, who->getDamage(), who->getFormBullet());
			return ;
		}
	}
	return ;
}

void GameZone::init_colors()
{
	init_color(102, 900, 100, 100);
	init_color(103, 500, 700, 500);
	init_color(104, 500, 100, 500);
	init_color(105, 900, 500, 500);
	init_color(106, 500, 500, 800);
	init_color(107, 500, 300, 500);
	init_color(108, 500, 500, 500);
	init_color(109, 100, 100, 500);
	init_color(110, 500, 500, 500);
	init_color(111, 100, 300, 500);
}

void GameZone::init_pairs()
{
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_WHITE);
	init_pair(7, 105, COLOR_BLACK);
	init_pair(8, 106, COLOR_BLACK);
	init_pair(9, 107, COLOR_BLACK);
	init_pair(10, 108, COLOR_WHITE);
	init_pair(12, 109, COLOR_WHITE);
	init_pair(13, 110, COLOR_WHITE);
	init_pair(14, 111, COLOR_WHITE);
}
