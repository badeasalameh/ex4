
#include "Mtmchkin.h"
#include "utilities.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include "Players/Player.h"
#include "Players/Warrior.h"
#include "Players/Sorcerer.h"
#include "Cards/Dragon.h"
#include "Cards/Encounter.h"
#include "Cards/Event.h"
#include "Cards/Gang.h"
#include "Cards/Giant.h"
#include "Cards/Goblin.h"
#include "Cards/PotionMerchant.h"
#include "Cards/SolarEclipse.h"
#include "Cards/InvalidCardsFile.h"
#include "Players/InvalidPlayersFile.h"
#include <algorithm>



void Mtmchkin::set_in_LeaderBoard(){
    for (auto& m_player: m_players) {
        auto& curPlayer = m_player.second;
        m_leaderboard.push_back(curPlayer);
    }
}

bool isValidPlayersNum(std::ifstream& PlayersFile) {
    int lines_counter = 0;
    std::string line;
    while (std::getline(PlayersFile, line)) {
        lines_counter++;
    }
    return (lines_counter >= 2 && lines_counter <= 6);
}

bool isValidPlayerName(const std::string& name) {
    int size = name.size();
    for (int i = 0; i < size; i++) {
        if (!std::isalpha(name[i]) ) return false;
    }
    return true;
}


bool isValidPlayerInput(const std::string& firstString, const std::string& secondString, const std::string& thirdString) {
    const int MIN_NAME_LENGTH = 3;
    const int MAX_NAME_LENGTH = 15;
    const std::string VALID_JOBS[] = {"Warrior", "Sorcerer"};
    const std::string VALID_BEHAVIORS[] = {"RiskTaking", "Responsible"};

    if (isValidPlayerName(firstString)  && firstString.size() >= MIN_NAME_LENGTH && firstString.size() <= MAX_NAME_LENGTH
    && (secondString == VALID_JOBS[0] || secondString == VALID_JOBS[1]) &&
        (thirdString == VALID_BEHAVIORS[0] || thirdString == VALID_BEHAVIORS[1])) {
        return true;
    }
    return false;
}



using std::pair;

pair<int, shared_ptr<Player>> addPlayer(int k,const std::string& s1,const std::string& s2,const std::string& s3) {

    if (s2 == "Warrior") return pair<int, shared_ptr<Player>>(k, shared_ptr<Player>(new Warrior(s1, s3)));

    else if (s2 == "Sorcerer") { return pair<int, shared_ptr<Player>>(k, shared_ptr<Player>(new Sorcerer(s1, s3))); }

    else {
        throw InvalidPlayersFile();
    }
}


bool is_number(const std::string& str) {
    int size = str.size();
    // Check the rest of the characters to ensure they are digits
    for (int i = 1; i < size; ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
return true ;
}


std::queue<std::string> read_file_to_queue(const std::string& filename) {
    std::ifstream file(filename);
    std::queue<std::string> string_queue;

    if (!file.is_open()) {
        throw InvalidCardsFile(); // Return an empty queue
    }
    std::string line;
    // Read each line from the file
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        // Read each word from the line and push it to the queue
        while (iss >> word) {
            string_queue.push(word);
        }
    }
    file.close(); // Close the file
    return string_queue;
}


//bool to_deal_with_gang(std::queue<std::string>& queue, int k, Gang& gang_to_insert) {
//    if (k == 0 || queue.empty()) {
//        return true;
//    }
//
//    int size = (int) (queue.size());
//
//    if (size < k) {
//        return false;
//    }
//
//    if (queue.front() != "Goblin" && queue.front() != "Giant" && queue.front() != "Dragon" && queue.front() != "Gang") {
//        throw InvalidCardsFile();
//    }
//
//    if (queue.front() == "Goblin" || queue.front() == "Giant" || queue.front() == "Dragon") {
//        k--;
//        // Create appropriate entity and insert into gang
//        if (queue.front() == "Goblin") {
//            auto *goblin = new Goblin();
//            gang_to_insert.insertGangMember(goblin);
//            queue.pop();
//
//        } else if (queue.front() == "Giant") {
//            auto *giant = new Giant();
//            gang_to_insert.insertGangMember(giant);
//            queue.pop();
//
//        } else if (queue.front() == "Dragon") {
//            auto *dragon = new Dragon();
//            gang_to_insert.insertGangMember(dragon);
//            queue.pop();
//
//        }
//        return to_deal_with_gang(queue, k, gang_to_insert);
//    }
//
//    if (queue.front() == "Gang") {
//        queue.pop();
//        size = (int) (queue.size());
//        if (is_number(queue.front())) {
//            int gang_size = std::stoi(queue.front());
//            if (gang_size < 2 || size < gang_size) {
//                throw InvalidCardsFile();
//            } else {
//                queue.pop();
//                Gang *new_gang = new Gang;
//                k--;
//                if (to_deal_with_gang(queue, gang_size, *new_gang)) {
//                    gang_to_insert.insertGangMember(new_gang);
//                }
//            }
//        } else return false;
//    } else return false;
//    return to_deal_with_gang(queue, k, gang_to_insert);
//}
bool to_deal_with_gang(std::queue<std::string>& queue, int k, Gang& gang_to_insert) {
    if (k == 0 || queue.empty()) {
        return true;
    }

    int size = static_cast<int>(queue.size());

    if (size < k) {
        return false;
    }

    if (queue.front() != "Goblin" && queue.front() != "Giant" && queue.front() != "Dragon" && queue.front() != "Gang") {
        throw InvalidCardsFile();
    }

    if (queue.front() == "Goblin" || queue.front() == "Giant" || queue.front() == "Dragon") {
        k--;
        // Create appropriate entity and insert into gang
        if (queue.front() == "Goblin") {
            std::shared_ptr<Goblin> goblin = std::make_shared<Goblin>();
            gang_to_insert.insertGangMember(goblin.get());
            queue.pop();

        } else if (queue.front() == "Giant") {
            std::shared_ptr<Giant> giant = std::make_shared<Giant>();
            gang_to_insert.insertGangMember(giant.get());
            queue.pop();

        } else if (queue.front() == "Dragon") {
            std::shared_ptr<Dragon> dragon = std::make_shared<Dragon>();
            gang_to_insert.insertGangMember(dragon.get());
            queue.pop();
        }
        return to_deal_with_gang(queue, k, gang_to_insert);
    }

    if (queue.front() == "Gang") {
        queue.pop();
        size = static_cast<int>(queue.size());
        if (is_number(queue.front())) {
            int gang_size = std::stoi(queue.front());
            if (gang_size < 2 || size < gang_size) {
                throw InvalidCardsFile();
            } else {
                queue.pop();
//                std::unique_ptr<Gang> new_gang(new Gang);
                std::shared_ptr<Gang> new_gang = std::make_shared<Gang>();

                k--;
                if (to_deal_with_gang(queue, gang_size, *new_gang)) {
                    gang_to_insert.insertGangMember(new_gang.get());
                }
            }
        } else return false;
    } else return false;

    return to_deal_with_gang(queue, k, gang_to_insert);
}




/////////////////////////////////////////////////////////////////////////////////////////////
bool check_to_deal_with_gang(std::queue<std::string>& queue, int k) {
    if (k == 0 || queue.empty()) {
        return true;
    }

    int size = static_cast<int>(queue.size());

    if (size < k) {
        return false;
    }

    if (queue.front() != "Goblin" && queue.front() != "Giant" && queue.front() != "Dragon" && queue.front() != "Gang") {
        throw InvalidCardsFile();
    }

    if (queue.front() == "Goblin" || queue.front() == "Giant" || queue.front() == "Dragon") {
        k--;
        // Create appropriate entity and insert into gang
        if (queue.front() == "Goblin") {
            queue.pop();

        } else if (queue.front() == "Giant") {
            queue.pop();

        } else if (queue.front() == "Dragon") {
            queue.pop();
        }
        return check_to_deal_with_gang(queue, k);
    }

    if (queue.front() == "Gang") {
        queue.pop();
        size = static_cast<int>(queue.size());
        if (is_number(queue.front())) {
            int gang_size = std::stoi(queue.front());
            if (gang_size < 2 || size < gang_size) {
                throw InvalidCardsFile();
            } else {
                queue.pop();
//                std::unique_ptr<Gang> new_gang(new Gang);

                k--;
                if (check_to_deal_with_gang(queue, gang_size)) {
                }
            }
        } else return false;
    } else return false;

    return check_to_deal_with_gang(queue, k);
}
//std::queue <std::shared_ptr<Card>>  check_and_put_cards(std::queue<std::string> temp_queue) {
//
// std::queue<std::shared_ptr<Card>> cards;
//       while (!temp_queue.empty() ) {
//            if (temp_queue.front() == "Dragon") {
//                cards.push(make_shared<Dragon>());
//                temp_queue.pop();
//        }
// else if (temp_queue.front() == "PotionsMerchant") {
//                cards.push(make_shared<PotionMerchant>());
//                temp_queue.pop();
//  }
//        else if (temp_queue.front() == "SolarEclipse") {
//                cards.push(make_shared<SolarEclipse>());
//                temp_queue.pop();
//        }
//
//        else if(temp_queue.front() == "Giant"){
//                cards.push(make_shared<Giant>());
//                temp_queue.pop();
//       }
//        else if (temp_queue.front() == "Goblin") {
//                cards.push(make_shared<Goblin>());
//                temp_queue.pop();
//        }
//         else if(temp_queue.front()=="Gang") {
//                temp_queue.pop();
//                if (is_number(temp_queue.front())) {
//                    int k = stoi(temp_queue.front());
//                    if (k >= 2) {
//                        temp_queue.pop();
//                        std::shared_ptr<Gang> gang = std::make_shared<Gang>();
//                        if(to_deal_with_gang(temp_queue, k,*gang)) {
//                            cards.push(make_shared<Gang>(*gang));
//                        }else throw InvalidCardsFile();
//                    } else throw InvalidCardsFile();
//                } else throw InvalidCardsFile();
//            } else throw InvalidCardsFile();
//   }
//       return cards;
//}

bool checkCards(std::queue<std::string> temp_queue) {
    while (!temp_queue.empty()) {
        if (temp_queue.front() == "Dragon") {
            temp_queue.pop();
        } else if (temp_queue.front() == "PotionsMerchant") {
            temp_queue.pop();
        } else if (temp_queue.front() == "SolarEclipse") {
            temp_queue.pop();
        } else if (temp_queue.front() == "Giant") {
            temp_queue.pop();
        } else if (temp_queue.front() == "Goblin") {
            temp_queue.pop();
        } else if (temp_queue.front() == "Gang") {
            temp_queue.pop();
            if (is_number(temp_queue.front())) {
                int k = std::stoi(temp_queue.front());
                if (k >= 2) {
                    temp_queue.pop();
                    if (check_to_deal_with_gang(temp_queue, k)) {
                    } else {
                        throw InvalidCardsFile();
                    }
                } else {
                    throw InvalidCardsFile();
                }
            } else {
                throw InvalidCardsFile();
            }
        } else {
            throw InvalidCardsFile();
        }
    }
    return true;
}
std::queue<std::shared_ptr<Card>> check_and_put_cards(std::queue<std::string> temp_queue) {
    std::queue<std::shared_ptr<Card>> cards;
    while (!temp_queue.empty()) {
        if (temp_queue.front() == "Dragon") {
            cards.push(std::make_shared<Dragon>());
            temp_queue.pop();
        } else if (temp_queue.front() == "PotionsMerchant") {
            cards.push(std::make_shared<PotionMerchant>());
            temp_queue.pop();
        } else if (temp_queue.front() == "SolarEclipse") {
            cards.push(std::make_shared<SolarEclipse>());
            temp_queue.pop();
        } else if (temp_queue.front() == "Giant") {
            cards.push(std::make_shared<Giant>());
            temp_queue.pop();
        } else if (temp_queue.front() == "Goblin") {
            cards.push(std::make_shared<Goblin>());
            temp_queue.pop();
        } else if (temp_queue.front() == "Gang") {
            temp_queue.pop();
            if (is_number(temp_queue.front())) {
                int k = std::stoi(temp_queue.front());
                if (k >= 2) {
                    temp_queue.pop();
                    std::shared_ptr<Gang> new_gang = std::make_shared<Gang>();
                    if (to_deal_with_gang(temp_queue, k, *new_gang)) {
                        cards.push(new_gang);
                    } else {
                        throw InvalidCardsFile();
                    }
                } else {
                    throw InvalidCardsFile();
                }
            } else {
                throw InvalidCardsFile();
            }
        } else {
            throw InvalidCardsFile();
        }
    }
    return cards;
}
using std::string;

Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {
    /*===== TODO: Open and read cards file =====*/
    std::ifstream deckFile(deckPath);
    try {
        deckFile.is_open();
    } catch (...) {
        throw InvalidCardsFile();
    }
    std::string card;
    std::queue<std::string> temp_queue;
    using std::istringstream;
    std::string line;

    while (std::getline(deckFile, line)) {
        std::istringstream iss(line);
        while (iss >> card) {
            temp_queue.push(card);
        }
    }
if(temp_queue.size() <2) {
    throw InvalidCardsFile();
}
    std::queue<std::string> queue=temp_queue;
if(checkCards(temp_queue))
{m_cards=check_and_put_cards(queue);}

    deckFile.close();
    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/


    std::ifstream PlayersFile(playersPath);
    try {
        PlayersFile.is_open();
    } catch (...) {
        throw InvalidPlayersFile();
    }
    int k = 0;
        // Extract the three strings
    std::string playersline;
    while(k != 7 && std::getline(PlayersFile,playersline) ) {
          std::istringstream iss(playersline);
             int num=0;
              std::string word;
        std::string firstString, secondString, thirdString;

            while(iss>>word) {
                if(num==0) firstString=word;
                if(num==1) secondString=word;
                if(num==2) thirdString=word;
                num++;
            }
            if(num != 3 ) {
//                std::cout <<num<< word;
                throw InvalidPlayersFile();
            }

            if (isValidPlayerInput(firstString, secondString, thirdString)) {
                k++;
                m_players.insert(addPlayer(k, firstString, secondString, thirdString));
            } else { throw InvalidPlayersFile(); }
        }
        /*============================================*/
        tot_num_players=(int)(m_players.size());
        if(tot_num_players < 2 || tot_num_players > 6) { throw InvalidPlayersFile();}
        this->m_turnIndex = 1;

}

void Mtmchkin::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Draw a card from the deck
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the card
     * 4. Print the turn outcome with "printTurnOutcome"
    */
    shared_ptr<Card> cardToPlay = m_cards.front();

    m_cards.pop();
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
                player.damage(giantCard -> getDamage());
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

        //used auto instead of auto*:
        auto warriorPlayer = dynamic_cast<Warrior*>(&player);
        auto sorcererPlayer = dynamic_cast<Sorcerer*>(&player);

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
            if(player.getBehavior() == "RiskTaking" && player.getHealthPoints() < 50 && player.pay(POTION_COST))
            {
                player.heal(POTION_HEAL);
                potionsBought++;
            }
                //PLAYER IS RESPONSIBLE:
            else if(player.getBehavior() == "Responsible" && player.getHealthPoints() < player.getMaxHealthPoints())
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
    m_cards.push(cardToPlay);
    sort_Board();
}


void Mtmchkin::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    for (auto it = m_players.begin(); it != m_players.end(); it++){
        if (std::find(m_finished.begin(), m_finished.end(), it -> second) != m_finished.end()) {
            continue;
        }
        auto& curPlayer = it->second;
            playTurn(*curPlayer);
        //PLAYER DEAD/WON, MOVE TO FINISHED BRACKET:
        if (curPlayer->getLevel() == MAX_LEVEL) {
            m_numOfWinners++;
            m_finished.push_back(curPlayer);
        } else if (curPlayer->isKnockedOut()) {
            m_numOfLosers++;
            m_finished.push_back(curPlayer);
        }
    }
    printRoundEnd();
}

    bool Mtmchkin::isGameOver() const {
        /*===== TODO: Implement the game over condition =====*/

        if(m_numOfWinners > 0 || m_numOfLosers == tot_num_players)
        {
            return true;
        }
        return false; // Replace this line
        /*===================================================*/
    }
void Mtmchkin::sort_Board() {
    std::sort(m_leaderboard.begin(), m_leaderboard.end(), [](const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2) {
        if (p1->getLevel() != p2->getLevel()) {
            return p1->getLevel() > p2->getLevel(); // Sort by level in descending order
        } else if (p1->getCoins() != p2->getCoins()) {
            return p1->getCoins() > p2->getCoins(); // Sort by coins in descending order
        } else {
            return p1->getName() < p2->getName(); // Sort by name in ascending order
        }
    });
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
            set_in_LeaderBoard();
            sort_Board();
            while (!isGameOver()) {
                playRound();
                    printLeaderBoardMessage();
                    int i=1 ;
                sort_Board();
                    for(auto& player: m_leaderboard) {
                        printLeaderBoardEntry(i,*player);
                        i++;
                    }
                printBarrier();
            }

            printGameOver();
            /*===== TODO: Print either a "winner" message or "no winner" message =====*/
            if(m_numOfWinners > 0)
            {
                if (!m_leaderboard.empty()) {
                    const shared_ptr<Player>& winner = m_leaderboard[0];
                    printWinner(*winner);
                }
            }
            else
            {
                printNoWinners();
            }

    }

