#include "robot.h"
#include "utils.h"
#include "event.h"
#include <stdlib.h>
#include <stdbool.h>

Robot initRobot(){
    Robot r;
    r.money = 50;
    r.social = 0;

    int constant1 = random(10,15);
    int constant2 = random(12,17);
    int bonus = random(1,12);
    int bonus2 = random(1,13);

    r.happiness = constant1+25-bonus;
    r.hygiene = 25-constant1+bonus;
    r.hunger = constant2+25-bonus2;
    r.health = 25-constant2+bonus2;

    r.deathCause = "";
    r.isDead = false;
    return r;
}

bool doAct(Robot *r, Activity a){
    if(a.money < 0 && r->money < abs(a.money)){
        return false;
    }
    r->money += a.money;
    r->happiness += a.happiness;
    r->hygiene += a.hygiene;
    r->social += a.social;
    r->hunger += a.hunger;
    r->health += a.health;

    if (r->happiness <= 0){
        r->isDead = true;
        r->deathCause = "Unhappy";
    }
    if (r->hygiene <= 0){
        r->isDead = true;
        r->deathCause = "Unhygienic";
    }
    if (r->hunger <= 0){
        r->isDead = true;
        r->deathCause = "Starvation";
    }
    if(r->health <= 0){
        r->isDead = true;
        r->deathCause = "Death";
    }

    r->happiness = (r->happiness > 100) ? 100 : r->happiness;
    r->hygiene = (r->hygiene > 100) ? 100 : r->hygiene;
    r->hunger = (r->hunger > 100) ? 100 : r->hunger;
    r->health = (r->health > 100) ? 100 : r->health;

    return true;
}

void doReversedAct(Robot *r, Activity a){
    r->money -= abs(a.money);
    r->happiness -= abs(a.happiness);
    r->hygiene -= abs(a.hygiene);
    r->social -= abs(a.social);
    r->hunger -= abs(a.hunger);
    r->health -= abs(a.health);

    if (r->happiness <= 0){
        r->isDead = true;
        r->deathCause = "Unhappy";
    }
    if (r->hygiene <= 0){
        r->isDead = true;
        r->deathCause = "Unhygienic";
    }
    if (r->hunger <= 0){
        r->isDead = true;
        r->deathCause = "Starvation";
    }
    if(r->health <= 0){
        r->isDead = true;
        r->deathCause = "Death";
    }

    r->happiness = (r->happiness > 100) ? 100 : r->happiness;
    r->hygiene = (r->hygiene > 100) ? 100 : r->hygiene;
    r->hunger = (r->hunger > 100) ? 100 : r->hunger;
    r->health = (r->health > 100) ? 100 : r->health;

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

void respondEvent(Robot *r, Event *e){
    Activity act = e->activity;
    if((random(1,2*random(2,6)) % 2) == 1){
        printf("\n%s\n[ ", e->negative);
        if(act.money > 0) printf("-%d$ ", act.money);
        if(act.happiness > 0) printf("-%d Happiness ", act.happiness);
        if(act.hygiene > 0) printf("-%d Hygiene ", act.hygiene);
        if(act.hunger > 0) printf("-%d Hunger ", act.hunger);
        if(act.social > 0) printf("-%d Social ", act.social);
        if(act.health > 0) printf("-%d Health ", act.health);
        printf("]\n");

        doReversedAct(r, act);
    } else {
        printf("\n%s\n[ ", e->positive);
        if(act.money > 0) printf("+%d$ ", act.money);
        if(act.happiness > 0) printf("+%d Happiness ", act.happiness);
        if(act.hygiene > 0) printf("+%d Hygiene ", act.hygiene);
        if(act.hunger > 0) printf("+%d Hunger ", act.hunger);
        if(act.social > 0) printf("+%d Social ", act.social);
        if(act.health > 0) printf("+%d Health ", act.health);
        printf("]\n");

        doAct(r, act);
    }
}
