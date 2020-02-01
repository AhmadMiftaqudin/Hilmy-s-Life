#include "robot.h"
#include "utils.h"
#include <stdlib.h>

Robot initRobot(){
    Robot r;
    r.money = 50;
    r.social = 0;

    int constant1 = random(25,42);
    int constant2 = random(20,40);
    int bonus = random(1,12);
    int bonus2 = random(1,13);

    r.happiness = constant1+25-bonus;
    r.hygiene = 50-constant1+bonus;
    r.hunger = constant2+25-bonus2;
    r.health = 50-constant2+bonus2;

    r.deathCause = "";
    r.isDead = false;
    return r;
}

bool doAct(Robot *r, Activity *a){
    if(a->money < 0 && r->money < abs(a->money)){
        return false;
    }
    r->money += a->money;
    r->happiness += a->happiness;
    r->hygiene += a->hygiene;
    r->social += a->social;
    r->hunger += a->hunger;
    r->health += a->health;

    if (r->happiness < 0){
        r->isDead = true;
        r->deathCause = "Unhappy";
    }
    if (r->hygiene < 0){
        r->isDead = true;
        r->deathCause = "Unhygienic";
    }
    if (r->hunger < 0){
        r->isDead = true;
        r->deathCause = "Starvation";
    }
    if(r->health < 0){
        r->isDead = true;
        r->deathCause = "Death";
    }

    r->happiness = (r->happiness > 100) ? 100 : r->happiness;
    r->hygiene = (r->hygiene > 100) ? 100 : r->hygiene;
    r->hunger = (r->hunger > 100) ? 100 : r->hunger;
    r->health = (r->health > 100) ? 100 : r->health;

    return true;
}

void showStatus(Robot r){
    int i;
    for(i=0;i<70;i++){
        printf("-");
    }
    printf("\nHilmy's Status");
    printf("\nSocial Point\t: %d", r.social);
    printf("\nMoney\t\t: $%d\n", r.money);

    printf("\nHappiness\t: ");
    bar(r.happiness,100);
    printf(" %d/100", r.happiness);

    printf("\nHygiene\t\t: ");
    bar(r.hygiene,100);
    printf(" %d/100", r.hygiene);

    printf("\nHunger\t\t: ");
    bar(r.hunger,100);
    printf(" %d/100", r.hunger);

    printf("\nHealth\t\t: ");
    bar(r.health,100);
    printf(" %d/100\n", r.health);

    for(i=0;i<70;i++){
        printf("-");
    }
    return;
}