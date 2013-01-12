#include "include.h"

PREFIX value ml_elm_radio_add(value v_parent)
{
        Evas_Object* obj = elm_radio_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_radio_add");
        return (value) obj;
}

PREFIX value ml_elm_radio_group_add(value v_obj, value v_group)
{
        elm_radio_group_add((Evas_Object*) v_obj, (Evas_Object*) v_group);
        return Val_unit;
}

PREFIX value ml_elm_radio_state_value_set(value v_obj, value v_v)
{
        elm_radio_state_value_set((Evas_Object*) v_obj, Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_radio_value_set(value v_obj, value v_v)
{
        elm_radio_value_set((Evas_Object*) v_obj, Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_radio_value_get(value v_obj)
{
        return Val_int(elm_radio_value_get((Evas_Object*) v_obj));
}

