#include "party.h"
#include "characterFactory.h"


class Duel{

    public:
    Duel();



    void attack(std::shared_ptr<IClass> attacker, Party &attackerParty, Party &defender);

    void checkHP(Party &defender);

    
    private:

    
    int round;

};