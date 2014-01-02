#include "include.h"

PREFIX Elm_Actionslider_Pos Elm_Actionslider_Pos_vals(
        value v_left, value v_center, value v_right)
{
        Elm_Actionslider_Pos pos = 0;
        if(Bool_val(v_left)) pos = pos | ELM_ACTIONSLIDER_LEFT;
        if(Bool_val(v_center)) pos = pos | ELM_ACTIONSLIDER_CENTER;
        if(Bool_val(v_right)) pos = pos | ELM_ACTIONSLIDER_RIGHT;
        return pos;
}

PREFIX value copy_Elm_Actionslider_Pos(Elm_Actionslider_Pos pos)
{
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_bool(pos & ELM_ACTIONSLIDER_LEFT));
        Store_field(v, 1, Val_bool(pos & ELM_ACTIONSLIDER_CENTER));
        Store_field(v, 2, Val_bool(pos & ELM_ACTIONSLIDER_RIGHT));
        return v;
}

PREFIX value ml_elm_actionslider_add(value v_parent)
{
        Evas_Object* obj = elm_actionslider_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_actionslider_add");
        return (value) obj;
}

PREFIX value ml_elm_actionslider_selected_label_get(value v_obj)
{
        return copy_string(elm_actionslider_selected_label_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_actionslider_indicator_pos_set(
        value v_obj, value v_left, value v_center, value v_right)
{
        elm_actionslider_indicator_pos_set((Evas_Object*) v_obj,
                Elm_Actionslider_Pos_vals(v_left, v_center, v_right));
        return Val_unit;
}

PREFIX value ml_elm_actionslider_indicator_pos_get(value v_obj)
{
        return copy_Elm_Actionslider_Pos(elm_actionslider_indicator_pos_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_actionslider_magnet_pos_set(
        value v_obj, value v_left, value v_center, value v_right)
{
        elm_actionslider_magnet_pos_set((Evas_Object*) v_obj,
                Elm_Actionslider_Pos_vals(v_left, v_center, v_right));
        return Val_unit;
}

PREFIX value ml_elm_actionslider_magnet_pos_get(value v_obj)
{
        return copy_Elm_Actionslider_Pos(elm_actionslider_magnet_pos_get(
                (Evas_Object*) v_obj));
}

