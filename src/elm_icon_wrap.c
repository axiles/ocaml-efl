#include "elm_icon_wrap.h"

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

PREFIX value ml_elm_icon_standard_set(value v_icon, value v_name)
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

PREFIX value ml_elm_icon_order_lookup_set(value v_obj, value v_order)
{
        elm_icon_order_lookup_set((Evas_Object*) v_obj,
                Elm_Icon_Lookup_Order_val(v_order));
        return Val_unit;
}

PREFIX value ml_elm_icon_order_lookup_get(value v_obj)
{
        return Val_Elm_Icon_Lookup_Order(elm_icon_order_lookup_get(
                (Evas_Object*) v_obj));
}

