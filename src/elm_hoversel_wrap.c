#include "include.h"

PREFIX value ml_elm_hoversel_add(value v_parent)
{
        Evas_Object* obj = elm_hoversel_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_hoversel_add");
        return (value) obj;
}

PREFIX value ml_elm_hoversel_horizontal_set(value v_box, value v_flag)
{
        elm_hoversel_horizontal_set((Evas_Object*) v_box, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_hoversel_horizontal_get(value v_obj)
{
        return Val_bool(elm_hoversel_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_hoversel_hover_parent_set(value v_obj, value v_parent)
{
        elm_hoversel_hover_parent_set((Evas_Object*) v_obj,
                (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_hoversel_hover_parent_get(value v_obj)
{
        return (value) elm_hoversel_hover_parent_get((Evas_Object*) v_obj);
}

