/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:11:17 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:11:19 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void    replace(std::string filename, std::string &s1, std::string &s2)
{
    std::ifstream       file_stream(filename.data());
    std::stringstream   buffer;
    std::string         out_file;
    size_t              position = 0;

    if (!file_stream.is_open())
        return;

    buffer << file_stream.rdbuf();
    out_file = buffer.str();
    position = out_file.find(s1);
    while (position != std::string::npos)
    {
        out_file.replace(position, s1.size(), s2);
        position = out_file.find(s1);
    }

    std::string new_name;
    new_name = filename + std::string(".replace");

    std::ofstream out(new_name.data());
    if (!out.is_open())
        return;
    out << out_file;
    out.close();
}
