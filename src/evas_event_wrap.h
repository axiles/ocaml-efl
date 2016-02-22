#ifndef EVAS_EVENT_H
#define EVAS_EVENT_H

#include "include.h"

 value Val_Evas_Event_Flags(Evas_Event_Flags f);

 value copy_Evas_Event_Info(
        Evas_Callback_Type t, void* event_info);

#endif

