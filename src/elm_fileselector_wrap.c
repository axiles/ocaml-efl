#include "include.h"

PREFIX value ml_elm_fileselector_add(value v_parent)
{
        Evas_Object* obj = elm_fileselector_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_fileselector");
        return (value) obj;
}

PREFIX value ml_elm_fileselector_is_save_set(value v_obj, value v_flag)
{
        elm_fileselector_is_save_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_is_save_get(value v_obj)
{
        return Val_Eina_Bool(elm_fileselector_is_save_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_folder_only_set(value v_obj, value v_flag)
{
        elm_fileselector_folder_only_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_folder_only_get(value v_obj)
{
        return Val_Eina_Bool(elm_fileselector_folder_only_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_buttons_ok_cancel_set(
        value v_obj, value v_flag)
{
        elm_fileselector_buttons_ok_cancel_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_buttons_ok_cancel_get(value v_obj)
{
        return Val_Eina_Bool(elm_fileselector_buttons_ok_cancel_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_expandable_set(value v_obj, value v_flag)
{
        elm_fileselector_expandable_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_expandable_get(value v_obj)
{
        return Val_Eina_Bool(elm_fileselector_expandable_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_path_set(value v_obj, value v_path)
{
        elm_fileselector_path_set((Evas_Object*) v_obj, String_val(v_path));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_path_get(value v_obj)
{
        return copy_string(elm_fileselector_path_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_selected_set(value v_obj, value v_path)
{
        return Val_Eina_Bool(elm_fileselector_selected_set((Evas_Object*) v_obj,
                String_val(v_path)));
}

