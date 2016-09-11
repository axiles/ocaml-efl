#include "include.h"

PREFIX value ml_elm_route_add(value v_parent)
{
        Evas_Object* route = elm_route_add(Evas_Object_val(v_parent));
        if(route == NULL) caml_failwith("elm_route_add");
        return copy_Evas_Object(route);
}

PREFIX value ml_elm_route_longitude_min_max_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double min, max;
        elm_route_longitude_min_max_get(Evas_Object_val(v_obj), &min, &max);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(min));
        Store_field(v_r, 1, copy_double(max));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_route_latitude_min_max_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double min, max;
        elm_route_latitude_min_max_get(Evas_Object_val(v_obj), &min, &max);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(min));
        Store_field(v_r, 1, copy_double(max));
        CAMLreturn(v_r);
}

