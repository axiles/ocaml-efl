#include "include.h"

PREFIX value ml_elm_theme_new(value v_unit)
{
        return copy_Elm_Theme(elm_theme_new());
}

PREFIX value ml_elm_theme_free(value v_th)
{
        elm_theme_free(Elm_Theme_val(v_th));
        return Val_unit;
}

PREFIX value ml_elm_theme_copy(value v_th, value v_thref)
{
        elm_theme_copy(Elm_Theme_val(v_th), Elm_Theme_val(v_thref));
        return Val_unit;
}

PREFIX value ml_elm_theme_ref_set(value v_th, value v_thref)
{
        Elm_Theme* thref;
        if(v_thref == Val_int(0)) thref = NULL;
        else thref = Elm_Theme_val(Field(v_thref, 0));
        elm_theme_ref_set(Elm_Theme_val(v_th), thref);
        return Val_unit;
}

PREFIX value ml_elm_theme_ref_get(value v_th)
{
        Elm_Theme* thref = elm_theme_ref_get(Elm_Theme_val(v_th));
        return copy_Elm_Theme_opt(thref);
}

PREFIX value ml_elm_theme_default_get(value v_unit)
{
        return copy_Elm_Theme(elm_theme_default_get());
}

PREFIX value ml_elm_theme_overlay_add(value v_th, value v_item)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        elm_theme_overlay_add(th, String_val(v_item));
        return Val_unit;
}

PREFIX value ml_elm_theme_overlay_del(value v_th, value v_item)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        elm_theme_overlay_del(th, String_val(v_item));
        return Val_unit;
}

PREFIX value ml_elm_theme_overlay_list_get(value v_th)
{
        return copy_Eina_List_string(elm_theme_overlay_list_get(
                Elm_Theme_val(v_th)));
}

PREFIX value ml_elm_theme_extension_add(value v_th, value v_item)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        elm_theme_extension_add(th, String_val(v_item));
        return Val_unit;
}

PREFIX value ml_elm_theme_extension_del(value v_th, value v_item)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        elm_theme_extension_del(th, String_val(v_item));
        return Val_unit;
}

PREFIX value ml_elm_theme_extension_list_get(value v_th)
{
        return copy_Eina_List_string(elm_theme_extension_list_get(
                Elm_Theme_val(v_th)));
}

PREFIX value ml_elm_theme_set(value v_th, value v_theme)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        elm_theme_set(th, String_val(v_theme));
        return Val_unit;
}

PREFIX value ml_elm_theme_get(value v_th, value v_unit)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        return copy_string(elm_theme_get(th));
}

PREFIX value ml_elm_theme_list_get(value v_th)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        return copy_Eina_List_string(elm_theme_list_get(th));
}

PREFIX value ml_elm_theme_list_item_path_get(value v_f)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_Bool flag;
        char* path = elm_theme_list_item_path_get(String_val(v_f), &flag);
        if(path == NULL) v = Val_int(0);
        else {
                v1 = caml_alloc(2, 0);
                Store_field(v1, 0, copy_string(path));
                Store_field(v1, 1, Val_Eina_Bool(flag));
                v = caml_alloc(1, 0);
                Store_field(v, 0, v1);
                free(path);
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_theme_flush(value v_th, value v_unit)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        elm_theme_flush(th);
        return Val_unit;
}

PREFIX value ml_elm_theme_full_flush(value v_unit)
{
        elm_theme_full_flush();
        return Val_unit;
}

PREFIX value ml_elm_theme_name_available_list_get(value v_unit)
{
        Eina_List* list = elm_theme_name_available_list_new();
        value v_list = copy_Eina_List_string(list);
        elm_theme_name_available_list_free(list);
        return v_list;
}

PREFIX value ml_elm_theme_data_get(value v_th, value v_key)
{
        CAMLparam2(v_th, v_key);
        CAMLlocal1(v_data);
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        const char* data = elm_theme_data_get(th, String_val(v_key));
        if(data == NULL) v_data = Val_int(0);
        else {
                v_data = caml_alloc(1, 0);
                Store_field(v_data, 0, copy_string(data));
        }
        CAMLreturn(v_data);
}

PREFIX value ml_elm_theme_group_path_find(value v_th, value v_path)
{
        CAMLparam2(v_th, v_path);
        CAMLlocal1(v_data);
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        const char* data = elm_theme_group_path_find(th, String_val(v_path));
        if(data == NULL) v_data = Val_int(0);
        else {
                v_data = caml_alloc(1, 0);
                Store_field(v_data, 0, copy_string(data));
        }
        CAMLreturn(v_data);
}

PREFIX value ml_elm_theme_group_base_list(value v_th, value v_base)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = Elm_Theme_val(Field(v_th, 0));
        Eina_List* list = elm_theme_group_base_list(th, String_val(v_base));
        value v_list = copy_Eina_List_string(list);
        Eina_List* l;
        char* data;
        EINA_LIST_FOREACH(list, l, data) eina_stringshare_del(data);
        eina_list_free(list);
        return v_list;
}

PREFIX value ml_elm_theme_system_dir_get(value v_unit)
{
        return copy_string(elm_theme_system_dir_get());
}

PREFIX value ml_elm_theme_user_dir_get(value v_unit)
{
        return copy_string(elm_theme_user_dir_get());
}

