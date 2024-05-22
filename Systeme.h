#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Particule.h"
#include "Enceinte.h"
#include "Dessinable.h"
#include "support_a_dessin.h"

class Systeme : public Dessinable {
public:
    Systeme();
    Systeme (double T, double hauteur, double largeur, double profondeur, unsigned int graine = std::random_device()());
    Systeme(Systeme const&) = delete;
    Systeme& operator=(Systeme const&) = delete;

    virtual ~Systeme() override;

    void ajouteParticule(const Particule& p);
    
    virtual void dessine_sur(SupportADessin& support) override;

    void supprime();

    void affiche(std::ostream& out) const;

    void evolue(const double& dt);

    void afficher_avant_choc(unsigned int i, unsigned int j) const;

    void afficher_apres_choc(unsigned int i, unsigned int j) const;
    
    void simulation (unsigned int nombre, SupportADessin& support, double dt = 1);

    const std::vector<std::unique_ptr<Particule>>& getParticules() const;

    Vecteur3D generer_pos();

    Vecteur3D generer_v(const unsigned int n);

    void collision_mur(Particule& p);
    double moyenneVitesseX() const;
    double moyenneVitesseY() const;
    double moyenneVitesseZ() const;
    double moyennePositionX() const;
    double moyennePositionY() const;
    double moyennePositionZ() const;
    double moyenneNormeVitesse()const;
private:
    std::vector<std::unique_ptr<Particule>> particules;
    Enceinte enceinte;
    GenerateurAleatoire tirage;
    double temperature = 300;
};

std::ostream& operator<<(std::ostream& out, const Systeme& s);
