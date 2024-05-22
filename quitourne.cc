#include "quitourne.h"

// ======================================================================
void Quitourne::evolue(double dt)
{
  constexpr double omega(100.0);
  angle += omega * dt;
}
