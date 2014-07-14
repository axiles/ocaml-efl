#include "include.h"

PREFIX value ml_elm_bubble_add(Evas_Object* v_parent)
{
        Evas_Object* bubble = elm_bubble_add((Evas_Object*) v_parent);
        if(bubble == NULL) caml_failwith("elm_bubble_add");
        return (value) bubble;
}

PREFIX value ml_elm_bubble_pos_set(value v_obj, value v_pos)
{
        elm_bubble_pos_set((Evas_Object*) v_obj, Elm_Bubble_Pos_val(v_pos));
        return Val_unit;
}

PREFIX value ml_elm_bubble_pos_get(value v_obj)
{
        return Val_Elm_Bubble_Pos(elm_bubble_pos_get((Evas_Object*) v_obj));
}

