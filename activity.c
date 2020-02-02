#include "activity.h"
#include <math.h>
#include <string.h>

Activity createActivity(char * name, int happiness, int money, int hygiene, int hunger, int social, int health){
    Activity act;
    act.name = name;
    act.happiness = happiness;
    act.money = money;
    act.hygiene = hygiene;
    act.hunger = hunger;
    act.social = social;
    act.health = health;
    return act;
}

void modifyActivity(Activity *act, float costMult, float bonusMult){
    if(act->happiness > 0) act->happiness = (int) ceil(bonusMult*act->happiness);
    if(act->money > 0) act->money = (int) ceil(bonusMult*act->money);
    if(act->hygiene > 0) act->hygiene = (int) ceil(bonusMult*act->hygiene);
    if(act->hunger > 0) act->hunger = (int) ceil(bonusMult*act->hunger);
    if(act->social > 0) act->social = (int) ceil(bonusMult*act->social);
    if(act->health > 0) act->health = (int) ceil(bonusMult*act->health);

    if(act->happiness < 0) act->happiness = (int) floor(costMult*act->happiness);
    if(act->money < 0) act->money = (int) floor(costMult*act->money);
    if(act->hygiene < 0) act->hygiene = (int) floor(costMult*act->hygiene);
    if(act->hunger < 0) act->hunger = (int) floor(costMult*act->hunger);
    if(act->social < 0) act->social = (int) floor(costMult*act->social);
    if(act->health < 0) act->health = (int) floor(costMult*act->health);
    return;
}

void printActivity(Activity act){
    if(strlen(act.name) > 10){printf("%s\t[ ", act.name);}
    else {printf("%s\t\t[ ", act.name);}

    if(act.money > 0) printf("+%d$ ", act.money);
    if(act.money < 0) printf("%d$ ", act.money);

    if(act.happiness > 0) printf("+%d Happiness ", act.happiness);
    if(act.happiness < 0) printf("%d Happiness ", act.happiness);

    if(act.hygiene > 0) printf("+%d Hygiene ", act.hygiene);
    if(act.hygiene < 0) printf("%d Hygiene ", act.hygiene);

    if(act.hunger > 0) printf("+%d Hunger ", act.hunger);
    if(act.hunger < 0) printf("%d Hunger ", act.hunger);

    if(act.social > 0) printf("+%d Social ", act.social);
    if(act.social < 0) printf("%d Social ", act.social);

    if(act.health > 0) printf("+%d Health ", act.health);
    if(act.health < 0) printf("%d Health ", act.health);
    printf("]");
}