#ifndef EVAS_H
#define EVAS_H

#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Smart_Cb_1_free(
        void* data, Evas_Object* obj, void* event_info);

 value copy_Evas_Event_Info(
        Evas_Callback_Type type, void* event_info);

 value copy_Evas_Coord_Point(Evas_Coord_Point p);

 value copy_Evas_Button_Flags(Evas_Button_Flags f);

 Evas_Callback_Priority Evas_Callback_Priority_val(value v);

 value* ml_Evas_register_value(value v);
 void ml_Evas_remove_values(void);

 value copy_Evas_Coord_Size(Evas_Coord_Size* s);

value copy_Evas_Coord_Rectangle(Evas_Coord_Rectangle* r);

#endif

