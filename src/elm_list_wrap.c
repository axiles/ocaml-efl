#include "include.h"

PREFIX value ml_elm_list_add(value v_parent)
{
        Evas_Object* obj = elm_list_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_list_add");
        return (value) obj;
}

PREFIX value ml_elm_list_go(value v_obj)
{
        elm_list_go((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_list_multi_select_set(value v_obj, value v_flag)
{
        elm_list_multi_select_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

