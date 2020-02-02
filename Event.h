#ifndef _EVENT_H_
#define _EVENT_H_

#include <stdio.h>
#include "activity.h"

typedef struct{
    Activity activity;
    char * name;
    char * description;
    char * positive;
    char * negative;
} Event;

Event createEvent(Activity activity, char *description, char * positive, char * negative);

void printEvent(Event event);

#endif
