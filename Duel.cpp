#include "Duel.h"
#include <algorithm>


Duel::Duel()
{
}

void Duel::attack(std::shared_ptr<IClass> attacker, Party &attackerParty, Party &defender)
{
    //first check if the attacker is a cleric that will heal its team during its turn
    if(attacker->getClassType() == 2)
    for (std::shared_ptr<IClass> character : attackerParty.getParty()) {
        character->takeDamage(-1*(attacker->getHealing()));
    }
   

    //wizard does splash damage so it needs its own case
    if(attacker->getClassType() == 4){
       
        defender.getParty()[0]->takeDamage(attacker->getHitBonus());
       
        if(defender.getParty().size() > 1){
        defender.getParty()[1]->takeDamage(attacker->getHitBonus());
        }

    }


    else{
        defender.getParty()[0]->takeDamage(attacker->getHitBonus());
    }


    checkHP(defender);
}

void Duel::checkHP(Party &defender)
{
    //only need to check the first and second characters b/c no more than that can get damaged
    if(defender.getParty()[0]->getHitPoints() <= 0){
       
        defender.removeCharacter(defender.getParty()[0]);
        
        if(defender.getParty().size() > 1 && defender.getParty()[0]->getHitPoints() <= 0){
            defender.removeCharacter(defender.getParty()[0]);
        }

    }
    else if(defender.getParty().size() > 1 && defender.getParty()[1]->getHitPoints() <= 0){
        defender.removeCharacter(defender.getParty()[1]);
    }
    
   
    
}
