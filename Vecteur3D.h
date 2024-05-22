#pragma once
#include <iostream>

class Vecteur3D {
    public:

    Vecteur3D (double x = 0.0, double y = 0.0, double z = 0.0); // constructeur 

    void set_coord(int indice_coordonnee, double valeur); //modifie une coordonnée d'un vecteur

    double get_coord(unsigned int i) const;

    double norme() const; // norme 
    
    double norme2() const; // norme au carré

    bool compare(const Vecteur3D& vecteur) const; // compare si deux vecteurs sont egaux avec une tolérance choisie 

    // Operateurs

    Vecteur3D& operator*=(const double& scalaire);

    Vecteur3D& operator-=(const Vecteur3D& vecteur);

    Vecteur3D& operator+=(const Vecteur3D& vecteur);

    Vecteur3D& operator^=(const Vecteur3D& vecteur);
    
    Vecteur3D operator~() const; // Vecteur unitaire  

    Vecteur3D operator-() const; // Opposé

    double operator*(const Vecteur3D& vecteur) const; // Produit scalaire

    bool operator==(const Vecteur3D& vecteur) const; // Verification si egaux

    bool operator!=(const Vecteur3D& vecteur) const; // Verification si inegaux 

    void set_precision(const double& x);

    double get_precision() const;

    void affiche(std::ostream& out) const;

    private:
    static double epsilon;
    double coordonnees[3];
};

std::ostream& operator<<(std::ostream& op, const Vecteur3D& v);

const Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2); // Addition 2 vecteurs
const Vecteur3D operator*(Vecteur3D v1, double const& scalaire);
const Vecteur3D operator*(double const& scalaire, Vecteur3D v1);
const Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2); // Soustraction de deux vecteurs 
const Vecteur3D operator^(Vecteur3D v1, Vecteur3D const& v2); // Produit vectoriel de deux vecteurs 
