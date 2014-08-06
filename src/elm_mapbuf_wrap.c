#include "include.h"

PREFIX value ml_elm_mapbuf_add(value v_parent)
{
        Evas_Object* mapbuf = elm_mapbuf_add((Evas_Object*) v_parent);
        if(mapbuf == NULL) caml_failwith("elm_mapbuf_add");
        return (value) mapbuf;
}

PREFIX value ml_elm_mapbuf_point_color_get(value v_obj, value v_idx)
{
        int r, g, b, a;
        elm_mapbuf_point_color_get((Evas_Object*) v_obj, Int_val(v_idx), &r, &g,
                &b, &a);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, r);
        Store_field(v, 1, g);
        Store_field(v, 2, b);
        Store_field(v, 3, a);
        return v;
}

