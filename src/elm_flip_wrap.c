#include "include.h"

PREFIX inline Elm_Flip_Mode Elm_Flip_Mode_val(value v)
{
        switch(v) {
                case Val_rotate_y_center_axis:
                        return ELM_FLIP_ROTATE_Y_CENTER_AXIS;
                case Val_rotate_x_center_axis:
                        return ELM_FLIP_ROTATE_X_CENTER_AXIS;
                case Val_rotate_xz_center_axis:
                        return ELM_FLIP_ROTATE_XZ_CENTER_AXIS;
                case Val_rotate_yz_center_axis:
                        return ELM_FLIP_ROTATE_YZ_CENTER_AXIS;
                case Val_cube_left: return ELM_FLIP_CUBE_LEFT;
                case Val_cube_right: return ELM_FLIP_CUBE_RIGHT;
                case Val_cube_up: return ELM_FLIP_CUBE_UP;
                case Val_cube_down: return ELM_FLIP_CUBE_DOWN;
                case Val_page_left: return ELM_FLIP_PAGE_LEFT;
                case Val_page_right: return ELM_FLIP_PAGE_RIGHT;
                case Val_page_up: return ELM_FLIP_PAGE_UP;
                case Val_page_down: return ELM_FLIP_PAGE_DOWN;
                default: break;
        }
        caml_failwith("Elm_Flip_Mode_val");
        return ELM_FLIP_ROTATE_Y_CENTER_AXIS;
}

PREFIX inline Elm_Flip_Interaction Elm_Flip_Interaction_val(value v)
{
        switch(v) {
                case Val_none: return ELM_FLIP_INTERACTION_NONE;
                case Val_rotate: return ELM_FLIP_INTERACTION_ROTATE;
                case Val_cube: return ELM_FLIP_INTERACTION_CUBE;
                case Val_page: return ELM_FLIP_INTERACTION_PAGE;
                default: break;
        }
        caml_failwith("Elm_Flip_Interaction_val");
        return ELM_FLIP_INTERACTION_NONE;
}

PREFIX inline value Val_Elm_Flip_Interaction(Elm_Flip_Interaction i)
{
        switch(i) {
                case ELM_FLIP_INTERACTION_NONE: return Val_none;
                case ELM_FLIP_INTERACTION_ROTATE: return Val_rotate;
                case ELM_FLIP_INTERACTION_CUBE: return Val_cube;
                case ELM_FLIP_INTERACTION_PAGE: return Val_page;
        }
        return Val_none;
}

PREFIX inline Elm_Flip_Direction Elm_Flip_Direction_val(value v)
{
        switch(v) {
                case Val_up: return ELM_FLIP_DIRECTION_UP;
                case Val_down: return ELM_FLIP_DIRECTION_DOWN;
                case Val_left: return ELM_FLIP_DIRECTION_LEFT;
                case Val_right: return ELM_FLIP_DIRECTION_RIGHT;
                default: break;
        }
        caml_failwith("Elm_Flip_Direction_val");
        return ELM_FLIP_DIRECTION_UP;
}

PREFIX inline value Val_Elm_Flip_Direction(Elm_Flip_Direction d)
{
        switch(d) {
                case ELM_FLIP_DIRECTION_UP: return Val_up;
                case ELM_FLIP_DIRECTION_DOWN: return Val_down;
                case ELM_FLIP_DIRECTION_LEFT: return Val_left;
                case ELM_FLIP_DIRECTION_RIGHT: return Val_right;
        }
        return Val_up;
}

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

