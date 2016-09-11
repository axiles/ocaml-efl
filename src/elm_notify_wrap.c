#include "include.h"

PREFIX value ml_elm_notify_add(value v_parent)
{
        Evas_Object* obj = elm_notify_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_notify_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_notify_align_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_res);
        double h, v;
        elm_notify_align_get(Evas_Object_val(v_obj), &h, &v);
        v_res = caml_alloc(2, 0);
        Store_field(v_res, 0, copy_double(h));
        Store_field(v_res, 1, copy_double(v));
        CAMLreturn(v_res);
}

