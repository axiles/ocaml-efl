#include "include.h"

PREFIX value ml_elm_multibuttonentry_add(value v_parent)
{
        Evas_Object* obj = elm_multibuttonentry_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_multibuttonentry_add");
        return (value) obj;
}

PREFIX value ml_elm_multibuttonentry_entry_get(value v_obj)
{
        return copy_Evas_Object_opt(elm_multibuttonentry_entry_get(
                (Evas_Object*) v_obj));
}

