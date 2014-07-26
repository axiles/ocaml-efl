#include "include.h"

PREFIX value ml_elm_mapbuf_add(value v_parent)
{
        Evas_Object* mapbuf = elm_mapbuf_add((Evas_Object*) v_parent);
        if(mapbuf == NULL) caml_failwith("elm_mapbuf_add");
        return (value) mapbuf;
}

