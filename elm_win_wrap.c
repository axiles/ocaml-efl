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

PREFIX value ml_elm_win_autodel_set(value v_win, value v_flag)
{
        elm_win_autodel_set((Evas_Object*) v_win, Eina_Bool_val(v_flag));
        return Val_unit;
}

