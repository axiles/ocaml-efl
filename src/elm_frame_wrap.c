#include "include.h"

PREFIX value ml_elm_frame_add(value v_parent)
{
        Evas_Object* frame = elm_frame_add((Evas_Object*) v_parent);
        if(frame == NULL) caml_failwith("elm_frame_add");
        return (value) frame;
}

PREFIX value ml_elm_frame_autocollapse_set(value v_obj, value v_flag)
{
        elm_frame_autocollapse_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_frame_autocollapse_get(value v_obj)
{
        return Val_bool(elm_frame_autocollapse_get((Evas_Object*) v_obj));
}

