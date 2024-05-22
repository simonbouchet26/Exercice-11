#pragma once
#include "Vecteur3D.h"
#include "Dessinable.h"
#include "Enceinte.h"
#include <string>
#include <memory>
#include <cmath>
#include "GenerateurAleatoire.h"

class Enceinte;


// -------------------------- Superclasse Particule --------------------------

class Particule : public Dessinable {
    public:

    // Methodes d'implementation

    Particule (Vecteur3D Pos = Vecteur3D(0, 0, 0), Vecteur3D V = Vecteur3D(1, 0, 0), std::string name = "Particule", double M = 1, bool Tracable = false, GenerateurAleatoire graine = 123456); // constructeur (avec des valeurs par defaut)

    virtual ~Particule(); // destructeur (n'affiche rien)

    virtual void dessine_sur(SupportADessin& support) override;

    double get_masse() const;

    void setPosition (double x, double y, double z);

    void setVitesse(double x, double y, double z);

    void set_coord_v(unsigned int i, double val);

    void set_coord_p(unsigned int i, double val);

    Vecteur3D get_pos() const;

    Vecteur3D get_vitesse() const;

    virtual std::unique_ptr<Particule> copie() const;

    // Methodes d'affichage

    virtual void affiche(std::ostream& out) const; 

    // Methodes pour gerer l'evolution

    void evolue(double dt);

    bool collisionAvec(const Particule& autre) const;

    Vecteur3D tirage_uniforme(double norme);

    void resoudreCollision(Particule& autre); 

    void set_trace(const bool b);

    bool get_tracable() const;

    protected:
    Vecteur3D position, vitesse;
    double masse;
    std::string nom;
    GenerateurAleatoire tirage;
    bool tracable;
};


// -------------------------- Differentes Particules --------------------------

class Argon : public  Particule {
    public:
    Argon (Vecteur3D Pos  = Vecteur3D(1, 1, 1), Vecteur3D V = Vecteur3D(1, 1, 1), std::string name = "Argon", const double M = 39.948);

    virtual void affiche(std::ostream& out) const override;
    
    void dessine_sur(SupportADessin& support) override;

    virtual std::unique_ptr<Particule> copie() const override;
};

class Neon : public Particule {
    public:
    Neon (Vecteur3D V  = Vecteur3D(1, 1, 1), Vecteur3D Pos = Vecteur3D(1, 1, 1), std::string name = "Neon", const double M = 20.1797);

    virtual void affiche(std::ostream& out) const override;
    void dessine_sur(SupportADessin& support) override;

    virtual std::unique_ptr<Particule> copie() const override;
    
};

class Helium : public Particule {
    public:
    Helium (Vecteur3D V  = Vecteur3D(1, 1, 1), Vecteur3D Pos = Vecteur3D(1, 1, 1), std::string name = "Helium", const double M = 4.002602);

    virtual void affiche(std::ostream& out) const override;
    void dessine_sur(SupportADessin& support) override;

    virtual std::unique_ptr<Particule> copie() const override;

};

std::ostream& operator<<(std::ostream& out, const Particule& p);
