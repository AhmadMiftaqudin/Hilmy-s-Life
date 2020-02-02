#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "robot.h"
#include "utils.h"
#include "activity.h"
#include "event.h"

int main() {
    Robot r = initRobot();

    int const numberofactivity = 12;
    int const numberofevent = 6;
    time_t now,end;

    Activity act[numberofactivity];
    act[0] = createActivity("Daydreaming", random(1,3), 0, -1*random(1,3), -1*random(1,3), 0, random(1,3));
    act[1] = createActivity("Sleep", random(2,4), 0, -2, -1*random(2,5), 0, 1+random(1,4));
    act[2] = createActivity("Shower", -1*random(1,2), -2, random(3, 5), -1*random(2,3), 0, 0);
    act[3] = createActivity("Eat", -1*random(1,2), -1*random(3, 5), 0, random(2,5), 0, random(2,3));
    act[4] = createActivity("Picnic", random(1,2), -1*random(3,5), -3, random(1,3), random(1,3), random(1,3));
    act[5] = createActivity("Work", -1*random(3,5), random(3,6), -2, -1*random(2,4), random(1,2), random(2,4)*-1);
    act[6] = createActivity("Part Time", -1*random(2,4), random(2,4), -2, -1*random(2,3), 0, -1*random(2,4));
    act[7] = createActivity("Party", 3, -1*random(3,6), -2, random(1,2), random(3,5), -1*random(3,5));
    act[8] = createActivity("Hangout", 3, -1*random(2,5), -2, -1*random(2,3), random(2,4), 0);
    act[9] = createActivity("Travelling", random(2,4), random(5,8)*-1, random(3,4)*-1, random(2,4), random(4,6), random(3,4)*-1);
    act[10] = createActivity("Spa", 1, -1*random(4,6), random(3,4), random(3,5)*-1, 1, random(1,2));
    act[11] = createActivity("Massage", 1, random(3,4)*-1, random(1,2), 0, 1, random(1,2));

    Event events[numberofevent];
    events[0] = createEvent(
        createActivity("Beautiful Girl", random(4,6), 0, 0, -1*random(2,4), random(4,7), 0), 
        createActivity("Beautiful Girl", -1*random(4,6), 0 , 0, -1*random(2,4), -1*random(1,4), 0),
    "Hilmy meets a beautiful girl.\nWhat should Hilmy do?\n[1] Ask the girl's phone number\n[2] Nevermind, just walk away.", 
    "The girl gives Hilmy her phone number.", "The girl rejects Hilmy.");
    events[1] = createEvent(
        createActivity("Game Competition", random(1,2), random(3,5), 0, -1*random(1,3), random(3,5), 0), 
        createActivity("Game Competition", -1*random(3,5), -1*random(3,5), 0, -1*random(2,3), -2, 0),
    "Hilmy has been challenged by random person.\nWhat should Hilmy do?\n[1] Accept the challenge.\n[2] Decline the challenge.", 
    "Hilmy wins the challenge.", "Awww! Hilmy loses the challenge.");
    events[2] = createEvent(
        createActivity("Concert", random(3,5), -1*random(8,10), -3, -1*random(3,4), random(10,15), 0), 
        createActivity("Concert", -1*random(5,10), -1*random(8,15), 0,0,0,0),
    "Hilmy saw a concert poster.\nWhat should Hilmy do?\n[1] Buy the concer ticket.\n[2] Not interested with music.", 
    "Hilmy enjoys the concert.", "The concert was a scam.");
    events[3] = createEvent(
        createActivity("Grandma", 0, random(5,10), 0,0,random(10,15), 0),
        createActivity("Grandma", 0,0,0,0,0,-100),
    "Hilmy saw a grandma who wants to\ncross the road. What should Hilmy do?\n[1] Help her.\n[2] Walk away.",
    "The grandma thanks Hilmy for helping her.", "Hilmy is hit by a car.");
    events[4] = createEvent(
        createActivity("Lend Money", -1*random(3,5), 0, 0,0, random(5,10), 0),
        createActivity("Lend Money", -1*random(4,6), -1*random(5,10), 0,0, random(1,3), 0),
    "A friend of Hilmy needs some money.\nWhat should Hilmy do?\n[1] Lend some money.\n[2] Ignore him.",
    "He thanked to you and returned the money.", "He just thanked you and good bye.");
    events[5] = createEvent(
        createActivity("Food Festival", random(10,15), -1*random(10,20), -1*random(5,10), 100, random(3,5), random(2,4)),
        createActivity("Food Festival", -1*random(3,9), -1*random(15,20), -1*random(5,10), -1*random(5,10), 0, -1*random(10,25)),
    "Hilmy saw a food festival.\nWhat should Hilmy do?\n[1] Go there and buy some foods.\n[2]Go home.",
    "Hilmy enjoys the food.", "Hilmy got food poisoning.");

    int action,i;
    int round=1;
    while(!r.isDead){
        
        //Proses Output per Ronde
        printf("\nRound: %d\n", round);
        showStatus(r);

        //Event
        if (round % 5 == 0){
            int decision;
            Event startedevent = events[random(0,numberofevent-1)];
            printEvent(startedevent);
            printf("\nInput Number: ");
            scanf("%d", &decision);
            while(decision < 1 || decision > 2){  
                printf("Invalid Arguments!\nInput Number: ");
                scanf("%d", &decision);
            }
            if (decision == 1) respondEvent(&r, &startedevent);
            round++;
            time(&now);
            do{time(&end);} while(difftime(end, now) <= 0.5);
            continue;
        }

        //Lanjutan Proses Output per Ronde
        printf("\nList of Action:");
        for (i=0;i<numberofactivity;i++){
            if(i<9){printf("\n[0%d] ", i+1);}
            else{printf("\n[%d] ", i+1);}
            printActivity(act[i]);
        }

        //Proses Input
        printf("\nWhat will Hilmy do?\nInput Number: ");
        scanf("%d", &action);
        while(action > numberofactivity || action < 1){
            printf("Invalid Arguments!\nWhat will Hilmy do?\nInput Number: ");
            scanf("%d", &action);
        }
        if (action <= numberofactivity || action >= 1){
            while (!doAct(&r, act[action-1], false)){
                printf("\nNot Enough Money! Please Pick Another Action!\nWhat will Hilmy do?\nInput Number: ");
                scanf("%d", &action);
            }

            for (i=0;i<numberofactivity;i++){
                if (i==(action-1)) {modifyActivity(&act[i], 1.6, 0.45);}
                else {modifyActivity(&act[i], 0.95, 1.1);}
            }
        }
        round++;
        time(&now);
        do{time(&end);} while(difftime(end, now) <= 0.15);
    }
    printf("\n\n\nGame Over! Round: %d\nHilmy's Dead! Cause of Death: %s\nScore: %d\n\n\n", round, r.deathCause, r.social);
    scanf("%d", &action);
    return 0;
}