#include "include.h"

inline Elm_Scroller_Movement_Block Elm_Scroller_Movement_Block_val_list(
        value v_list)
{
        value v = v_list;
        Elm_Scroller_Movement_Block r = ELM_SCROLLER_MOVEMENT_NO_BLOCK;
        while(v != Val_int(0)) {
                r = r | Elm_Scroller_Movement_Block_val(Field(v, 0));
                v = Field(v, 1);
        }
        return r;
}

inline value copy_Elm_Scroller_Movement_Block(Elm_Scroller_Movement_Block m)
{
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_bool(m & ELM_SCROLLER_MOVEMENT_BLOCK_VERTICAL));
        Store_field(v, 1, Val_bool(m & ELM_SCROLLER_MOVEMENT_BLOCK_HORIZONTAL));
        return v;
}

PREFIX value ml_elm_scroller_add(value v_parent)
{
        Evas_Object* obj = elm_scroller_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_scroller_add");
        return (value) obj;
}

PREFIX value ml_elm_scroller_policy_get(value v_obj)
{
        Elm_Scroller_Policy ph, pv;
        elm_scroller_policy_get((Evas_Object*) v_obj, &ph, &pv);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Elm_Scroller_Policy(ph));
        Store_field(v, 1, Val_Elm_Scroller_Policy(pv));
        return v;
}

PREFIX value ml_elm_scroller_region_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        elm_scroller_region_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_elm_scroller_child_size_get(value v_obj, value v_w, value v_h)
{
        Evas_Coord w, h;
        elm_scroller_child_size_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_elm_scroller_page_snap_get(value v_obj)
{
        Eina_Bool ph, pv;
        elm_scroller_page_snap_get((Evas_Object*) v_obj, &ph, &pv);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_bool(ph));
        Store_field(v_r, 1, Val_bool(pv));
        return v_r;
}

PREFIX value ml_elm_scroller_bounce_get(value v_obj)
{
        Eina_Bool h_bounce, v_bounce;
        elm_scroller_bounce_get((Evas_Object*) v_obj, &h_bounce, &v_bounce);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Eina_Bool(h_bounce));
        Store_field(v, 1, Val_Eina_Bool(v_bounce));
        return v;
}

PREFIX value ml_elm_scroller_page_relative_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double h, v;
        elm_scroller_page_relative_get((Evas_Object*) v_obj, &h, &v);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(h));
        Store_field(v_r, 1, copy_double(v));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_scroller_page_size_get(value v_obj)
{
        Evas_Coord h, v;
        elm_scroller_page_size_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

PREFIX value ml_elm_scroller_page_scroll_limit_get(value v_obj)
{
        Evas_Coord lph, lpv;
        elm_scroller_page_scroll_limit_get((Evas_Object*) v_obj, &lph, &lpv);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(lph));
        Store_field(v_r, 1, Val_int(lpv));
        return v_r;
}

PREFIX value ml_elm_scroller_current_page_get(value v_obj)
{
        Evas_Coord h, v;
        elm_scroller_current_page_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

PREFIX value ml_elm_scroller_last_page_get(value v_obj)
{
        Evas_Coord h, v;
        elm_scroller_last_page_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

PREFIX value ml_elm_scroller_gravity_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double x, y;
        elm_scroller_gravity_get((Evas_Object*) v_obj, &x, &y);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(x));
        Store_field(v_r, 1, copy_double(y));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_scroller_step_size_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        Evas_Coord x, y;
        elm_scroller_step_size_get(Evas_Object_val(v_obj), &x, &y);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        CAMLreturn(v_r);
}

