#include "include.h"

PREFIX value ml_elm_mapbuf_add(value v_parent)
{
        Evas_Object* mapbuf = elm_mapbuf_add((Evas_Object*) v_parent);
        if(mapbuf == NULL) caml_failwith("elm_mapbuf_add");
        return (value) mapbuf;
}

PREFIX value ml_elm_mapbuf_enabled_set(value v_obj, value v_flag)
{
        elm_mapbuf_enabled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_enabled_get(value v_obj)
{
        return Val_bool(elm_mapbuf_enabled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_smooth_set(value v_obj, value v_flag)
{
        elm_mapbuf_smooth_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_smooth_get(value v_obj)
{
        return Val_bool(elm_mapbuf_smooth_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_alpha_set(value v_obj, value v_flag)
{
        elm_mapbuf_alpha_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_alpha_get(value v_obj)
{
        return Val_bool(elm_mapbuf_alpha_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_mapbuf_auto_set(value v_obj, value v_flag)
{
        elm_mapbuf_auto_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_mapbuf_auto_get(value v_obj)
{
        return Val_bool(elm_mapbuf_auto_get((Evas_Object*) v_obj));
}

