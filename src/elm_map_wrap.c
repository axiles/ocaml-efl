#include "include.h"

PREFIX value ml_elm_map_add(Evas_Object* v_parent)
{
        Evas_Object* map = elm_map_add((Evas_Object*) v_parent);
        if(map == NULL) caml_failwith("elm_map_add");
        return (value) map;
}

