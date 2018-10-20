/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:30:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 16:30:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

Cast::Cast() : type_(-1), d_num_(0), f_num_(0), i_num_(0), c_num_(0)
{}

Cast::~Cast()
{}

Cast& Cast::operator=(const Cast &other)
{
	this->type_ = other.type_;
	this->d_num_ = other.d_num_;
	this->f_num_ = other.f_num_;
	this->i_num_ = other.i_num_;
	this->c_num_ = other.c_num_;
	return (*this);
}
Cast::Cast(const Cast &other)
{
	*this = other;
}

int  Cast::check_type(std::string literal)
{
	unsigned long  max_idx;

	max_idx = literal.size() - 1;
	if (max_idx == 0 && !isdigit(literal[0]))
		return (CHAR);
	if (literal[max_idx] == 'f' && isdigit(literal[max_idx - 1]))
		return (FLOAT);
	for (unsigned long i = 0; i <= max_idx; i++)
	{
		if (literal[i] == '.')
			return (DOUBLE);
	}
	for (unsigned long i = 0; i <= max_idx; i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (!isdigit(literal[i]))
			return (SPECIAL);
	}
	long int long_num;

	if (literal.size() > 10)
		return (SPECIAL);
	long_num = strtol(literal.data(), NULL, 10);
	if (long_num > static_cast<long int>(INT_MAX) || long_num < static_cast<long int>(INT_MIN))
		return (SPECIAL);
	return (INT);
}

void Cast::find_basis_number(std::string literal)
{
	if (type_ == CHAR)
	{
		c_num_ = literal[0];
	}
	else if (type_ == DOUBLE)
	{
		d_num_ = (strtod(literal.data(), NULL));
	}
	else if (type_ == INT)
	{
		i_num_ = static_cast<int>(strtol(literal.data(), NULL, 10));
	}
	else if (type_ == FLOAT)
	{
		f_num_ = static_cast<float>(strtod(literal.data(), NULL));
	}
}

void Cast::cast_literal(std::string literal)
{
	type_ = check_type(literal);
	find_basis_number(literal);
	casting_to_double(literal);
	casting_to_float(literal);
	try
	{
		casting_to_int(literal);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		casting_to_char(literal);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int  Cast::casting_to_double(std::string literal)
{
	std::cout << "Double: ";
	if (type_ == DOUBLE)
	{
		std::cout << d_num_ << std::endl;
	}
	else if (type_ == CHAR)
		std::cout << static_cast<double>(c_num_) << std::endl;
	else if (type_ == INT)
		std::cout << static_cast<double>(i_num_) << std::endl;
	else if (type_ == FLOAT)
		std::cout << static_cast<double>(f_num_) << std::endl;
	else if (type_ == SPECIAL)
	{
		if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
			std::cout << std::numeric_limits<double>::infinity() << std::endl;
		else if (literal == "-inf" || literal == "-inff")
			std::cout << -std::numeric_limits<double>::infinity() << std::endl;
		else if (literal == "nan" || literal == "nanf")
			std::cout << "nan" << std::endl;
	}
	return 0;
}

int  Cast::casting_to_float(std::string literal)
{
	std::cout << "Float: ";
	if (type_ == FLOAT)
	{
		std::cout << f_num_ << std::endl;
	}
	else if (type_ == DOUBLE)
	{
		if (d_num_ > 0 && d_num_ > static_cast<double>(FLT_MAX))
			std::cout << "inff" << std::endl;
		else if (d_num_ < 0 && d_num_ < static_cast<double>(-FLT_MAX))
			std::cout << "-inff" << std::endl;
		else
			std::cout << static_cast<float>(d_num_) << std::endl;
	}
	else if (type_ == INT)
	{
		std::cout << static_cast<float>(i_num_) << std::endl;
	}
	else if (type_ == CHAR)
	{
		std::cout << static_cast<float>(c_num_) << std::endl;
	}
	else if (type_ == SPECIAL)
	{
		if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
			std::cout << "inff" << std::endl;
		else if (literal == "-inf" || literal == "-inff")
			std::cout << "-inff" << std::endl;
		else if (literal == "nan" || literal == "nanf")
			std::cout << "nanf" << std::endl;
	}
	return 0;
}

int  Cast::casting_to_int(std::string literal)
{
	std::cout << "Int: ";
	if (type_ == INT)
	{
		std::cout << i_num_ << std::endl;
	}
	else if (type_ == DOUBLE)
	{
		if (d_num_ > static_cast<double>(INT_MAX) || d_num_ < static_cast<double>(INT_MIN))
			throw NonPossibleNum();
		std::cout << static_cast<int>(d_num_) << std::endl;
	}
	else if (type_ == FLOAT)
	{
		std::cout << static_cast<int>(f_num_) << std::endl;
	}
	else if (type_ == CHAR)
	{
		std::cout << static_cast<int>(c_num_) << std::endl;
	}
	else if (type_ == SPECIAL)
		throw NonPossibleNum();
	(void)literal;
	return 0;
}

int  Cast::casting_to_char(std::string literal)
{
	std::cout << "Char: ";
	if (type_ == CHAR)
	{
		if (!isprint(c_num_))
			throw NonPrintableChar();
		std::cout << c_num_ << std::endl;
	}
	else if (type_ == DOUBLE)
	{
		if (d_num_ > static_cast<double>(CHAR_MAX) || d_num_ < static_cast<double>(CHAR_MIN))
			throw NonPossibleNum();
		else if (!isprint(static_cast<int>(d_num_)))
			throw NonPrintableChar();
		std::cout << static_cast<char >(d_num_) << std::endl;
	}
	else if (type_ == FLOAT)
	{
		if (f_num_ > static_cast<float>(CHAR_MAX) || f_num_ < static_cast<float>(CHAR_MIN))
			throw NonPossibleNum();
		else if (!isprint(static_cast<int>(f_num_)))
			throw NonPrintableChar();
		std::cout << static_cast<char>(f_num_) << std::endl;
	}
	else if (type_ == INT)
	{
		if (i_num_ > CHAR_MAX || i_num_ < CHAR_MIN)
			throw NonPossibleNum();
		else if (!isprint(i_num_))
			throw NonPrintableChar();
		std::cout << static_cast<char>(i_num_) << std::endl;
	}
	else if (type_ == SPECIAL)
		throw NonPossibleNum();
	(void)literal;
	return 0;
}

Cast::NonPrintableChar::NonPrintableChar()
{}

Cast::NonPrintableChar::~NonPrintableChar() throw()
{}

Cast::NonPrintableChar::NonPrintableChar(const Cast::NonPrintableChar &other) throw()
{(void)other;}

Cast::NonPrintableChar& Cast::NonPrintableChar::operator=(const Cast::NonPrintableChar &other)
{
	(void)other;
	return *this;
}

const char* Cast::NonPrintableChar::what() const throw()
{
	return "Non displayable.";
}


Cast::NonPossibleNum::NonPossibleNum()
{}

Cast::NonPossibleNum::~NonPossibleNum() throw()
{}

Cast::NonPossibleNum::NonPossibleNum(const Cast::NonPossibleNum &other) throw()
{(void)other;}

Cast::NonPossibleNum& Cast::NonPossibleNum::operator=(const Cast::NonPossibleNum &other)
{
	(void)other;
	return *this;
}

const char* Cast::NonPossibleNum::what() const throw()
{
	return "impossible";
}
