    //
// Created by Mahmoud on 3/20/2024.
//

#include "Warrior.h"

int  Warrior::getAttackStrength() const {
    return (m_force*2 +m_level);
}
    Warrior& Warrior::operator=(const Warrior& Warriorplayer) {

    m_name=Warriorplayer.m_name;
        m_level=Warriorplayer.m_level;
        m_force=Warriorplayer.m_force;
        m_maxHP=Warriorplayer.m_maxHP;
        m_coins=Warriorplayer.m_coins;
        m_job=Warriorplayer.m_job;
        m_behavior=Warriorplayer.m_behavior;
        return *this;
}

    Warrior::Warrior(const Warrior &WarriorPlayer): Player(WarriorPlayer) {
        m_name=WarriorPlayer.m_name;
        m_level=WarriorPlayer.m_level;
        m_force=WarriorPlayer.m_force;
        m_maxHP=WarriorPlayer.m_maxHP;
        m_coins=WarriorPlayer.m_coins;
        m_job=WarriorPlayer.m_job;
        m_behavior=WarriorPlayer.m_behavior;
    }

