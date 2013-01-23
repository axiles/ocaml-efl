#include "include.h"

PREFIX inline Elm_Bg_Option Elm_Bg_Option_val(value v_o)
{
        switch(v_o) {
                case Val_center: return ELM_BG_OPTION_CENTER;
                case Val_scale: return ELM_BG_OPTION_SCALE;
                case Val_tile: return ELM_BG_OPTION_TILE;
                case Val_last: return ELM_BG_OPTION_LAST;
        }
        caml_failwith("Elm_Bg_Option_val");
        return ELM_BG_OPTION_CENTER;
}

PREFIX inline value Val_Elm_Bg_Option(Elm_Bg_Option o)
{
        switch(o) {
                case ELM_BG_OPTION_CENTER: return Val_center;
                case ELM_BG_OPTION_SCALE: return Val_scale;
                case ELM_BG_OPTION_TILE: return Val_tile;
                case ELM_BG_OPTION_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Bg_Option");
        return Val_center;
}

PREFIX value ml_elm_bg_add(value v_parent)
{
        Evas_Object* bg = elm_bg_add((Evas_Object*) v_parent);
        if(bg == NULL) caml_failwith("elm_bg_add");
        return (value) bg;
}

PREFIX value ml_elm_bg_file_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        return Val_Eina_Bool(elm_bg_file_set((Evas_Object*) v_obj,
                String_val(v_file), group));
}
        
PREFIX value ml_elm_bg_file_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        const char *file, *group;
        elm_bg_file_get((Evas_Object*) v_obj, &file, &group);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(file));
        if(group == NULL) v1 = Val_int(0);
        else {
                v1 = caml_alloc(1, 0);
                Store_field(v1, 0, copy_string(group));
        }
        Store_field(v, 1, v1);
        CAMLreturn(v);
}

PREFIX value ml_elm_bg_option_set(value v_obj, value v_option)
{
        elm_bg_option_set((Evas_Object*) v_obj, Elm_Bg_Option_val(v_option));
        return Val_unit;
}

PREFIX value ml_elm_bg_color_set(value v_obj, value v_r, value v_g, value v_b)
{
        elm_bg_color_set((Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g),
                Int_val(v_b));
        return Val_unit;
}

