#include "Vecteur3D.h"
#include <cmath>
#include <iostream>

using namespace std;

double Vecteur3D::epsilon = 1;

void Vecteur3D::set_coord(int indice, double valeur) {
    switch (indice) {
        case 0: coordonnees[0] = valeur; break;
        case 1: coordonnees[1] = valeur ; break;
        case 2: coordonnees[2] = valeur ; break;
        default: throw out_of_range("L'indice est indefini");
    }
}

Vecteur3D::Vecteur3D(double x, double y, double z)
{
    coordonnees[0] = x;
    coordonnees[1] = y;
    coordonnees[2] = z;
}


double Vecteur3D::get_coord(unsigned int i) const{
    switch (i) {
        case 0: return coordonnees[0];
        case 1: return coordonnees[1];
        case 2: return coordonnees[2];
        default: throw out_of_range("L'indice est indefini"); // frr ca fait quoi ca en fait ?
    }
}


double Vecteur3D::norme() const{
    double resultat_norme(0);
    for (int i = 0; i < 3; ++i) {
        resultat_norme += coordonnees[i] * coordonnees[i];
    }
    return sqrt(resultat_norme);
}

double Vecteur3D::norme2() const{
    return norme() * norme();
}

bool Vecteur3D::compare(const Vecteur3D& vecteur) const {
    return (abs(coordonnees[0] - vecteur.get_coord(0)) < epsilon and
            abs(coordonnees[1] - vecteur.get_coord(1)) < epsilon and 
            abs(coordonnees[2] - vecteur.get_coord(2)) < epsilon);
}

void Vecteur3D::set_precision(const double& x) {
    epsilon = x;
}

void Vecteur3D::affiche(ostream& out) const {
    out << get_coord(0) << " " << get_coord(1) << " " << get_coord(2);
}

// Operateurs

Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& vecteur){
    for (int i = 0; i < 3; ++i){
        coordonnees[i]-=vecteur.coordonnees[i];
    }
    return *this;
}

Vecteur3D& Vecteur3D::operator*=(const double& scalaire){
    for (int i = 0; i < 3; ++i){
        coordonnees[i]*=scalaire;
    }
    return *this;
}

Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& vecteur) {
    for (int i = 0; i < 3; ++i){
        coordonnees[i]+=vecteur.coordonnees[i];
    }
    return *this;
}

double Vecteur3D::operator*(const Vecteur3D& vecteur) const{
    double resultat(0);
    for (int i = 0; i < 3; ++i) {
        resultat += coordonnees[i] * vecteur.coordonnees[i];
    }
    return resultat;
}

Vecteur3D Vecteur3D::operator-() const {  //opposé
    Vecteur3D resultat;
    for (int i = 0; i < 3; ++i){
        resultat.coordonnees[i] = -coordonnees[i];
    }
    return resultat;
}

Vecteur3D Vecteur3D::operator~() const {
    double longueur = norme(); 
    if (longueur != 0) {
        Vecteur3D resultat_unitaire;
        for (int i = 0; i < 3; ++i) {
            resultat_unitaire.coordonnees[i] = coordonnees[i] / longueur;
        }
        return resultat_unitaire;
    } else {
        return Vecteur3D(0, 0, 0);
    }
}

bool Vecteur3D::operator==(Vecteur3D const& v2) const {
    return compare(v2);
}   

bool Vecteur3D::operator!=(Vecteur3D const& v2) const {
    return (fabs(coordonnees[0] - v2.coordonnees[0]) >= epsilon or
            fabs(coordonnees[1] - v2.coordonnees[1]) >= epsilon or
            fabs(coordonnees[2] - v2.coordonnees[2]) >= epsilon);
    
}

Vecteur3D& Vecteur3D::operator^=(const Vecteur3D& vecteur) {
    double tempX = coordonnees[1] * vecteur.coordonnees[2] - coordonnees[2] * vecteur.coordonnees[1];
    double tempY = coordonnees[2] * vecteur.coordonnees[0] - coordonnees[0] * vecteur.coordonnees[2];
    double tempZ = coordonnees[0] * vecteur.coordonnees[1] - coordonnees[1] * vecteur.coordonnees[0];
    coordonnees[0] = tempX, coordonnees[1] = tempY, coordonnees[2] = tempZ;

    return *this;
}

ostream& operator<<(ostream& op, const Vecteur3D& v) {
    v.affiche(op);
    return op;
}

const Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2) {
    Vecteur3D tmp(v1);
    tmp += v2;
    return tmp;
}

// Difference de deux vecteurs
const Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2) { 
    Vecteur3D tmp(v1);
    tmp -= v2;
    return tmp;
}

const Vecteur3D operator*(Vecteur3D v1, double const& scalaire) {
    Vecteur3D tmp(v1);
    tmp *= scalaire;
    return tmp;
}

const Vecteur3D operator*(double const& scalaire, Vecteur3D v1) {
    Vecteur3D tmp(v1);
    tmp *= scalaire;
    return tmp;
}

const Vecteur3D operator^(Vecteur3D v1, Vecteur3D const& v2) {
    Vecteur3D tmp(v1);
    tmp ^= v2;
    return tmp;
}