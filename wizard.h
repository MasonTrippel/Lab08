#include "IClass.h"

class wizard : public IClass{
    public:
        wizard(std::shared_ptr<IRace> race) : IClass(race){
        m_hitPoint = 12;
        //easier to hit
        m_armorClass = 12;
        m_hitBonus = 2;
        m_initiative = 8;
        //low damage to whole team
        m_baseDamage = 1;
        classType = 4;
	}

    virtual ~wizard() {}
    wizard() = delete;

    private:


};