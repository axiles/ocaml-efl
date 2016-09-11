#include "elm_icon_wrap.h"

PREFIX value ml_elm_icon_add(value v_parent)
{
        Evas_Object* icon = elm_icon_add(Evas_Object_val(v_parent));
        if(icon == NULL) caml_failwith("elm_icon_add");
        return copy_Evas_Object(icon);
}

PREFIX value ml_elm_icon_thumb_set(value v_obj, value v_file, value v_group)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        elm_icon_thumb_set(Evas_Object_val(v_obj), String_val(v_file), group);
        return Val_unit;
}

PREFIX value ml_elm_icon_standard_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* name = elm_icon_standard_get(Evas_Object_val(v_obj));
        if(name == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(name));
        }
        CAMLreturn(v);
}

