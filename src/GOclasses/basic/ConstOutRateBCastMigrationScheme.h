/*****************************************************************************
 *   Copyright (C) 2008, 2009 Advanced Concepts Team (European Space Agency) *
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

// 09/03/2009: Initial version by Marek Rucinski.

#ifndef PAGMO_CONST_OUT_RATE_BCAST_MIGRATION_SCHEME_H
#define PAGMO_CONST_OUT_RATE_BCAST_MIGRATION_SCHEME_H

#include "MigrationScheme.h"
#include <boost/unordered_map.hpp>
#include <vector>
#include "../../Functions/rng/rng.h"

/// Migration scheme with constant outgoing migration rate and broadcast communication style.
/**
 * This is the migration model in which the migration is "destination driven". Moreover, migrating individuals
 * are multiplied and send to all neighbours of an island.
 */
class __PAGMO_VISIBLE ConstOutRateBCastMigrationScheme: public MigrationScheme
{
	public:
		/// Constructor.
		/**
		 * Creates a migration scheme associated with the given topology.
		 * \param[in] _topology topology to be used with the scheme
		 * \param[in] seed optional seed to initialise the internal RNG.
		 */
		ConstOutRateBCastMigrationScheme(const base_topology& _topology)
				:MigrationScheme(_topology)
		{
		}
		
		/// Copy constructor.
		/**
		 * Creates a deep copy of the object
		 */
		ConstOutRateBCastMigrationScheme(const ConstOutRateBCastMigrationScheme& ms):MigrationScheme(ms) { }
		
		/// Virtual destructor.
		virtual ~ConstOutRateBCastMigrationScheme() { }; 
	
		/// \see MigrationScheme::preEvolutionCallback
		virtual void preEvolutionCallback(island& _island);
		
		/// \see MigrationScheme::postEvolutionCallback
		virtual void postEvolutionCallback(island& _island);

		/// \see MigrationScheme::clone
		virtual MigrationScheme* clone() const { return new ConstOutRateBCastMigrationScheme(*this); }
		
		/// \see MigrationScheme::reset
		virtual void reset();
		
	private:
		/// Database of the migrating individuals.
		/**
		 * Maps island's id to a vector of individuals migrating into that island.
		 */
		boost::unordered_map<size_t, std::vector<Individual> > inbox;
};

#endif