/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include "Football.h"

// -------------- Team --------------------

Team::Team(const string& name): teamName(name) {
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
    return ASSISTS_POINT * assists;
}

string Player::print() const {
    // IMPLEMENT ME
    // below are just stub code
    string removeMe = "";
    return removeMe;
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

// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t): Player(name, t) {

}

Attacker::~Attacker() {
    // IMPLEMENT ME
}

int Attacker::getScore() const {
//    int genericScore = Player::getScore();
    int genericScore = 0;
    genericScore += GOAL_POINT * getGoalsScored();
    return genericScore;
}

string Attacker::print() const {
    // IMPLEMENT ME
    // below are just stub code
    string removeMe = "";
    return removeMe;
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t) {
    Player(name, t);
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
    // IMPLEMENT ME
    // below are just stub code
    string removeMe = "";
    return removeMe;
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t) {
    Player(name, t);
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
    // IMPLEMENT ME
    // below are just stub code
    string removeMe = "";
    return removeMe;
}

// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t) {
    Player(name, t);
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
    // IMPLEMENT ME
    // below are just stub code
    string removeMe = "";
    return removeMe;
}

// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
    // IMPLEMENT ME
}

FantasyTeam::~FantasyTeam() {
    // IMPLEMENT ME
}

bool FantasyTeam::addPlayer(Player* p) {
    // IMPLEMENT ME
    // below are just stub code
    bool removeMe = true;
    return removeMe;
}

int FantasyTeam::getScore() const {
    // IMPLEMENT ME
    // below are just stub code
    int removeMe = 0;
    return removeMe;
}