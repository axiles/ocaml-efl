#ifndef EVAS_EVENT_H
#define EVAS_EVENT_H

#include "include.h"

inline value copy_Evas_Event_Mouse_In(Evas_Event_Mouse_In* e);

inline value copy_Evas_Event_Mouse_In(Evas_Event_Mouse_In* e);

inline value copy_Evas_Event_Mouse_Out(Evas_Event_Mouse_Out* e);

inline value copy_Evas_Event_Mouse_Down(Evas_Event_Mouse_Down* ev);

inline value copy_Evas_Event_Mouse_Up(Evas_Event_Mouse_Up* ev);

inline value copy_Evas_Event_Mouse_Move(Evas_Event_Mouse_Move* ev);

inline value copy_Evas_Event_Mouse_Wheel(Evas_Event_Mouse_Wheel* ev);

inline value copy_Evas_Event_Multi_Down(Evas_Event_Multi_Down* ev);

inline value copy_Evas_Event_Multi_Up(Evas_Event_Multi_Up* ev);

inline value copy_Evas_Event_Multi_Move(Evas_Event_Multi_Move* ev);

inline value copy_Evas_Event_Key_Down(Evas_Event_Key_Down* info);

inline value copy_Evas_Event_Key_Up(Evas_Event_Key_Up* info);

inline value copy_Evas_Event_Hold(Evas_Event_Hold* ev);

inline value copy_Evas_Event_Info(
        Evas_Callback_Type t, void* event_info);

#endif

