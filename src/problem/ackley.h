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

#ifndef PAGMO_PROBLEM_ACKLEY_H
#define PAGMO_PROBLEM_ACKLEY_H

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/version.hpp>
#include <string>

#include "../types.h"
#include "base.h"

namespace pagmo{ namespace problem {

/// The Ackley problem.
/**
 * \image html ackley.gif "Two-dimensional Ackley function."
 * \image latex ackley.png "Two-dimensional Ackley function." width=5cm
 *
 * This is a box-constrained continuous single-objecive problem.
 * The objective function is the n-dimensional Ackley function:
 * \f[
 * 	F\left(x_1,\ldots,x_n\right) = 20 + e - 20e^{-\frac 15 \sqrt{\frac 1n \sum_{i=1}^n x_i^2}} - e^{\frac 1n \sum_{i=1}^n \cos(2\pi x_i)}, \quad x_i \in \left[ -15,30 \right].
 * \f]
 * The global minimum is in \f$x_i=0\f$, where \f$ F\left( 0,\ldots,0 \right) = 0 \f$.
 *
 * @author Dario Izzo (dario.izzo@esa.int)
 */

class __PAGMO_VISIBLE ackley : public base
{
	public:
		ackley(int);
		base_ptr clone() const;
		std::string get_name() const;
	protected:
		void objfun_impl(fitness_vector &, const decision_vector &) const;
	private:
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int /*version*/){
			ar & boost::serialization::base_object<base>(*this);
		}
};

template<class Archive>
inline void save_construct_data( Archive & ar, const ackley *t, const unsigned int /*file_version*/) {
    // save data required to construct instance
	int n;
	n = t->get_dimension();
    ar << n;
}

template<class Archive>
inline void load_construct_data( Archive & ar, ackley *t, const unsigned int /*file_version*/) {
    // retrieve data from archive required to construct new instance
    int n;
    ar >> n;
    // invoke inplace constructor to initialize instance of my_class
    ::new(t)ackley(n);
}

}} //namespaces

#endif // SCHWEFEL_H
