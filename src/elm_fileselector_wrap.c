#include "include.h"

inline Elm_Fileselector_Mode Elm_Fileselector_Mode_val(value v_mode)
{
        switch(v_mode) {
                case Val_list: return ELM_FILESELECTOR_LIST;
                case Val_grid: return ELM_FILESELECTOR_GRID;
                case Val_last: return ELM_FILESELECTOR_LAST;
        }
        caml_failwith("Elm_FileSelector_Mode_val");
        return ELM_FILESELECTOR_LIST;
}

inline value Val_Elm_Fileselector_Mode(Elm_Fileselector_Mode mode)
{
        switch(mode) {
                case ELM_FILESELECTOR_LIST: return Val_list;
                case ELM_FILESELECTOR_GRID: return Val_grid;
                case ELM_FILESELECTOR_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Fileselector_Mode");
        return Val_list;
}

inline Elm_Fileselector_Sort Elm_Fileselector_Sort_val(value v)
{
        switch(v) {
                case Val_filename_asc:
                        return ELM_FILESELECTOR_SORT_BY_FILENAME_ASC;
                case Val_filename_desc:
                        return ELM_FILESELECTOR_SORT_BY_FILENAME_DESC;
                case Val_type_asc: return ELM_FILESELECTOR_SORT_BY_TYPE_ASC;
                case Val_type_desc: return ELM_FILESELECTOR_SORT_BY_TYPE_DESC;
                case Val_size_asc: return ELM_FILESELECTOR_SORT_BY_SIZE_ASC;
                case Val_size_desc: return ELM_FILESELECTOR_SORT_BY_SIZE_DESC;
                case Val_modified_asc:
                        return ELM_FILESELECTOR_SORT_BY_MODIFIED_ASC;
                case Val_modified_desc:
                        return ELM_FILESELECTOR_SORT_BY_MODIFIED_DESC;
                case Val_last: return ELM_FILESELECTOR_SORT_LAST;
        }
        caml_failwith("Elm_Fileselector_Sort_val");
        return ELM_FILESELECTOR_SORT_BY_FILENAME_ASC;
}

inline value Val_Elm_Fileselector_Sort(Elm_Fileselector_Sort s)
{
        switch(s) {
                case ELM_FILESELECTOR_SORT_BY_FILENAME_ASC:
                        return Val_filename_asc;
                case ELM_FILESELECTOR_SORT_BY_FILENAME_DESC:
                        return Val_filename_desc;
                case ELM_FILESELECTOR_SORT_BY_TYPE_ASC: return Val_type_asc;
                case ELM_FILESELECTOR_SORT_BY_TYPE_DESC: return Val_type_desc;
                case ELM_FILESELECTOR_SORT_BY_SIZE_ASC: return Val_size_asc;
                case ELM_FILESELECTOR_SORT_BY_SIZE_DESC: return Val_size_desc;
                case ELM_FILESELECTOR_SORT_BY_MODIFIED_ASC:
                        return Val_modified_asc;
                case ELM_FILESELECTOR_SORT_BY_MODIFIED_DESC:
                        return Val_modified_desc;
                case ELM_FILESELECTOR_SORT_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Fileselector_Sort");
        return Val_filename_asc;
}

Eina_Bool ml_Elm_Fileselector_Filter_Func(
        const char* path, Eina_Bool dir, void* data)
{
        CAMLparam0();
        CAMLlocal2(v_s, v_r);
        value* v_fun = (value*) data;
        v_s = copy_string(path);
        v_r = caml_callback2(*v_fun, v_s, Val_bool(dir));
        CAMLreturnT(Eina_Bool, Bool_val(v_r));
}

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

PREFIX value ml_elm_fileselector_custom_filter_append(
        value v_obj, value v_fun, value v_name, value v_unit)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_fun);
        return Val_bool(elm_fileselector_custom_filter_append(obj,
                ml_Elm_Fileselector_Filter_Func, data, String_opt_val(v_name)));
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

PREFIX value ml_elm_fileselector_thumbnail_size_set(
        value v_obj, value v_w, value v_h)
{
        elm_fileselector_thumbnail_size_set((Evas_Object*) v_obj,
                Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_fileselector_thumbnail_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_fileselector_thumbnail_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_fileselector_sort_method_get(value v_obj)
{
        return Val_Elm_Fileselector_Sort(elm_fileselector_sort_method_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_fileselector_sort_method_set(value v_obj, value v_sort)
{
        elm_fileselector_sort_method_set((Evas_Object*) v_obj,
                Elm_Fileselector_Sort_val(v_sort));
        return Val_unit;
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

