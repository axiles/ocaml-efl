#include "include.h"

PREFIX value ml_elm_panes_add(value v_parent)
{
        Evas_Object* obj = elm_panes_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_panes_add");
        return (value) obj;
}

PREFIX value ml_elm_panes_fixed_set(value v_obj, value v_flag)
{
        elm_panes_fixed_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_panes_fixed_get(value v_obj)
{
        return Val_bool(elm_panes_fixed_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_panes_content_left_size_get(value v_obj)
{
        return copy_double(elm_panes_content_left_size_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_panes_content_left_size_set(value v_obj, value v_size)
{
        elm_panes_content_left_size_set((Evas_Object*) v_obj,
                Double_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_panes_content_right_size_get(value v_obj)
{
        return copy_double(elm_panes_content_right_size_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_panes_content_right_size_set(value v_obj, value v_size)
{
        elm_panes_content_right_size_set((Evas_Object*) v_obj,
                Double_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_panes_horizontal_set(value v_obj, value v_flag)
{
        elm_panes_horizontal_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_panes_horizontal_get(value v_obj)
{
        return Val_bool(elm_panes_horizontal_get((Evas_Object*) v_obj));
}

