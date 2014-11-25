#include "include.h"

PREFIX value ml_elm_notify_add(value v_parent)
{
        Evas_Object* obj = elm_notify_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_notify_add");
        return (value) obj;
}

/*PREFIX value ml_elm_notify_parent_set(value v_obj, value v_parent)
{
        elm_notify_parent_set((Evas_Object*) v_obj, (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_notify_parent_get(value v_obj)
{
        return (value) elm_notify_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_notify_align_set(value v_obj, value v_h, value v_v)
{
        elm_notify_align_set((Evas_Object*) v_obj, Double_val(v_h),
                Double_val(v_v));
        return Val_unit;
}
*/
PREFIX value ml_elm_notify_align_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_res);
        double h, v;
        elm_notify_align_get((Evas_Object*) v_obj, &h, &v);
        v_res = caml_alloc(2, 0);
        Store_field(v_res, 0, copy_double(h));
        Store_field(v_res, 1, copy_double(v));
        CAMLreturn(v_res);
}

/*PREFIX value ml_elm_notify_timeout_set(value v_obj, value v_time)
{
        elm_notify_timeout_set((Evas_Object*) v_obj, Double_val(v_time));
        return Val_unit;
}

PREFIX value ml_elm_notify_timeout_get(value v_obj)
{
        return copy_double(elm_notify_timeout_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_notify_allow_events_set(value v_obj, value v_flag)
{
        elm_notify_allow_events_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_notify_allow_events_get(value v_obj)
{
        return Val_Eina_Bool(elm_notify_allow_events_get((Evas_Object*) v_obj));
}
*/
