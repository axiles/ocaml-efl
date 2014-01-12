#include "include.h"

PREFIX value ml_elm_theme_new(value v_unit)
{
        return (value) elm_theme_new();
}

PREFIX value ml_elm_theme_free(value v_th)
{
        elm_theme_free((Elm_Theme*) v_th);
        return Val_unit;
}

PREFIX value ml_elm_theme_copy(value v_th, value v_thref)
{
        elm_theme_copy((Elm_Theme*) v_th, (Elm_Theme*) v_thref);
        return Val_unit;
}

PREFIX value ml_elm_theme_ref_set(value v_th, value v_thref)
{
        Elm_Theme* thref;
        if(v_thref == Val_int(0)) thref = NULL;
        else thref = (Elm_Theme*) Field(v_thref, 0);
        elm_theme_ref_set((Elm_Theme*) v_th, thref);
        return Val_unit;
}

PREFIX value ml_elm_theme_ref_get(value v_th)
{
        Elm_Theme* thref = elm_theme_ref_get((Elm_Theme*) v_th);
        if(thref == NULL) return Val_int(0);
        value v_thref = caml_alloc(1, 0);
        Store_field(v_thref, 0, (value) thref);
        return v_thref;
}

PREFIX value ml_elm_theme_default_get(value v_unit)
{
        return (value) elm_theme_default_get();
}

PREFIX value ml_elm_theme_overlay_add(value v_th, value v_item)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = (Elm_Theme*) Field(v_th, 0);
        elm_theme_overlay_add(th, String_val(v_item));
        return Val_unit;
}

PREFIX value ml_elm_theme_overlay_del(value v_th, value v_item)
{
        Elm_Theme* th;
        if(v_th == Val_int(0)) th = NULL;
        else th = (Elm_Theme*) Field(v_th, 0);
        elm_theme_overlay_del(th, String_val(v_item));
        return Val_unit;
}

PREFIX value ml_elm_theme_overlay_list_get(value v_th)
{
        return copy_Eina_List_string(elm_theme_overlay_list_get(
                (Elm_Theme*) v_th));
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

