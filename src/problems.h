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

#ifndef PAGMO_PROBLEMS_H
#define PAGMO_PROBLEMS_H

// Header including all problems implemented in PaGMO.

#include "problem/base.h"
#include "problem/branin.h"
#include "problem/golomb_ruler.h"
#include "problem/himmelblau.h"
#include "problem/knapsack.h"
#include "problem/nsga_ii_fon.h"
#include "problem/nsga_ii_sch.h"
#include "problem/paraboloid.h"
#include "problem/rastrigin.h"
#include "problem/rosenbrock.h"
#include "problem/schwefel.h"
#include "problem/griewank.h"
#include "problem/levy5.h"
#include "problem/lennard_jones.h"
#include "problem/ackley.h"
#include "problem/snopt_toyprob.h"
#include "problem/string_match.h"
#include "problem/string_match_mo.h"
#include "problem/luksan_vlcek_1.h"
#include "problem/luksan_vlcek_2.h"
#include "problem/luksan_vlcek_3.h"
#include "problem/cassini_1.h"
#include "problem/cassini_2.h"
#include "problem/gtoc_1.h"
#include "problem/gtoc_2.h"
#include "problem/inventory.h"
#include "problem/sagas.h"
#include "problem/rosetta.h"
#include "problem/messenger.h"
#include "problem/messenger_full.h"
#include "problem/tandem.h"
#include "problem/laplace.h"
#include "problem/sample_return.h"
#include "problem/earth_planet.h"

// routine that registers the derived types of the the problem class needed for casting after deserializing the base_ptr
#define REGISTER_PROBLEM_SERIALIZATIONS()                       \
ar.template register_type<problem::ackley>();					\
ar.template register_type<problem::branin>();					\
ar.template register_type<problem::cassini_2>();				\
ar.template register_type<problem::cassini_1>();				\
ar.template register_type<problem::griewank>();					\
ar.template register_type<problem::himmelblau>();				\
ar.template register_type<problem::inventory>();				\
ar.template register_type<problem::levy5>();					\
ar.template register_type<problem::messenger>();				\
ar.template register_type<problem::messenger_full>();			\
ar.template register_type<problem::nsga_ii_fon>();				\
ar.template register_type<problem::nsga_ii_sch>();				\
ar.template register_type<problem::luksan_vlcek_1>();			\
ar.template register_type<problem::luksan_vlcek_2>();			\
ar.template register_type<problem::luksan_vlcek_3>();			\
ar.template register_type<problem::paraboloid>();				\
ar.template register_type<problem::string_match>();				\
ar.template register_type<problem::string_match_mo>();			\
ar.template register_type<problem::rastrigin>();				\
ar.template register_type<problem::rosenbrock>();				\
ar.template register_type<problem::rosetta>();					\
ar.template register_type<problem::sagas>();					\
ar.template register_type<problem::schwefel>();					\
ar.template register_type<problem::snopt_toyprob>();			\
ar.template register_type<problem::tandem>();			

#endif
