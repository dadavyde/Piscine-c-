/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:11:06 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:11:08 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int    main()
{
    std::string s1("fuck");
    std::string s2("****");
    replace("./test01", s1, s2);

    s1 = "shit";
    s2 = "####";
    replace("./test01.replace", s1, s2);

    s1 = "Lorem Ipsum";
    s2 = "WWOOOOWW";
    replace("./test00", s1, s2);
    
    return (0);
}
