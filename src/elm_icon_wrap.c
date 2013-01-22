#include "include.h"

PREFIX inline Elm_Icon_Type Elm_Icon_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_ICON_NONE;
                case Val_file: return ELM_ICON_FILE;
                case Val_standard: return ELM_ICON_STANDARD;
        }
        caml_failwith("Elm_Icon_Type_val");
        return ELM_ICON_NONE;
}

PREFIX inline value Val_Elm_Icon_Type(Elm_Icon_Type ty)
{
        switch(ty) {
                case ELM_ICON_NONE: return Val_none;
                case ELM_ICON_FILE: return Val_file;
                case ELM_ICON_STANDARD: return Val_standard;
        }
        caml_failwith("Val_Elm_Icon_Type");
        return Val_none;
}

PREFIX inline Elm_Icon_Lookup_Order Elm_Icon_Lookup_Order_val(value v_o)
{
        switch(v_o) {
                case Val_fdo_theme: return ELM_ICON_LOOKUP_FDO_THEME;
                case Val_theme_fdo: return ELM_ICON_LOOKUP_THEME_FDO;
                case Val_fdo: return ELM_ICON_LOOKUP_FDO;
                case Val_theme: return ELM_ICON_LOOKUP_THEME;
        }
        caml_failwith("Elm_Icon_Lookup_Order_val");
        return ELM_ICON_LOOKUP_FDO_THEME;
}

PREFIX inline value Val_Elm_Icon_Lookup_Order(Elm_Icon_Lookup_Order o)
{
        switch(o) {
                case ELM_ICON_LOOKUP_FDO_THEME: return Val_fdo_theme;
                case ELM_ICON_LOOKUP_THEME_FDO: return Val_theme_fdo;
                case ELM_ICON_LOOKUP_FDO: return Val_fdo;
                case ELM_ICON_LOOKUP_THEME: return Val_theme;
        }
        caml_failwith("Val_Elm_Icon_Lookup_Order");
        return Val_fdo_theme;
}

PREFIX value ml_elm_icon_add(value v_parent)
{
        Evas_Object* icon = elm_icon_add((Evas_Object*) v_parent);
        if(icon == NULL) caml_failwith("elm_icon_add");
        return (value) icon;
}

PREFIX value ml_elm_icon_thumb_set(value v_obj, value v_file, value v_group)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        elm_icon_thumb_set((Evas_Object*) v_obj, String_val(v_file), group);
        return Val_unit;
}

PREFIX value ml_elm_icon_standard_set_with_bool(value v_icon, value v_name)
{
        return Val_Eina_Bool(elm_icon_standard_set((Evas_Object*) v_icon,
                String_val(v_name)));
}

PREFIX value ml_elm_icon_standard_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* name = elm_icon_standard_get((Evas_Object*) v_obj);
        if(name == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(name));
        }
        CAMLreturn(v);
}



