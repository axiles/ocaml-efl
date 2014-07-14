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

PREFIX value ml_elm_fileselector_selected_get(value v_obj)
{
        return copy_string(elm_fileselector_selected_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_mime_types_filter_append(
        value v_obj, value v_mime_types, value v_filter_name, value v_unit)
{
        char* filter_name;
        if(v_filter_name == Val_int(0)) filter_name = NULL;
        else filter_name = String_val(Field(v_filter_name, 0));
        return Val_bool(elm_fileselector_mime_types_filter_append(
                (Evas_Object*) v_obj, String_val(v_mime_types), filter_name));
}

PREFIX value ml_elm_fileselector_filters_clear(value v_obj)
{
        elm_fileselector_filters_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_fileselector_hidden_visible_set(value v_obj, value v_flag)
{
        elm_fileselector_hidden_visible_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_hidden_visible_get(value v_obj)
{
        return Val_bool(elm_fileselector_hidden_visible_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_mode_set(value v_obj, value v_mode)
{
        elm_fileselector_mode_set((Evas_Object*) v_obj,
                Elm_Fileselector_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_mode_get(value v_obj)
{
        return Val_Elm_Fileselector_Mode(elm_fileselector_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_multi_select_set(value v_obj, value v_flag)
{
        elm_fileselector_multi_select_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_multi_select_get(value v_obj)
{
        return Val_bool(elm_fileselector_multi_select_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_selected_paths_get(value v_obj)
{
        return copy_Eina_List_string(
                elm_fileselector_selected_paths_get((Evas_Object*) v_obj));
}

