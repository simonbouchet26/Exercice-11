#include "contenu.h"
#include <vector>
#include "support_a_dessin.h"

using namespace std;
// ======================================================================
void Contenu::evolue(double dt)
{
   for(auto const& m :machin){
       m->evolue(dt);
   }
}

void Contenu::ajoute(Machin* m) {
    machin.push_back(unique_ptr<Machin>(m) );
}

void Contenu::dessine_sur(SupportADessin& support){
    for(auto const& m :machin){
        m->dessine_sur(support);
    }
}
