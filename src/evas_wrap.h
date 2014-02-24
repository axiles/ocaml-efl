#ifndef EVAS_H
#define EVAS_H

#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Smart_Cb_1_free(
        void* data, Evas_Object* obj, void* event_info);

PREFIX inline value copy_Evas_Event_Info(
        Evas_Callback_Type type, void* event_info);

PREFIX inline Evas_Load_Error Evas_Load_Error_val(value v);
PREFIX inline value Val_Evas_Load_Error(Evas_Load_Error e);

PREFIX inline value copy_Evas_Point(Evas_Point p);

PREFIX inline value copy_Evas_Coord_Point(Evas_Coord_Point p);

PREFIX inline value copy_Evas_Position(Evas_Position p);

PREFIX inline value copy_Evas_Coord_Precision_Point(
        Evas_Coord_Precision_Point p);

PREFIX inline value copy_Evas_Precision_Position(Evas_Precision_Position p);

PREFIX inline value Val_Evas_Button_Flags(Evas_Button_Flags f);

PREFIX inline Evas_Aspect_Control Evas_Aspect_Control_val(value v);

PREFIX inline Evas_Callback_Priority Evas_Callback_Priority_val(value v);

PREFIX inline value* ml_Evas_register_value(value v);
PREFIX inline void ml_Evas_remove_values();

#endif

