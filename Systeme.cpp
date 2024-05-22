#include "Systeme.h"

using namespace std;
// Est ce qu on garde le construdcteur par defaut ?
Systeme::Systeme() {} 

Systeme::Systeme(double T, double hauteur, double largeur, double profondeur, unsigned int graine)
    :  enceinte(hauteur, largeur, profondeur), temperature(T), tirage(graine) {}

Systeme::~Systeme() {
    supprime();
    // Ressources libérées automatiquement par les destructeurs de vector et shared_ptr
}

void Systeme::ajouteParticule(const Particule& p) {
    particules.push_back(p.copie());
}

void Systeme::dessine_sur(SupportADessin& support) {
    support.dessine(enceinte); // Dessine l'enceinte
    for (auto const& particule : particules) {
        particule->dessine_sur(support); // Dessine chaque particule
    }
}

void Systeme::affiche(ostream& out) const {
    out << "Le systeme est compose de(s) " << particules.size() << " particules suivantes : " << endl;
    for (auto const& particule : particules) {
        particule->affiche(out);
    }
}

void Systeme::supprime(){
    particules.clear();
}

ostream& operator<<(ostream& out, const Systeme& s) {
    s.affiche(out);
    return out;
}

void Systeme::afficher_avant_choc(unsigned int i, unsigned int j) const {
    cout << "La particule " << i << " entre en collision avec une autre particule." << endl
        << "    Avant le choc : " << endl << "      part. " << i << " : " << *particules[i]
        << "      autre : " << *particules[j];
}

void Systeme::afficher_apres_choc(unsigned int i, unsigned int j) const {
    cout << "   Apres le choc : " << endl << "      part. " << i << " : " << *particules[i] <<
            "      autre : " << *particules[j] << endl;
}

void Systeme::evolue(const double& dt) {
    for (int i = 0; i < particules.size(); ++i) {
        collision_mur(*particules[i]);
        for (int j = i + 1; j < particules.size(); ++j) {
            if (particules[i]->collisionAvec(*particules[j])) {
                afficher_avant_choc(i, j);
                particules[i]->resoudreCollision(*particules[j]);
                afficher_apres_choc(i, j);
            }
        }
    }
    cout << "-----------------------------" << endl;
    for (auto const& particule : particules) {
        particule->evolue(dt);
    } 
}

void Systeme::collision_mur(Particule& p) {
    double x = p.get_pos().get_coord(0);
    double y = p.get_pos().get_coord(1);
    double z = p.get_pos().get_coord(2);
    Vecteur3D v = p.get_vitesse();
    for (int i = 0; i < 3; ++i){
        if ((p.get_pos().get_coord(i) < 0) or (p.get_pos().get_coord(i) > enceinte.getProportion(i))) {
            cout << "Il y a collision avec un mur" << endl;
            p.set_coord_v(i, -p.get_vitesse().get_coord(i));
            p.set_coord_p(i, max(0.0, min(p.get_pos().get_coord(i), enceinte.getProportion(i))));
        }
    }
}

Vecteur3D Systeme::generer_pos() {
    Vecteur3D v(enceinte.getProportions());
    double x = tirage.uniforme(0, v.get_coord(0));
    double y = tirage.uniforme(0, v.get_coord(1));
    double z = tirage.uniforme(0, v.get_coord(2));
    
    return Vecteur3D (x, y, z);
}

Vecteur3D Systeme::generer_v(const unsigned int n ) {
    double m, cste;
    switch (n) {
        case 0: m = 39.948; break; // Argon
        case 1: m = 4.002602; break; // Helium
        case 2: m = 20.1797; break; // Neon
        default: throw out_of_range("L'indice est indefini");
    }   
    cste = ((8.314472 / m) / 100); // *1000 ?
    return Vecteur3D(tirage.gaussienne(0.0, cste * temperature), 
                     tirage.gaussienne(0.0, cste * temperature), 
                     tirage.gaussienne(0.0, cste * temperature));
}

void Systeme::simulation(unsigned int nombre, SupportADessin& support, double dt) {
    for (int i = 0 ; i < nombre ; ++i) {
        evolue(dt);
    }
    dessine_sur(support);
}
const std::vector<std::unique_ptr<Particule>>& Systeme::getParticules() const
{
    return particules;
}

double Systeme::moyenneVitesseX() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_vitesse().get_coord(0);
    }
    return (somme / particules.size());
}

double Systeme::moyenneVitesseY() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_vitesse().get_coord(1);
    }
    return (somme / particules.size());
}

double Systeme::moyenneVitesseZ() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_vitesse().get_coord(2);
    }
    return (somme / particules.size());
}

double Systeme::moyennePositionX() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_pos().get_coord(0);
    }
    return ( somme / particules.size());
}

double Systeme::moyennePositionY() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_pos().get_coord(1);
    }
    return (somme / particules.size());
}

double Systeme::moyennePositionZ() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_pos().get_coord(2);
    }
    return (somme / particules.size());
}

double Systeme::moyenneNormeVitesse() const {
    double somme = 0.0;
    for (const auto& p : particules) {
        somme += p->get_vitesse().norme();
    }
    return (somme / particules.size());
}
