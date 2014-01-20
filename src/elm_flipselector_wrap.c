#include "include.h"

PREFIX value ml_elm_flipselector_add(value v_parent)
{
        Evas_Object* flipselector = elm_flipselector_add(
                (Evas_Object*) v_parent);
        if(flipselector == NULL) caml_failwith("elm_flipselector_add");
        return (value) flipselector;
}

PREFIX value ml_elm_flipselector_flip_next(value v_obj)
{
        elm_flipselector_flip_next((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_flipselector_flip_prev(value v_obj)
{
        elm_flipselector_flip_prev((Evas_Object*) v_obj);
        return Val_unit;
}

