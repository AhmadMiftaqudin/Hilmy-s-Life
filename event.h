#ifndef _EVENT_H_
#define _EVENT_H_

#include <stdio.h>
#include "activity.h"

typedef struct{
    Activity positiveactivity;
    Activity negativeactivity;
    char * name;
    char * description;
    char * positive;
    char * negative;
} Event;

Event createEvent(Activity positiveactivity, Activity negativeactivity, char *description, char * positive, char * negative);

void printEvent(Event event);

#endif