#include "include.h"

PREFIX value ml_elm_toolbar_add(value v_parent)
{
        Evas_Object* obj = elm_toolbar_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_toolbar_add");
        return (value) obj;
}

PREFIX value ml_elm_toolbar_icon_size_set(value v_obj, value v_size)
{
        elm_toolbar_icon_size_set((Evas_Object*) v_obj, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_icon_size_get(value v_obj)
{
        return Val_int(elm_toolbar_icon_size_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_icon_order_lookup_set(value v_obj, value v_order)
{
        elm_toolbar_icon_order_lookup_set((Evas_Object*) v_obj,
                Elm_Icon_Lookup_Order_val(v_order));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_icon_order_lookup_get(value v_obj)
{
        return Val_Elm_Icon_Lookup_Order(elm_toolbar_icon_order_lookup_get(
                (Evas_Object*) v_obj));
}

