#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include "Particule.h"
using namespace std;


// -------------------------- Super-classe Particule --------------------------


// Methodes d'implementation

Particule::Particule(Vecteur3D Pos, Vecteur3D V, string name, double M, bool Tracable, GenerateurAleatoire graine) // constructeur
: position(Pos), vitesse(V), nom(name), masse(M), tracable(Tracable)  
{}

Particule::~Particule()
{}

void Particule::dessine_sur(SupportADessin& support)
    { support.dessine(*this); }

double Particule::get_masse() const{
    return masse;
}

void Particule::setPosition(double x, double y, double z) {
    position.set_coord(0, x);
    position.set_coord(1, y);
    position.set_coord(2, z);
}

void Particule::setVitesse(double x, double y, double z) {
    vitesse.set_coord(0, x);
    vitesse.set_coord(1, y);
    vitesse.set_coord(2, z);
}

void Particule::set_coord_v(unsigned int i, double val) {
    vitesse.set_coord(i, val);
}

void Particule::set_coord_p(unsigned int i, double val) {
    position.set_coord(i, val);
}

Vecteur3D Particule::get_pos() const {
    return position;
} 

Vecteur3D Particule::get_vitesse() const{
    return vitesse;
}

unique_ptr<Particule> Particule::copie() const {
    return unique_ptr<Particule> (new Particule(*this));
}

// Methodes d'affichage

void Particule::affiche(ostream& out) const {
    out << "pos : " << position << " ; v : " << vitesse << " ; masse : " << masse << endl;
}

ostream& operator<<(ostream& out, const Particule& p) {
    p.affiche(out);
    return out;
}


// Methodes pour gerer l'evolution

void Particule::evolue(double dt) {
    position += (dt*vitesse);
}

bool Particule::collisionAvec(const Particule& autre) const {
    return (position == autre.get_pos());
}

Vecteur3D Particule::tirage_uniforme(double L) {
    double z = tirage.uniforme(-L, L);
    double phi = tirage.uniforme(0, 2 * M_PI);
    double r = sqrt(L * L - z * z);
    return Vecteur3D(r*cos(phi), r*sin(phi), z);
}

void Particule::resoudreCollision(Particule& autre) {
    Vecteur3D vg  = (masse/(masse + autre.masse))*vitesse + (autre.masse/(masse + autre.masse))*autre.vitesse; 
    double L = (vitesse - vg).norme();
    Vecteur3D v0(tirage_uniforme(L));   
    vitesse =  vg + v0;
    autre.vitesse = vg - (masse / autre.masse) * v0;
}

void Particule::set_trace(const bool b) {
    tracable = b;
}

bool Particule::get_tracable() const {
    return tracable;
}

// -------------------------- Sous-classe Argon --------------------------

Argon::Argon(Vecteur3D Pos, Vecteur3D V, string name, double m)
: Particule( Pos, V, name, m) {
    cout << "Une particule d'Argon a été crée !" << endl;
}

void Argon::dessine_sur(SupportADessin& support)
    { support.dessine(*this); }

void Argon::affiche(ostream& out) const {
    out << "Particule " << nom << " : ";
    Particule::affiche(out);
}

unique_ptr<Particule> Argon::copie() const {
    return unique_ptr<Particule> (new Argon(*this));
}

// -------------------------- Sous-classe Neon --------------------------

void Neon::dessine_sur(SupportADessin& support)
    { support.dessine(*this); }

Neon::Neon(Vecteur3D Pos, Vecteur3D V, string name, double m)
: Particule(Pos, V, name, m) {
    cout << "Une particule de Neon a été crée !" << endl;
}

void Neon::affiche(ostream& out) const  {
    out << "particule " << nom << " : ";
    Particule::affiche(out);
}

unique_ptr<Particule> Neon::copie() const {
    return unique_ptr<Particule> (new Neon(*this));
}

// -------------------------- Sous-classe Helium --------------------------

Helium::Helium(Vecteur3D Pos, Vecteur3D V, string name, double m)
: Particule(Pos, V, name, m) {
    cout << "Une particule d'Helium a été crée !" << endl;
}

void Helium::dessine_sur(SupportADessin& support)
    { support.dessine(*this); }

void Helium::affiche(ostream& out) const {
    out << "particule " << nom << " : ";
    Particule::affiche(out);
}

unique_ptr<Particule> Helium::copie() const {
    return unique_ptr<Particule> (new Helium(*this));
}
