/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include <iostream>
#include "Football.h"

// -------------- Team --------------------

Team::Team(const string& name): teamName(name) {
    goalsConceded = 0;
}

void Team::addGoalsConceded(int g) {
    goalsConceded = g;
}

Team::~Team() {
    // IMPLEMENT ME
}

string Team::getTeamName() {
    return teamName;
}

int Team::getGoalsConceded() {
    return goalsConceded;
}


// -------------- Player ------------------

Player::Player() {
    // see comment in .h
}

Player::Player(const string& name, Team* t) {
    this -> name = name;
    team = t;
    goalsScored = 0;
    assists = 0;
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {
    // IMPLEMENT ME
}

void Player::addGoalsScored(int g) {
    goalsScored += g;
}

void Player::addAssists(int a) {
    assists += a;
}

int Player::getScore() const {
    //assists
    cout<< "constructor called"<<endl;
    return ASSISTS_POINT * assists;
}

string Player::print() const {
    string s = ": ";
    s += getName();
    s +=  ", Team: ";
    s +=  getTeam()->getTeamName();
    s +=  "\n";
    s += " Goals scored: ";
    s += to_string(getGoalsScored());
    s += "\n";
    s += " Assists: ";
    s += to_string(getAssists());
    s += "\n";
    s += " Goals conceded: ";
    s += to_string(getTeam()->getGoalsConceded());
    s += "\n";

    return s;
}

int Player::getGoalsScored() const {
    return goalsScored;
}

Team * Player::getTeam() const {
    return team;
}

string Player::getName() const {
    return name;
}

int Player::getAssists() const {
    return assists;
}

// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t): Player(name, t) {

}

Attacker::~Attacker() {
    // IMPLEMENT ME
}

int Attacker::getScore() const {
    int genericScore = Player::getScore();
    genericScore += GOAL_POINT * getGoalsScored();
    return genericScore;
}

string Attacker::print() const {
    string toReturn = "Attacker";
    toReturn += Player::print();
    toReturn += " Score: ";
    toReturn += to_string(getScore());
    return toReturn;
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t): Player(name, t)  {
}

Midfielder::~Midfielder() {
    // IMPLEMENT ME
}

int Midfielder::getScore() const {
    int genericScore = Player::getScore();
    //goals points
    genericScore += GOAL_POINT * getGoalsScored();

    //conceded points
    genericScore += (Player::getTeam()->getGoalsConceded() == 0) ? NO_GOALS_CONCEDED_POINT : 0;

    return genericScore;
}

string Midfielder::print() const {
    string toReturn = "Midfielder";
    toReturn += Player::print();
    toReturn += " Score: ";
    toReturn += to_string(getScore());
    return toReturn;
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t): Player(name, t)  {
}

Defender::~Defender() {
    // IMPLEMENT ME
}

int Defender::getScore() const {
    int genericScore = Player::getScore();

    //goal points
    genericScore += GOAL_POINT * getGoalsScored();

    //conceded points
    genericScore += (Player::getTeam()->getGoalsConceded() == 0) ? NO_GOALS_CONCEDED_POINT : 0;

    //reduce points based on goals
    genericScore -= ((Player::getTeam()->getGoalsConceded() / 2) * REDUCTION_EVERY_2_GOALS_CONCEDED_BY_THEIR_TEAM);

    return genericScore;

}

string Defender::print() const {
    string toReturn = "Defender";
    toReturn += Player::print();
    toReturn += " Score: ";
    toReturn += to_string(getScore());
    return toReturn;
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t): Player(name, t)  {
    shotsSaved = 0;
}

Goalkeeper::~Goalkeeper() {
    // IMPLEMENT ME
}

void Goalkeeper::addShotsSaved(int ss) {
    shotsSaved += ss;
}

int Goalkeeper::getScore() const {
    int genericScore = Player::getScore();
    //goal points
    genericScore += GOAL_POINT * getGoalsScored();

    //conceded points
    genericScore += (Player::getTeam()->getGoalsConceded() == 0) ? NO_GOALS_CONCEDED_POINT : 0;

    //reduce points based on goals
    genericScore -= ((Player::getTeam()->getGoalsConceded() / 2) * REDUCTION_EVERY_2_GOALS_CONCEDED_BY_THEIR_TEAM);

    //points for every 3 shots the keeper saved
    genericScore += (shotsSaved / 3) * EVERY_3_SHOTS_SAVED;

    return genericScore;

}

string Goalkeeper::print() const {
    string toReturn = "Goalkeeper";
    toReturn += Player::print();
    toReturn += " Shots saved: ";
    toReturn += to_string(shotsSaved);
    toReturn += "\n";
    toReturn += " Score: ";
    toReturn += to_string(getScore());
    return toReturn;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
    *players = new Player[11];
    for(int i = 0; i < 11; i++){
        players[i] = nullptr;
    }
    size = 0;
}

FantasyTeam::~FantasyTeam() {
    // IMPLEMENT ME
}

bool FantasyTeam::addPlayer(Player* p) {

    if(!checkIfPlayerIsAdded(p) && size < 11) {
        //add player
        players[size] = p;
        size++;
        return true;
    }

    return false;
}

int FantasyTeam::getScore() const {
    int totalScore = 0;
    for(int i = 0; i <= size; i++){
        if(players[i] != nullptr){
            totalScore += players[i]->getScore();
        }
    }
    return totalScore;
}

bool FantasyTeam::checkIfPlayerIsAdded(Player *p) {
    for(int i = 0; i <= size; i++){
        if(players[i] == p){
            return true;
        }
    }
    return  false;
}