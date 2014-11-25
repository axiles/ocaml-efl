#include "include.h"

PREFIX value ml_elm_radio_add(value v_parent)
{
        Evas_Object* obj = elm_radio_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_radio_add");
        return (value) obj;
}

PREFIX value ml_elm_radio_selected_object_get(value v_obj)
{
        return (value) elm_radio_selected_object_get((Evas_Object*) v_obj);
}

