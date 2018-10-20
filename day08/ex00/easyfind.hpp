/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:04:54 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/13 17:04:55 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>

template <typename T>
size_t easyfind (T a, int b)
{
    typename T::iterator it;

    it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        return (-1);
    else
        return (it - a.begin());
}

#endif
