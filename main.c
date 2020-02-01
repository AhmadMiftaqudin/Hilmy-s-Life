#include <stdio.h>
#include "robot.h"
#include "utils.h"
#include "activity.h"

int main() {
    Robot r = initRobot();

    Activity act[2];
    act[0] = createActivity("Sleep", random(2,4), -3, -5*random(1,3), 0, random(2,4), 1);
    act[1] = createActivity("Shower", random(1,3), -2, random(1,3), -1*random(1,3), 0, 2);

    int action,i;
    int round=1;
    while(!r.isDead){
        
        //Proses Output per Ronde
        showStatus(r);
        printf("\nList of Action:");
        for (i=0;i<2;i++){
            printf("\n[%d] ", i+1);
            printActivity(act[i]);
        }

        //Proses Input
        printf("\nWhat will Hilmy do?\nInput Number: ");
        scanf("%d", &action);
        while (!doAct(&r, &act[action-1])){
            printf("\nNot Enough Money! Please Pick Another Action!\nWhat will Hilmy do?\nInput Number: ");
            scanf("%d", &action);
        }

        for (i=0;i<2;i++){
            if (i==(action-1)) {modifyActivity(&act[i], 1.2, 0.8);}
            else {modifyActivity(&act[i], 0.9, 1.1);}
        }

        round++;
    }
    printf("\n\n\nGame Over! Round: %d\nHilmy's Dead! Cause of Death: %s\nScore: %d\n\n\n", round, r.deathCause, r.social);
    return 0;
}