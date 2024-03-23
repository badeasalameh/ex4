
#include "Mtmchkin.h"
#include "utilities.h"
hahahahahahahahuhdubsfhbef;
#include "Encounter.h"
#include "Dragon.h"
#include "Giant.h"
#include "Goblin.h"
#include "Gang.h"

#include "Event.h"
#include "SolarEclipse.h"
#include "PotionMerchant.h"

#include "Warrior.h"
#include "Sorcerer.h"

#define POTION_COST 5
#define POTION_HEAL 10
#define SOLARECLIPSE_WARRIOR -1
#define SOLARECLIPSE_SORCERER 1

Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {

    /*===== TODO: Open and read cards file =====*/

    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/

    /*============================================*/


    this -> m_turnIndex = 1;
}

void Mtmchkin::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Draw a card from the deck
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the card
     * 4. Print the turn outcome with "printTurnOutcome"
    */
    if(!m_cards.empty())
    {
        shared_ptr<Card> cardToPlay = m_cards.front();
        printTurnDetails(m_turnIndex , player , *cardToPlay);

        shared_ptr<Encounter> encounterCard = dynamic_pointer_cast<Encounter>(cardToPlay);
        shared_ptr<Event> eventCard = dynamic_pointer_cast<Event>(cardToPlay);
        // ENCOUNTER CARD:

        if (encounterCard)
        {
            shared_ptr<Dragon> dragonCard = dynamic_pointer_cast<Dragon>(encounterCard);
            shared_ptr<Giant> giantCard = dynamic_pointer_cast<Giant>(encounterCard);
            shared_ptr<Goblin> goblinCard = dynamic_pointer_cast<Goblin>(encounterCard);
            shared_ptr<Gang> gangCard = dynamic_pointer_cast<Gang>(encounterCard);

            int lootWon = 0;
            int damageTaken = 0;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //DRAGON:
            if (dragonCard)
            {
                //DRAGON WIN:
                if (dragonCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(dragonCard -> getDamage());
                    damageTaken = dragonCard -> getDamage();

                    if (player.isKnockedOut())
                    {
                        //PLAYER DEAD! deal with him accordingly.
                    }
                    printTurnOutcome(player.getName() + " lost the encounter and took " + to_string(damageTaken) + " damage!");
                }
                else
                {//PLAYER WIN:
                    player.addCoins(dragonCard -> getLoot());
                    lootWon = dragonCard -> getLoot();
                    player.levelUp();
                    printTurnOutcome(player.getName() + " won the encounter, gained " + to_string(lootWon) + " coins and leveled up!");
                }
            }
            //GIANT:
            else if(giantCard)
            {
                //GIANT WIN:
                if(giantCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(goblinCard -> getDamage());
                    damageTaken = giantCard -> getDamage();
                    if(player.isKnockedOut())
                    {
                        //PLAYER DEAD! deal with him accordingly.
                    }
                    printTurnOutcome(player.getName() + " lost the encounter and took " + to_string(damageTaken) + " damage!");
                }
                //PLAYER WIN:
                else
                {
                    player.addCoins(giantCard -> getLoot());
                    lootWon = giantCard -> getLoot();
                    player.levelUp();
                    printTurnOutcome(player.getName() + " won the encounter, gained " + to_string(lootWon) + " coins and leveled up!");
                }
            }
            //GOBLIN
            else if(goblinCard)
            {
                //GOBLIN WIN:
                if(goblinCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(goblinCard -> getDamage());
                    damageTaken = goblinCard -> getDamage();
                    if(player.isKnockedOut())
                    {
                        //PLAYER DEAD! deal with him accordingly.
                    }
                    printTurnOutcome(player.getName() + " lost the encounter and took " + to_string(damageTaken) + " damage!");
                }
                    //PLAYER WIN:
                else
                {
                    player.addCoins(goblinCard -> getLoot());
                    lootWon = goblinCard -> getLoot();
                    player.levelUp();
                    printTurnOutcome(player.getName() + " won the encounter, gained " + to_string(lootWon) + " coins and leveled up!");
                }
            }
            //GANG
            else if (gangCard)
            {
                //GOBLIN WIN:
                if(gangCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(gangCard -> getDamage());
                    damageTaken = gangCard -> getDamage();
                    if(player.isKnockedOut())
                    {
                        //PLAYER DEAD! deal with him accordingly.
                    }
                    printTurnOutcome(player.getName() + " lost the encounter and took " + to_string(damageTaken) + " damage!");
                }
                    //PLAYER WIN:
                else
                {
                    player.addCoins(gangCard -> getLoot());
                    lootWon = gangCard -> getLoot();
                    player.levelUp();
                    printTurnOutcome(player.getName() + " won the encounter, gained " + to_string(lootWon) + " coins and leveled up!");
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //EVENT CARD:
        else if(eventCard)
        {
            shared_ptr<SolarEclipse> solarEclipseCard = dynamic_pointer_cast<SolarEclipse>(eventCard);
            shared_ptr<PotionMerchant> potionMerchantCard = dynamic_pointer_cast<PotionMerchant>(eventCard);

            Warrior* warriorPlayer = dynamic_cast<Warrior*>(&player);
            Sorcerer* sorcererPlayer = dynamic_cast<Sorcerer*>(&player);

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //SOLARECLIPSE:
            if(solarEclipseCard)
            {
                //PLAYER IS A WARRIOR:
                if(warriorPlayer)
                {
                    player.buff(SOLARECLIPSE_WARRIOR);
                    printTurnOutcome(player.getName() + " was affected by a solar eclipse! their force has changed by -1!");
                }
                //PLAYER IS A SORCERER:
                else if(sorcererPlayer)
                {
                    player.buff(SOLARECLIPSE_SORCERER);
                    printTurnOutcome(player.getName() + " was affected by a solar eclipse! their force has changed by 1!");
                }
            }
            //POTIONMERCHANT:
            else if(potionMerchantCard)
            {
                int potionsBought = 0;
                //PLAYER IS A RISKTAKER:
                if(player.getBehavior() == "RiskTaker" && player.getHealthPoints() < 50 && player.pay(POTION_COST))
                {
                    player.heal(POTION_HEAL);
                    potionsBought++;
                }
                //PLAYER IS RESPONSIBLE:
                else if(player.getBehavior() == "Warrior" && player.getHealthPoints() < player.getMaxHealthPoints())
                {
                    while(player.pay(POTION_COST) && (player.getHealthPoints() < player.getMaxHealthPoints()))
                    {
                        player.heal(POTION_HEAL);
                        potionsBought++;
                    }
                }
                printTurnOutcome(player.getName() + " bought " + to_string(potionsBought) + " potions!");
            }
        }
        m_turnIndex++;
    }
}

void Mtmchkin::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for(auto& player : m_players)
    {
        playTurn(*player.second);
    }

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();
    
    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool Mtmchkin::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    for(auto& player : m_players)
    {
        if(player.second -> getHealthPoints() > 0 && player.second -> getLevel() < 10)
        {
            return false;
        }
    }
    return true; // Replace this line
    /*===================================================*/
}

void Mtmchkin::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    
    /*========================================================================*/
}
