#include "include.h"

PREFIX value ml_elm_flip_add(value v_parent)
{
        Evas_Object* flip = elm_flip_add((Evas_Object*) v_parent);
        if(flip == NULL) caml_failwith("elm_flip_add");
        return (value) flip;
}

PREFIX value ml_elm_flip_front_visible_get(value v_obj)
{
        return Val_bool(elm_flip_front_visible_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_flip_perspective_set(
        value v_obj, value v_focus, value v_x, value v_y)
{
        elm_flip_perspective_set((Evas_Object*) v_obj, Int_val(v_focus),
                Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

