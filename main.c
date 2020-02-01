#include <stdio.h>
#include "robot.h"
#include "utils.h"
#include "activity.h"

int main() {
    Robot r = initRobot();

    int const numberofactivity = 13;
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
    act[12] = createActivity("Lend Money", -1*random(4,5), random(4,8)*-1, 0, 0, random(2,4), 0);


    int action,i;
    int round=1;
    while(!r.isDead){
        
        //Proses Output per Ronde
        showStatus(r);
        printf("\nList of Action:");
        for (i=0;i<numberofactivity;i++){
            if(i<9){printf("\n[0%d] ", i+1);}
            else{printf("\n[%d] ", i+1);}
            printActivity(act[i]);
        }

        //Proses Input
        printf("\nWhat will Hilmy do?\nInput Number: ");
        scanf("%d", &action);
        while (!doAct(&r, &act[action-1])){
            printf("\nNot Enough Money! Please Pick Another Action!\nWhat will Hilmy do?\nInput Number: ");
            scanf("%d", &action);
        }

        for (i=0;i<numberofactivity;i++){
            if (i==(action-1)) {modifyActivity(&act[i], 1.25, 0.75);}
            else {modifyActivity(&act[i], 0.8, 1.2);}
        }

        round++;
    }
    printf("\n\n\nGame Over! Round: %d\nHilmy's Dead! Cause of Death: %s\nScore: %d\n\n\n", round, r.deathCause, r.social);
    return 0;
}
