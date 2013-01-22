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
