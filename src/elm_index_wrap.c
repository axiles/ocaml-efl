#include "include.h"

PREFIX value ml_elm_index_add(value v_parent)
{
        Evas_Object* obj = elm_index_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_index_add");
        return (value) obj;
}

PREFIX value ml_elm_index_autohide_disabled_set(value v_obj, value v_flag)
{
        elm_index_autohide_disabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value  ml_elm_index_autohide_disabled_get(value v_obj)
{
        return Val_bool(elm_index_autohide_disabled_get((Evas_Object*) v_obj));
}

