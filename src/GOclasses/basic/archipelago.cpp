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

#include "../problems/GOproblem.h"
#include "../algorithms/go_algorithm.h"
#include "archipelago.h"
#include "island.h"

archipelago::archipelago(const GOProblem &p):m_gop(p.clone()) {}

archipelago::archipelago(int N, int M, const GOProblem &p, const go_algorithm &a):m_gop(p.clone())
{
	for (int i = 0; i < N; ++i) {
		push_back(M,a);
	}
}

archipelago::archipelago(const archipelago &a):m_container(a.m_container),m_gop(a.m_gop->clone())
{
	const iterator it_f = end();
	for (iterator it = begin(); it != it_f; ++it) {
		it->set_archipelago(this);
	}
}

size_t archipelago::size() const
{
	return m_container.size();
}

void archipelago::push_back(int N, const go_algorithm &a)
{
	m_container.push_back(island(N,*m_gop,a));
	m_container.back().set_archipelago(this);
}

const GOProblem &archipelago::problem() const
{
	return *m_gop;
}