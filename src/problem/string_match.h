/*****************************************************************************
 *   Copyright (C) 2004-2009 The PaGMO development team,                     *
 *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
 *   http://apps.sourceforge.net/mediawiki/pagmo                             *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Developers  *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Credits     *
 *   act@esa.int                                                             *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************/

#ifndef PAGMO_PROBLEM_STRING_MATCH_H
#define PAGMO_PROBLEM_STRING_MATCH_H

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <string>

#include "../config.h"
#include "../types.h"
#include "base.h"

namespace pagmo { namespace problem {

/// String matching problem.
/**
 * This problem is initialised by providing a string of arbitrary (non-null) size n, and it defines an n-dimensional single-objective integer optimisation problem
 * in which each variable is a character in a string of length n and the objective function is given by the sum of the distances of each character in the chromosome
 * from the corresponding correct letter in the original string.
 *
 * In other words, in a chromosome with fitness 0 the value of each variable is the ASCII code of the corresponding letter in the original string.
 *
 * @author Francesco Biscani (bluescarni@gmail.com)
 */
class __PAGMO_VISIBLE string_match: public base
{
	public:
		string_match(const std::string &);
		string_match(const char *);
		base_ptr clone() const;
		std::string get_name() const;
	protected:
		void objfun_impl(fitness_vector &, const decision_vector &) const;
		std::string human_readable_extra() const;
	private:
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int /*version*/){
			ar & boost::serialization::base_object<base>(*this);
			ar & const_cast<std::string &>(m_str);
		}
	public:
		const std::string m_str;
};

template<class Archive>
inline void save_construct_data( Archive & ar, const string_match *t, const unsigned int /*file_version*/) {
    // save data required to construct instance
	std::string str;
	str = t->m_str;
    ar << str;
}

template<class Archive>
inline void load_construct_data( Archive & ar, string_match *t, const unsigned int /*file_version*/) {
    // retrieve data from archive required to construct new instance
    std::string str;
    ar >> str;
    // invoke inplace constructor to initialize instance of my_class
    ::new(t)string_match(str);
}

} }

#endif
