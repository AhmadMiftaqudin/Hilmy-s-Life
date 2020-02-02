#include "event.h"
#include <stdio.h>

Event createEvent(Activity positiveactivity, Activity negativeactivity, char * description, char * positive, char * negative){
    Event e;
    e.name = positiveactivity.name;
    e.description = description;
    e.positive = positive;
    e.negative = negative;
    e.positiveactivity = positiveactivity;
    e.negativeactivity = negativeactivity;
    return e;
}

void printEvent(Event e){
    int i=0;

    printf("\nEvent: %s\n%s", e.name, e.description);
    
    printf("\n");
    for(i=0;i<70;i++){
        printf("-");
    }
    printf("\n");
}