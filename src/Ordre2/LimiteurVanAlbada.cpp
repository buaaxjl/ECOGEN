//  
//       ,---.     ,--,    .---.     ,--,    ,---.    .-. .-. 
//       | .-'   .' .')   / .-. )  .' .'     | .-'    |  \| | 
//       | `-.   |  |(_)  | | |(_) |  |  __  | `-.    |   | | 
//       | .-'   \  \     | | | |  \  \ ( _) | .-'    | |\  | 
//       |  `--.  \  `-.  \ `-' /   \  `-) ) |  `--.  | | |)| 
//       /( __.'   \____\  )---'    )\____/  /( __.'  /(  (_) 
//      (__)              (_)      (__)     (__)     (__)     
//
//  This file is part of ECOGEN.
//
//  ECOGEN is the legal property of its developers, whose names 
//  are listed in the copyright file included with this source 
//  distribution.
//
//  ECOGEN is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published 
//  by the Free Software Foundation, either version 3 of the License, 
//  or (at your option) any later version.
//  
//  ECOGEN is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with ECOGEN (file LICENSE).  
//  If not, see <http://www.gnu.org/licenses/>.

#include "LimiteurVanAlbada.h"

using namespace std;

//***********************************************************************

LimiteurVanAlbada::LimiteurVanAlbada(){}

//***********************************************************************

LimiteurVanAlbada::~LimiteurVanAlbada(){}

//***********************************************************************

double LimiteurVanAlbada::limitePente(const double& pente1, const double& pente2) 
{
	double zero(1e-6);
	double pente(0.), produit(pente1*pente2), somme(pente1 + pente2);
	if( (fabs(pente1)>zero) && (fabs(pente2)>zero) && (fabs(somme)>zero)  && (produit>zero)){
		pente = produit*somme / (pente1*pente1 + pente2*pente2);
	}
	return pente;
}