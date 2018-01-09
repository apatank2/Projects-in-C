#ifndef TOURNAMENT_H
#define TOURNAMENT_H
//#include "tournament.c"
typedef struct Player
{
    char *first;
    char *last;
    int team;
    int number;
    int defensive;
    int offensive;
} Player;

typedef struct Team
{
    char *name;
    Player *players;
} Team;

void deleteTeam(Team *t1);
Player * draftPlayers(char * filename, int team, int num_players);
Team * initializeTeam(char * name, Player * players);
Team * game (Team * t1, Team * t2);
Team * tournament(Team **leag,int no_of_teams);

#endif 
