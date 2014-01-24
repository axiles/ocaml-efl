#include "include.h"

PREFIX value ml_elm_diskselector_add(Evas_Object* v_parent)
{
        Evas_Object* diskselector = elm_diskselector_add(
                (Evas_Object*) v_parent);
        if(diskselector == NULL) caml_failwith("elm_diskselector_add");
        return (value) diskselector;
}

PREFIX value ml_elm_diskselector_round_enabled_set(value v_obj, value v_flag)
{
        elm_diskselector_round_enabled_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_diskselector_round_enabled_get(value v_obj)
{
        return Val_bool(elm_diskselector_round_enabled_get(
                (Evas_Object*) v_obj));
}

