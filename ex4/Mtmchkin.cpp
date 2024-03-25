
#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {
/*
 * in the constructor, when defining the m_players, fill the m_leaderboard with the players as well.
 * initialize the m_numOfWinners and m_numOfLosers to 0.
 */
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

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //DRAGON:
            if (dragonCard)
            {
                //DRAGON WIN:
                if (dragonCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(dragonCard -> getDamage());
                    printTurnOutcome(getEncounterLostMessage(player ,dragonCard -> getDamage()));
                }
                else
                {//PLAYER WIN:
                    player.addCoins(dragonCard -> getLoot());
                    player.levelUp();
                    printTurnOutcome(getEncounterWonMessage(player , dragonCard -> getLoot()));
                }
            }
            //GIANT:
            else if(giantCard)
            {
                //GIANT WIN:
                if(giantCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(goblinCard -> getDamage());
                    printTurnOutcome(getEncounterLostMessage(player , giantCard -> getDamage()));
                }
                //PLAYER WIN:
                else
                {
                    player.addCoins(giantCard -> getLoot());
                    player.levelUp();
                    printTurnOutcome(getEncounterWonMessage(player , giantCard -> getLoot()));
                }
            }
            //GOBLIN
            else if(goblinCard)
            {
                //GOBLIN WIN:
                if(goblinCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(goblinCard -> getDamage());
                    printTurnOutcome(getEncounterLostMessage(player , goblinCard -> getDamage()));
                }
                    //PLAYER WIN:
                else
                {
                    player.addCoins(goblinCard -> getLoot());
                    player.levelUp();
                    printTurnOutcome(getEncounterWonMessage(player , goblinCard -> getLoot()));
                }
            }
            //GANG
            else if (gangCard)
            {
                //GOBLIN WIN:
                if(gangCard -> getCombatPower() >= player.getAttackStrength())
                {
                    player.damage(gangCard -> getDamage());
                    printTurnOutcome(getEncounterLostMessage(player , gangCard -> getDamage()));
                }
                    //PLAYER WIN:
                else
                {
                    player.addCoins(gangCard -> getLoot());
                    player.levelUp();
                    printTurnOutcome(getEncounterWonMessage(player , gangCard -> getLoot()));
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //EVENT CARD:
        else if(eventCard)
        {
            shared_ptr<SolarEclipse> solarEclipseCard = dynamic_pointer_cast<SolarEclipse>(eventCard);
            shared_ptr<PotionMerchant> potionMerchantCard = dynamic_pointer_cast<PotionMerchant>(eventCard);

            auto* warriorPlayer = dynamic_cast<Warrior*>(&player);
            auto* sorcererPlayer = dynamic_cast<Sorcerer*>(&player);

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //SOLARECLIPSE:
            if(solarEclipseCard)
            {
                //PLAYER IS A WARRIOR:
                if(warriorPlayer)
                {
                    player.buff(SOLARECLIPSE_WARRIOR);
                    printTurnOutcome(getSolarEclipseMessage(player , SOLARECLIPSE_WARRIOR));
                }
                //PLAYER IS A SORCERER:
                else if(sorcererPlayer)
                {
                    player.buff(SOLARECLIPSE_SORCERER);
                    printTurnOutcome(getSolarEclipseMessage(player , SOLARECLIPSE_SORCERER));
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
                printTurnOutcome(getPotionsPurchaseMessage(player , potionsBought));
            }
        }
        m_turnIndex++;
    }
}

void Mtmchkin::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for (auto it = m_players.begin() ; it != m_players.end() ; it++)
    {
        auto &curPlayer = it -> second;
        playTurn(*curPlayer);
        //////////////////////////////////////
        //PLAYER DEAD/WON, MOVE TO FINISHED BRACKET:
        if (curPlayer -> isKnockedOut() || curPlayer -> getLevel() == MAX_LEVEL)
        {
            if(curPlayer -> getLevel() == MAX_LEVEL)
            {
                m_numOfWinners++;
            }
            else if(curPlayer -> isKnockedOut())
            {
                m_numOfLosers++;
            }
            m_finished.push_back(curPlayer);
            it = m_players.erase(it);
        }
    }
    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();
    
    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
    int playerIndex = 1;
    for(auto& player : m_leaderboard)
    {
        printLeaderBoardEntry(playerIndex , *player);
        playerIndex++;
    }
    /*=======================================================================================*/

    printBarrier();
}

bool Mtmchkin::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    if(m_numOfWinners > 0 || m_numOfLosers == m_leaderboard.size())
    {
        return true;
    }
    return false;
    /*===================================================*/
}

void Mtmchkin::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/
    int playerIndex = 1;
   for(auto& player : m_players)
   {
       printStartPlayerEntry(playerIndex , *player.second);
       playerIndex++;
   }
    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    if(m_numOfWinners > 0)
    {
        auto it = m_leaderboard.begin();
        const shared_ptr<Player>& winner = *it;
        printWinner(*winner);
    }
    else
    {
        printNoWinners();
    }
    /*========================================================================*/
}
