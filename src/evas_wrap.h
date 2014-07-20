#ifndef EVAS_H
#define EVAS_H

#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Smart_Cb_1_free(
        void* data, Evas_Object* obj, void* event_info);

inline value copy_Evas_Event_Info(
        Evas_Callback_Type type, void* event_info);

/*inline value copy_Evas_Point(Evas_Point p);*/

inline value copy_Evas_Coord_Point(Evas_Coord_Point p);

/*inline value copy_Evas_Position(Evas_Position p);*/

/*inline value copy_Evas_Coord_Precision_Point(
        Evas_Coord_Precision_Point p);

inline value copy_Evas_Precision_Position(Evas_Precision_Position p);*/

inline value copy_Evas_Button_Flags(Evas_Button_Flags f);

inline Evas_Callback_Priority Evas_Callback_Priority_val(value v);

inline value* ml_Evas_register_value(value v);
inline void ml_Evas_remove_values();

inline value copy_Evas_Coord_Size(Evas_Coord_Size* s);

inline Evas_Modifier* Evas_Modifier_val(value v);
inline value Val_Evas_Modifier(Evas_Modifier* m);

inline Evas_Object* Evas_Object_val(value v);
inline value Val_Evas_Object(Evas_Object* obj);

inline Evas_Device* Evas_Device_val(value v);
inline value Val_Evas_Device(Evas_Device* d);

#endif

