#pragma once

class Quitourne;
class Contenu;
class Bloc;
class Particule;
class Neon;
class Argon;
class Systeme;
class Helium;
class Enceinte;

class SupportADessin
{
 public:
  virtual ~SupportADessin() = default;
  // on ne copie pas les Supports
  SupportADessin(SupportADessin const&)            = delete;
  SupportADessin& operator=(SupportADessin const&) = delete;
   // mais on peut les déplacer
  SupportADessin(SupportADessin&&)            = default;
  SupportADessin& operator=(SupportADessin&&) = default;

  SupportADessin() = default;


  virtual void dessine(Bloc const& a_dessiner) = 0;
  virtual void dessine(Particule const& a_dessiner) = 0;
  virtual void dessine(Neon const& a_dessiner) = 0;
  virtual void dessine(Argon const& a_dessiner) = 0;
  virtual void dessine(Systeme const& a_dessiner) = 0;
  virtual void dessine(Helium const& a_dessiner) = 0;
  virtual void dessine(Enceinte const& a_dessiner) = 0;

  /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
   * objets que l'on veut dessiner. Par exemple :
   *    virtual void dessine(Nounours const& a_dessiner) = 0;
   *    virtual void dessine(Voiture  const& a_dessiner) = 0;
   */
};
