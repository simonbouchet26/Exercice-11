#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"
#include "Machin.h"
#include <memory>
#include <vector>

class Contenu : public Dessinable {
public:
  Contenu() = default;
  virtual ~Contenu() = default;
  Contenu(Contenu const&)            = default;
  Contenu& operator=(Contenu const&) = default;
  Contenu(Contenu&&)                 = default;
  Contenu& operator=(Contenu&&)      = default;

  virtual void dessine_sur(SupportADessin& support) override;

  void ajoute(Machin* m);

  void evolue(double dt);


private:
  std::vector<std::unique_ptr<Machin>> machin;

};
