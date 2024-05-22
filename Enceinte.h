#pragma once
#include "dessinable.h"
#include "Vecteur3D.h"
#include "support_a_dessin.h"

class Enceinte : public Dessinable {
    public:
    Enceinte (double Hauteur = 20.0, double Largeur = 20.0, double Profondeur = 20.0);

    double getProportion(int i) const;

    Vecteur3D getProportions() const;

    void affiche(std::ostream& out) const;

    unsigned int count();

    virtual void dessine_sur(SupportADessin& support) override;

    private:
    Vecteur3D proportions;
    unsigned int c1, c2, c3, c4, c5, c6; // utiliser un array ?
};

std::ostream& operator<<(std::ostream& out, const Enceinte& E);
