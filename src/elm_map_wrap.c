#include "include.h"

PREFIX value ml_elm_map_add(Evas_Object* v_parent)
{
        Evas_Object* map = elm_map_add((Evas_Object*) v_parent);
        if(map == NULL) caml_failwith("elm_map_add");
        return (value) map;
}

PREFIX value ml_elm_map_zoom_set(value v_obj, value v_x)
{
        elm_map_zoom_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_map_zoom_get(value v_obj)
{
        return Val_int(elm_map_zoom_get((Evas_Object*) v_obj));
}

