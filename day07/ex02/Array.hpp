/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:04:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/11 16:04:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
	Array<T>() : size_(0)
	{
		array_ = NULL;
	};
	Array<T>(unsigned int n) : size_(n)
	{
		array_ = new T [n]();
	};
	~Array<T>()
	{
		delete [] this->array_;
	}
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete [] this->array_;
			this->size_ = other.size_;
			this->array_ = new T [size_];
			for(unsigned int i = 0; i < size_; i++)
				this->array_[i] = other.array_[i];
		}
		return (*this);
	}
	Array(const Array &other) : array_(new T [other.size_]), size_(other.size_)
	{
		for(unsigned int i = 0; i < size_; i++)
			this->array_[i] = other.array_[i];
	}
	class InvalidIndex : public std::exception
	{
	public:
		InvalidIndex() {};
		~InvalidIndex() throw() {};
		InvalidIndex(const InvalidIndex &other) throw(){ (void)other; };
		InvalidIndex &operator=(const InvalidIndex &other) { (void)other; return *this;};
		virtual const char* what() const throw()
		{
			return ("Invalid index!");
		};
	};
	T &operator[](unsigned int i)
	{
		if (i >= size_)
			throw InvalidIndex();
		return (array_[i]);
	}
	unsigned int size() const
	{
		return size_;
	}

private:
	T *array_;
	unsigned int size_;
};


#endif