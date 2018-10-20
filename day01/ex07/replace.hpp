/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:11:25 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:11:26 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H

#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

void    replace(std::string filename, std::string &s1, std::string &s2);

#endif
