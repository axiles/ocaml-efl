#include "include.h"

PREFIX value ml_elm_radio_add(value v_parent)
{
        Evas_Object* obj = elm_radio_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_radio_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_radio_selected_object_get(value v_obj)
{
        return copy_Evas_Object(elm_radio_selected_object_get(
                Evas_Object_val(v_obj)));
}

