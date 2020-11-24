#include <iostream>

class Weapon
{
protected:
    std::string mName = "weapon name";
    int mDamage = 1;
private:

public:
    virtual void Swing() = 0;

    void SetName(std::string str)
    {
        mName = str;
    }

    void SetDamage(int damage)
    {
        mDamage = damage;
    }

    int GetDamage()
    {
        return mDamage;
    }
};

class Axe : public Weapon
{
public:
    void Swing() override
    {
        std::cout << "swinging " << mName << " for " << mDamage << " damage." << std::endl;
    }
};

class Sword : public Weapon
{
public:
    void Swing() override
    {
        std::cout << "swinging " << mName << " for " << mDamage << " damage." << std::endl;
    }
};

class WeaponEnhancer
{
public:
    void Enhance(Weapon& weapon)
    {
        weapon.SetDamage(weapon.GetDamage() + 5);
    }
};

int main()
{
    Axe axe;
    Sword sword;

    axe.SetName("a big axe");
    sword.SetName("a big sword");

    axe.SetDamage(3);
    sword.SetDamage(2);

    axe.Swing();
    sword.Swing();

    WeaponEnhancer enhancer;
    enhancer.Enhance(axe);
    enhancer.Enhance(sword);

    axe.Swing();
    sword.Swing();
}