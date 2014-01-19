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

