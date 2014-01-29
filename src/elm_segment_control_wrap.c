#include "include.h"

PREFIX value ml_elm_segment_control_add(value v_parent)
{
        Evas_Object* segment_control = elm_segment_control_add(
                (Evas_Object*) v_parent);
        if(segment_control == NULL) caml_failwith("elm_segment_control_add");
        return (value) segment_control;
}

