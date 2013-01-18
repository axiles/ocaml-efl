#include "include.h"

PREFIX value ml_elm_win_add(value v_parent, value v_name, value v_ty)
{
        Evas_Object* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Evas_Object*) Field(v_parent, 0);
        Evas_Object* win = elm_win_add(parent, String_val(v_name),
                Elm_Win_Type_val(v_ty));
        if(win == NULL) caml_failwith("elm_win_add");
        return (value) win;
}

PREFIX value ml_elm_win_util_standard_add(value v_name, value v_title)
{
        Evas_Object* obj = elm_win_util_standard_add(String_val(v_name),
                String_val(v_title));
        if(obj == NULL) caml_failwith("elm_win_util_standard_add");
        return (value) obj;
}

PREFIX value ml_elm_win_resize_object_add(value v_obj, value v_subobj)
{
        elm_win_resize_object_add((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_win_resize_object_del(value v_obj, value v_subobj)
{
        elm_win_resize_object_del((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_win_title_set(value v_obj, value v_title)
{
        elm_win_title_set((Evas_Object*) v_obj, String_val(v_title));
        return Val_unit;
}

PREFIX value ml_elm_win_title_get(value v_obj)
{
        return copy_string(elm_win_title_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_icon_name_set(value v_obj, value v_name)
{
        elm_win_icon_name_set((Evas_Object*) v_obj, String_val(v_name));
        return Val_unit;
}

PREFIX value ml_elm_win_icon_name_get(value v_obj)
{
        return copy_string(elm_win_icon_name_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_role_set(value v_obj, value v_role)
{
        elm_win_role_set((Evas_Object*) v_obj, String_val(v_role));
        return Val_unit;
}

PREFIX value ml_elm_win_role_get(value v_obj)
{
        return copy_string(elm_win_role_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_icon_object_set(value v_obj, value v_icon)
{
        elm_win_icon_object_set((Evas_Object*) v_obj, (Evas_Object*) v_icon);
        return Val_unit;
}

PREFIX value ml_elm_win_icon_object_get(value v_obj)
{
        return (value) elm_win_icon_object_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_win_autodel_set(value v_win, value v_flag)
{
        elm_win_autodel_set((Evas_Object*) v_win, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_autodel_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_autodel_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_activate(value v_obj)
{
        elm_win_activate((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_lower(value v_obj)
{
        elm_win_lower((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_raise(value v_obj)
{
        elm_win_raise((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_center(value v_obj, value v_h, value v_v)
{
        elm_win_center((Evas_Object*) v_obj, Eina_Bool_val(v_h),
                Eina_Bool_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_win_borderless_set(value v_obj, value v_flag)
{
        elm_win_borderless_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_borderless_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_borderless_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_shaped_set(value v_obj, value v_flag)
{
        elm_win_shaped_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_shaped_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_shaped_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_alpha_set(value v_obj, value v_flag)
{
        elm_win_alpha_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_alpha_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_alpha_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_override_set(value v_obj, value v_flag)
{
        elm_win_override_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_override_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_override_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_fullscreen_set(value v_obj, value v_flag)
{
        elm_win_fullscreen_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_fullscreen_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_fullscreen_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_maximized_set(value v_obj, value v_flag)
{
        elm_win_maximized_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_maximized_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_maximized_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_iconified_set(value v_obj, value v_flag)
{
        elm_win_iconified_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_iconified_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_iconified_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_withdrawn_set(value v_obj, value v_flag)
{
        elm_win_withdrawn_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_withdrawn_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_withdrawn_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_urgent_set(value v_obj, value v_flag)
{
        elm_win_urgent_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_urgent_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_urgent_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_demand_attention_set(value v_obj, value v_flag)
{
        elm_win_demand_attention_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_demand_attention_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_demand_attention_get(
                (Evas_Object*) v_obj));
}

