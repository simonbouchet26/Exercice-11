#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"
#include "Machin.h"

class Quitourne : public Machin {
public:
  Quitourne(double a = 0.0)
    : angle(a)
  {}
  virtual ~Quitourne() = default;
  Quitourne(Quitourne const&)            = default;
  Quitourne& operator=(Quitourne const&) = default;
  Quitourne(Quitourne&&)                 = default;
  Quitourne& operator=(Quitourne&&)      = default;


  virtual void evolue(double dt) override;

  // accesseur
  double infos() const { return angle; }

private:
  double angle; /* pour le mouvement ;
                   dans cet exemple, juste une rotation
                   au cours du temps                    */
};
