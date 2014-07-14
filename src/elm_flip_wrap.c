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

PREFIX value ml_elm_flip_go(value v_obj, value v_mode)
{
        elm_flip_go((Evas_Object*) v_obj, Elm_Flip_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_flip_go_to(value v_obj, value v_front, value v_mode)
{
        elm_flip_go_to((Evas_Object*) v_obj, Bool_val(v_front),
                Elm_Flip_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_flip_interaction_set(value v_obj, value v_interaction)
{
        elm_flip_interaction_set((Evas_Object*) v_obj,
                Elm_Flip_Interaction_val(v_interaction));
        return Val_unit;
}

PREFIX value ml_elm_flip_interaction_get(value v_obj)
{
        return Val_Elm_Flip_Interaction(elm_flip_interaction_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_flip_interaction_direction_enabled_set(
        value v_obj, value v_dir, value v_flag)
{
        elm_flip_interaction_direction_enabled_set((Evas_Object*) v_obj,
                Elm_Flip_Direction_val(v_dir), Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_flip_interaction_direction_enabled_get(
        value v_obj, value v_dir)
{
        return Val_bool(elm_flip_interaction_direction_enabled_get(
                (Evas_Object*) v_obj, Elm_Flip_Direction_val(v_dir)));
}

PREFIX value ml_elm_flip_interaction_direction_hitsize_set(
        value v_obj, value v_dir, value v_x)
{
        elm_flip_interaction_direction_hitsize_set((Evas_Object*) v_obj,
                Elm_Flip_Direction_val(v_dir), Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_flip_interaction_direction_hitsize_get(
        value v_obj, value v_dir)
{
        return copy_double(elm_flip_interaction_direction_hitsize_get(
                (Evas_Object*) v_obj, Elm_Flip_Direction_val(v_dir)));
}

