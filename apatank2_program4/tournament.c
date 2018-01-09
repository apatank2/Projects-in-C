#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "tournament.h"
void deleteTeam(Team * t1)
{
free(t1->players);
free(t1);
}

Player * draftPlayers(char * filename, int team, int num_players)
{
  Player *p = malloc(sizeof(Player) * 32);
  char *p1;
  char singleline[150];
  int ins_line_cnt = 0;
  int no_of_players=0;
  int team_no;
  FILE * fpointer;
  fpointer = fopen(filename,"r");
  for (;;)
            {

                fgets(singleline,150,fpointer);
                p1 = strtok (singleline,",:");
                 while (p1!= NULL)
  {
    ins_line_cnt = ins_line_cnt + 1;
    if (ins_line_cnt == 1)
             {
                 team_no = atoi(p1);
                 if (team_no  == team)
                 {
                    p[no_of_players].team = team;
                 }
             }
             if (ins_line_cnt == 2)
             {
                 if (team_no == team)
                 {
	        p[no_of_players].first = p1;
                 }
             }
             if (ins_line_cnt == 3)
             {
                 if (team_no == team)
                 {
                   p[no_of_players].last = p1;
                  }
             }
             if (ins_line_cnt == 4)
             {
                 if (team_no == team)
                 {
                   p[no_of_players].number = atoi(p1);
                 }
             }
             if (ins_line_cnt == 5)
             {
                 if (team_no == team)
                 {
                    p[no_of_players].offensive = atoi(p1);
                 }
             }
             if (ins_line_cnt == 6)
             {
                 if (team_no == team)
                 {
                     p[no_of_players].defensive = atoi(p1);
                     no_of_players = no_of_players + 1;
                 }
 	         ins_line_cnt = 0;
             }
             p1 = strtok (NULL, ",:");
 	 }
                if (feof( fpointer )) break;



            }
            fclose(fpointer);

     return p;

}

Team * initializeTeam(char * name, Player * players)
{
	Team *t = malloc(sizeof(Team));	
	t->name = name;
	t->players = players;
	return t;
}

Team * game(Team * t1, Team * t2)
{
   if ( t1 == NULL && t2 == NULL)
   {
   return NULL;
   };
   
   int z=0;
   int team1_def = 0;
   int team1_off = 0;
   int team2_def = 0;
   int team2_off = 0;
   int team1_score = 0;
   int team2_score = 0;
   int team1_attack = 0;
   int team2_attack = 0;
   int team1_defense = 0;
   int team2_defense = 0;
   for (;z<10;z++)
   {
   team1_def = team1_def + t1->players[z].defensive;
   team1_off = team1_off + t1->players[z].offensive;
   team2_def = team2_def + t2->players[z].defensive;
   team2_off = team2_off + t2->players[z].offensive;
   };
   z = 0;
   for (;z<10;z++)
   {
   team1_attack = rand()%team1_off;
   team2_attack = rand()%team2_off;
   team1_defense = rand()%team1_def;
   team2_defense = rand()%team2_def;
   if (team2_attack > team1_defense)
   {
   team2_score = team2_score + 1;
   };
   if (team1_attack > team2_defense)
   {
   team1_score = team1_score + 1;
   };
   };
   if (team1_score >  team2_score)
   {
   return t1;
   }
   else if (team2_score > team1_score)
   {
   return t2;
   }
   else if (team1_score == team2_score)
   {
   if ((team1_def + team1_off) > (team2_def  + team2_off))
   {
   return t1;
   }
   else
   {
   return t2;
   }
   }
};

Team * tournament(Team **leag, int no_of_teams)
{  
    int j = 0;
    int n = no_of_teams;
    int flag = 0;
    int team_cnt = no_of_teams;
    int team_cnt1 = no_of_teams-1;
    Team *grpwinner = NULL;  // printf("\n No.of Teams are : %d \n",no_of_teams);
    Team *q1 = NULL;
    Team *q2 = NULL;
    Team *q3 = NULL;
    Team *q4 = NULL;
    Team *q5 = NULL;
    Team *q6 = NULL;
    Team *q7 = NULL;
    while(n>1)
    {
    if(n%2!=0)
    {
    flag=1;
    break;
    }
    n=n/2;
    }
    if(flag==1)
    {
    printf("Team is not a Power of 2");
    return NULL;
    }
    int val;
    if  (team_cnt  >= 8)
    {
    val = team_cnt / 8;
    }
  // printf("\n No.of Teams are : %d \n",val);
   if (team_cnt == 2)
   {
    q1 =  game(leag[0], leag[1]);
    return q1;
   }
   if (team_cnt == 4)
   {
    q1 =  game(leag[0], leag[1]);
    q2 =  game(leag[2], leag[3]);
    q3 =  game(q1,q2);
    return q3;
   }
   if (team_cnt >= 8)
   {
   for (;j<val;j++)
    {
        if (j==0)
        {
            team_cnt = team_cnt - 1;
            q1 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
            team_cnt = team_cnt - 1;
	    q2 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
	    team_cnt = team_cnt -1;
	    q3 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
	    team_cnt = team_cnt -1;
            q4 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
            q5 = game(q1,q2);
            q6 = game(q3,q4);
             grpwinner = game(q5,q6);
           // return grpwinner;


        }
        if (j > 0)
        {
            team_cnt = team_cnt - 1;
            q1 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
            team_cnt = team_cnt - 1;
            q2 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
            team_cnt = team_cnt -1;
            q3 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
            team_cnt = team_cnt -1;
            q4 =  game(leag[team_cnt1-team_cnt], leag[team_cnt]);
            q5 = game(q1,q2);
            q6 = game(q3,q4);
            q7 = game(q5,q6);
	         grpwinner = game(q7,grpwinner);
          // return grpwinner;

        }


    }
   // return grpwinner;
    }
    return grpwinner;
}
