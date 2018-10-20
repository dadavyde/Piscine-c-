/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:30:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 16:30:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
#define CAST_HPP

#include <iostream>
#include <cctype>
#include <exception>
#include <string>
#include <limits>
#include <cfloat>
#include <cstdlib>

enum TYPE{CHAR, INT, FLOAT, DOUBLE, SPECIAL};


class Cast
{
public:
	Cast();
	~Cast();
	Cast &operator=(const Cast &other);
	Cast(const Cast &other);

	int   casting_to_char(std::string literal);
	int   casting_to_int(std::string literal);
	int   casting_to_double(std::string literal);
	int   casting_to_float(std::string literal);
	int  check_type(std::string literal);
	void  find_basis_number(std::string literal);
	void  cast_literal(std::string literal);
	//void  handle_special(std::string literal);

	class NonPrintableChar : public std::exception
	{
	public:
		NonPrintableChar();
		~NonPrintableChar() throw();
		NonPrintableChar(const NonPrintableChar &other) throw();
		NonPrintableChar &operator=(const NonPrintableChar &other);
		virtual const char* what() const throw();
	};

	class NonPossibleNum : public std::exception
	{
	public:
		NonPossibleNum();
		~NonPossibleNum() throw();
		NonPossibleNum(const NonPossibleNum &other) throw();
		NonPossibleNum &operator=(const NonPossibleNum &other);
		virtual const char* what() const throw();
	};
private:
	int  type_;
	double  d_num_;
	float  f_num_;
	int  i_num_;
	char  c_num_;
};

#endif
