#include "include.h"

PREFIX value ml_elm_glview_add(value v_parent)
{
        Evas_Object* glview = elm_glview_add((Evas_Object*) v_parent);
        if(glview == NULL) caml_failwith("elm_glview_add");
        return (value) glview;
}

PREFIX value ml_elm_glview_size_set(value v_obj, value v_w, value v_h)
{
        elm_glview_size_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_glview_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_glview_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_glview_gl_api_get(value v_obj)
{
        return (value) elm_glview_gl_api_get((Evas_Object*) v_obj);
}

