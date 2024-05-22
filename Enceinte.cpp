#include <iostream>
#include "Enceinte.h"
using namespace std;

Enceinte::Enceinte(double Hauteur, double Largeur, double Profondeur)
: proportions(Hauteur, Largeur, Profondeur) {}


double Enceinte::getProportion(int i) const {
    return proportions.get_coord(i);
}

Vecteur3D Enceinte::getProportions() const {
    return proportions;
}

void Enceinte::affiche(ostream& out) const {
    out << "Largeur : " << getProportion(0) << ", Hauteur : " << getProportion(1) << ", Profondeur : " << getProportion(2) << endl;
}

ostream& operator<<(ostream& out, const Enceinte& E) {
    E.affiche(out);
    return out;
}

void Enceinte::dessine_sur(SupportADessin& support) {
    support.dessine(*this); 
}

unsigned int Enceinte::count() {
    return 0;
    // Comptera le nombre de choc avec la paroi
}