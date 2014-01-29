#include "include.h"

PREFIX value ml_elm_segment_control_add(value v_parent)
{
        Evas_Object* segment_control = elm_segment_control_add(
                (Evas_Object*) v_parent);
        if(segment_control == NULL) caml_failwith("elm_segment_control_add");
        return (value) segment_control;
}

PREFIX value ml_elm_segment_control_item_add(
        value v_obj, value v_icon, value v_label, value v_unit)
{
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Elm_Object_Item* it = elm_segment_control_item_add((Evas_Object*) v_obj,
                icon, label);
        if(it == NULL) caml_failwith("elm_segment_control_item_add");
        return (value) it;
}

