#include "include.h"

PREFIX value ml_elm_hover_add(value v_parent)
{
        Evas_Object* obj = elm_hover_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_hover_add");
        return (value) obj;
}

PREFIX value ml_elm_hover_target_set(value v_obj, value v_target)
{
        elm_hover_target_set((Evas_Object*) v_obj, (Evas_Object*) v_target);
        return Val_unit;
}

PREFIX value ml_elm_hover_target_get(value v_obj)
{
        Evas_Object* target = elm_hover_target_get((Evas_Object*) v_obj);
        if(target == NULL) caml_failwith("elm_hover_target_get");
        return (value) target;
}

