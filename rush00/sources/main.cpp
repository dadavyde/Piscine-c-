/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:29:52 by rnovodra          #+#    #+#             */
/*   Updated: 2018/10/06 13:29:52 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameZone.hpp"

int		main(void) {

	GameZone	game;

	system("afplay music/main.mp3 &");
	game.play();
	system("pkill afplay &");
	return 0;
}
