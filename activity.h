#ifndef _ACTIVITY_H_
#define _ACTIVITY_H_

#include <stdio.h>

typedef struct{
    int happiness;
    int money;
    int hygiene;
    int hunger;
    int social;
    int health;
    char * name;
} Activity;

Activity createActivity(char * name, int happiness, int money, int hygiene, int hunger, int social, int health);

void modifyActivity(Activity *act, float costMult, float bonusMult);
void printActivity(Activity act);
#endif