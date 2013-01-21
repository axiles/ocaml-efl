#include "include.h"

PREFIX value ml_elm_check_add(value v_parent)
{
        Evas_Object* obj = elm_check_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_check_add");
        return (value) obj;
}

PREFIX value ml_elm_check_state_set(value v_obj, value v_flag)
{
        elm_check_state_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_check_state_get(value v_obj)
{
        return Val_Eina_Bool(elm_check_state_get((Evas_Object*) v_obj));
}


