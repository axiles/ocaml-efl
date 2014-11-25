#ifndef ELM_OBJECT_H
#define ELM_OBJECT_H

#include "include.h"

inline value Val_Elm_Object_Select_Mode(Elm_Object_Select_Mode m);

PREFIX Evas_Object* ml_Elm_Tooltip_Item_Content_Cb_0(
        void* data, Evas_Object* obj, Evas_Object* tooltip, void* item);

void ml_Evas_Object_Event_Cb_on_del(
        void* data, Evas* e, Evas_Object* obj, void* event_info);

inline void ml_Elm_Object_Item_gc_value(
        const Elm_Object_Item* it, value* data);
inline value* ml_Elm_Object_Item_register_value(
        Elm_Object_Item* it, value v);

#endif
