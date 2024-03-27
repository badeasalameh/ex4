#include "Mtmchkin.h"
using std::pair;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PLAYERS INPUT:
bool isCapital(std::string str) {
    if(str[0]<='A' && str[0] <='Z')
        return true ;
    return false ;
}

//CHECK NUMBER OF PLAYERS (BETWEEN 2 AND 6):
bool isValidPlayersNum(std::ifstream& PlayersFile) {
    int lines_counter = 0;
    std::string line;
    while (std::getline(PlayersFile, line)) {
        lines_counter++;
    }
    return (lines_counter >= 2 && lines_counter <= 6);
}

//CHECK PLAYER FILE VALIDITY:
bool isValidPlayerInput(const std::string& firstString, const std::string& secondString, const std::string& thirdString) {
    const int MIN_NAME_LENGTH = 3;
    const int MAX_NAME_LENGTH = 15;
    const std::string VALID_JOBS[] = {"Warrior", "Sorcerer"};
    const std::string VALID_BEHAVIORS[] = {"Risktaking", "Responsible"};

    if (firstString.length() >= MIN_NAME_LENGTH && firstString.length() <= MAX_NAME_LENGTH &&
        isCapital(firstString) &&
        (secondString == VALID_JOBS[0] || secondString == VALID_JOBS[1]) &&
        (thirdString == VALID_BEHAVIORS[0] || thirdString == VALID_BEHAVIORS[1])) {
        return true;
    }
    return false;
}

//ADD PLAYERS TO M_PLAYERS:
pair<int, shared_ptr<Player>> addPlayer(int k,const std::string& s1,const std::string& s2,const std::string& s3) {
    if(s2=="Warrior") { return pair<int, shared_ptr<Player>>(k, shared_ptr<Player>(new Warrior(s1, s3)));}
    else if(s2=="Sorcerer") {return pair<int, shared_ptr<Player>>(k, shared_ptr<Player>(new Sorcerer(s1, s3)));}
    else {
        throw InvalidPlayersFile();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CARDS INPUT:
/*
bool is_number(const std::string& str) {
    // Check the rest of the characters to ensure they are digits
    for (int i = 1; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true ;
}

std::queue<std::string> read_file_to_queue(const std::string& filename) {
    std::ifstream file(filename);
    std::queue<std::string> string_queue;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return string_queue; // Return an empty queue
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
    std::queue<std::string> temp_queue = string_queue;
    return temp_queue;
}


bool to_deal_with_gang(std::queue<std::string> queue,int k,Gang **gang_to_insert) {
    if (k == 0) {
        return true;
    }

    if (queue.front() == "Goblin") {
        Goblin* goblin;
        *(gang_to_insert)->insertGangMember(goblin);

    }

    if (queue.front() == "Giant") {
        Giant *giant;
        gang_to_insert.insertGangMember(giant);

    }

    if (queue.front() == "Dragon") {
        Dragon *dragon;
        gang_to_insert.insertGangMember(dragon);

    }

    if (queue.front() == "Gang") {
        Gang* new_gang;
        queue.pop();
        if (is_number(queue.front())) {
            if (queue.size() < stoi(queue.front()) || stoi(queue.front()) < 2) {
                throw "Invalid Cards File";
            } else {
                queue.pop(); ///
                gang_to_insert.insertGangMember(new_gang);
                to_deal_with_gang(queue,stoi(queue.front()),&new_gang);

            }
        } else return false;
    }
}




std::queue<std::unique_ptr<Card>> check_and_put_cards(std::queue<std::string> temp_queue) {
    std::queue<std::unique_ptr<Card>> cards;
    while (!temp_queue.empty() ) {
        if (temp_queue.front() == "Dragon") {
            cards.push(make_unique<Dragon>());
            temp_queue.pop();
        }
        else if (temp_queue.front() == "PotionMerchant") {
            cards.push(make_unique<PotionMerchant>());
            temp_queue.pop();
        }
        else if (temp_queue.front() == "SolarEclipse") {
            cards.push(make_unique<SolarEclipse>());
            temp_queue.pop();
        }

        else if(temp_queue.front() == "Giant"){
            cards.push(make_unique<Giant>());
            temp_queue.pop();
        }
        else if (temp_queue.front() == "Goblin") {

            cards.push(make_unique<Goblin>());
            temp_queue.pop();
        }
        else if(temp_queue.front()=="Gang") {
            temp_queue.pop();
            if (is_number(temp_queue.front())) {
                int k = stoi(temp_queue.front());
                if (k >= 2) {
                    temp_queue.pop();
                    Gang gang_to_insert;
                    to_deal_with_gang(temp_queue, k,gang_to_insert);
                } else throw "Invalid Crads File";
            } else throw "Invalid Crads File";
        } else throw "Invalid Cards File";
    }

}
*/
/*CARD INPUT FILE PLAN:
 * turn the input file into queue of strings (without spaces). {DONE}
 * create checker functions (names , spaces , lengths....). {DONE}
 * create a function that makes a card, and inserts it into the m_cards. {DONE}
 * create a separate function that takes care of gang instances.
 */
/////////////////////////////////////////////////////////////
//TURN INTO QUEUE:
queue<string> turnFileIntoQueue (std::ifstream cardInputFile)
{
    string word;
    queue<string> queueToReturn;

    while(cardInputFile >> word)
    {
        queueToReturn.push(word);
    }
    return queueToReturn;
}
/////////////////////////////////////////////////////
//CHECKERS:
bool checkIfNumber(const string& stringToCheck)
{
    for(int i = 0 ; i < stringToCheck.size() ; i++)
    {
        if(!isdigit(stringToCheck[i]))
        {
            return false;
        }
    }
    return true;
}

bool checkCardInputWithoutGang(const queue<string>& FileToCheck)
{
    queue<string> tempQueue = FileToCheck;
    while (!tempQueue.empty())
    {
        string wordToCheck = tempQueue.front();
        tempQueue.pop();

        if (wordToCheck != "Gang" && wordToCheck != "Dragon" && wordToCheck != "Giant" && wordToCheck != "Goblin" && !checkIfNumber(wordToCheck))
        {
            throw InvalidCardsFile();
        }
    }
    return true;
}
bool checkCardInputGang(const queue<string>& FileToCheck)
{
    queue<string> tempQueue = FileToCheck;
    while(!tempQueue.empty())
    {
        string gangToCheck = tempQueue.front();
        if(gangToCheck != "Gang")
        {
            tempQueue.pop();
            if(checkIfNumber(tempQueue.front()))
            {
                throw InvalidCardsFile();
            }
            continue;
        }
        else if(gangToCheck == "Gang")
        {
            tempQueue.pop();
            if(!checkIfNumber(tempQueue.front()) || (checkIfNumber(tempQueue.front()) && stoi(tempQueue.front()) < 2))
            {
                throw InvalidCardsFile();
            }
            else
            {
                int supposedNumberOfGangMembers = stoi(tempQueue.front());
                int actualNumberOfGangMembers = 0;
                tempQueue.pop();

                for(int i = 0 ; i < supposedNumberOfGangMembers ; i++)
                {
                    if(tempQueue.front() != "Gang")
                    {
                        actualNumberOfGangMembers++;
                        tempQueue.pop();
                        continue;
                    }
                    else
                    {
                        actualNumberOfGangMembers++;
                        if(!checkCardInputGang(tempQueue))
                        {
                            throw InvalidCardsFile();
                        }
                    }
                }

                if(actualNumberOfGangMembers == supposedNumberOfGangMembers)
                {
                    return true;
                }
                throw InvalidCardsFile();
            }
        }
    }
    throw InvalidCardsFile();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CREATOR FUNCTIONS:
void createAndInsertCardWithoutGang(queue<string> queue , std::queue<shared_ptr<Card>> m_cards)
{
    while(!queue.empty())
    {
        string cardToCreate = queue.front();
        if (cardToCreate == "Gang")
        {
            queue.pop();
            continue;
        }
        else if(cardToCreate == "Dragon")
        {
            m_cards.push(make_unique<Dragon>());
            queue.pop();
            continue;
        }
        else if(cardToCreate == "Goblin")
        {
            m_cards.push(make_unique<Goblin>());
            queue.pop();
            continue;
        }
        else if(cardToCreate == "Giant")
        {
            m_cards.push(make_unique<Giant>());
            queue.pop();
            continue;
        }
    }
}
void createAndInsertCardGang(queue<string> queue , std::queue<shared_ptr<Card>> m_cards)
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Mtmchkin::Mtmchkin(const string& deckPath, const string& playersPath) {

    //===== TODO: Open and read cards file =====/
    std::ifstream deckFile(deckPath);
    try {
        deckFile.is_open();
    } catch (const std::runtime_error& e) {
        throw e;
    }

    std::string cardLine;

//    std::queue<std::string> q1 Is_Valid_Card_Input(deckFile);
    deckFile.close();
    //==========================================/


    //===== TODO: Open and Read players file =====/


    std::ifstream PlayersFile(playersPath);
    std::string Playersline;
    try {
        PlayersFile.is_open();
    } catch (...) {
        throw "Invalid Players File";
    }
    int k = 1;

    while (std::getline(PlayersFile, Playersline)&& k!=7) {
        std::istringstream iss(playersPath);
        std::string firstString, secondString, thirdString;

        // Extract the three strings
        if ((iss >> firstString >> secondString >> thirdString) &&
            isValidPlayerInput(firstString, secondString, thirdString)) {
            m_players.insert(addPlayer(k,firstString,secondString,thirdString));
            k++;
        } else throw "Invalid Players File";
    }
    //============================================/
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
                if(player.getBehavior() == "RiskTaking" && player.getHealthPoints() < 50 && player.pay(POTION_COST))
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
        m_cards.push(cardToPlay);
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
