#pragma once

#include "Machin.h"
#include "support_a_dessin.h"

class Bloc : public Machin {
    public:
    virtual void dessine_sur(SupportADessin& support) override
    { support.dessine(*this); }

    virtual void evolue(double dt) override;


};
