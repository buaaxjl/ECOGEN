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

#ifndef FACENS_H
#define FACENS_H

#include "../Face.h"

class ElementNS; //Predeclaration de la classe Element pour pouvoir inclure Element.h
#include "ElementNS.h"

class FaceNS : public Face
{
public:
  FaceNS();
  FaceNS(const int &nombreNoeuds);
  virtual ~FaceNS();

  void construitFace(const Coord *noeuds, const int &numNoeudAutre, ElementNS *elementVoisin);
  bool faceExiste(FaceNS **faces, const int &indiceMaxFaces, int &indiceFaceExiste);
  void ajouteElementVoisin(ElementNS *elementVoisin);
  void ajouteElementVoisinLimite(ElementNS *elementVoisin);

  //Accesseurs
  ElementNS *getElementGauche() const;
  ElementNS *getElementDroite() const;
  void setEstLimite(const bool &estLimite);
  void setEstComm(const bool &estComm);
  bool getEstComm() const;
  int getSommeNumNoeuds() const;

  int getNombreNoeuds() const;
  int getNumNoeud(const int &numNoeud) const;
  void getInfoNoeuds(int *numNoeuds, int &sommeNumNoeuds) const;
  bool getEstLimite() const;
  void afficheNoeuds() const;
  virtual void afficheInfos() const;
  static int rechercheFace(int *face, int &sommeNoeuds, int **tableauFaces, int *tableauSommeNoeuds, int nombreNoeuds, int &indiceMaxFaces); // Recherche si face appartient au tableau tableauFaces : renvoi le numero ou -1 si absence
  static int rechercheFace(int *face, int &sommeNoeuds, std::vector<int*> tableauFaces, std::vector<int> tableauSommeNoeuds, int nombreNoeuds, int &indiceMaxFaces); // Recherche si face appartient au tableau tableauFaces : renvoi le numero ou -1 si absence. Utilise seulement sur ancienne version

protected:
  virtual void calculSurface(const Coord *noeuds){};
  virtual void calculRepere(const Coord *noeuds, const int &numNoeudAutre, ElementNS *elementVoisin){};

  int m_nombreNoeuds;   /*!< nombre de noeuds de la face */
  int *m_numNoeuds;     /*!< Numero des noeud relatif au tableau de noeuds global */
  int m_sommeNumNoeuds;
  bool m_limite;
  bool m_comm;
  ElementNS *m_elementGauche;
  ElementNS *m_elementDroite;

};

#endif // FACENS_H

//Surcharge operateur externe a la classe car prends deux arguments
bool operator==(const FaceNS &a, const FaceNS &b);
bool operator!=(const FaceNS &a, const FaceNS &b);