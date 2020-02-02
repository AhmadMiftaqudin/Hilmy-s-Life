#include "event.h"
#include <stdio.h>

Event createEvent(Activity activity, char * description, char * positive, char * negative){
    Event e;
    e.name = activity.name;
    e.description = description;
    e.positive = positive;
    e.negative = negative;
    e.activity = activity;
    return e;
}

void printEvent(Event e){
    int i=0;
    printf("\n");
    for(i=0;i<70;i++){
        printf("-");
    }

    printf("\nEvent: %s\n%s", e.name, e.description);
    
    printf("\n");
    for(i=0;i<70;i++){
        printf("-");
    }
    printf("\n");
}
