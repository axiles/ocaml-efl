#include "include.h"

 Elm_Clock_Edit_Mode Elm_Clock_Edit_Mode_val_list(value v)
{
        value v_tmp = v;
        Elm_Clock_Edit_Mode m = ELM_CLOCK_EDIT_DEFAULT;
        while(v_tmp != Val_int(0)) {
                m = m | Elm_Clock_Edit_Mode_val(Field(v_tmp, 0));
                v_tmp = Field(v_tmp, 1);
        }
        return m;
}

 value copy_Elm_Clock_Edit_Mode(Elm_Clock_Edit_Mode m)
{
        value v = caml_alloc(8, 0);
        Store_field(v, 0, Val_bool((m == ELM_CLOCK_EDIT_DEFAULT)));
        Store_field(v, 1, Val_bool(m & ELM_CLOCK_EDIT_HOUR_DECIMAL));
        Store_field(v, 2, Val_bool(m & ELM_CLOCK_EDIT_HOUR_UNIT));
        Store_field(v, 3, Val_bool(m & ELM_CLOCK_EDIT_MIN_DECIMAL));
        Store_field(v, 4, Val_bool(m & ELM_CLOCK_EDIT_MIN_UNIT));
        Store_field(v, 5, Val_bool(m & ELM_CLOCK_EDIT_SEC_DECIMAL));
        Store_field(v, 6, Val_bool(m & ELM_CLOCK_EDIT_SEC_UNIT));
        Store_field(v, 7, Val_bool(m & ELM_CLOCK_EDIT_ALL));
        return v;
}

PREFIX value ml_elm_clock_add(value v_parent)
{
        Evas_Object* obj = elm_clock_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_clock_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_clock_time_get(value v_obj)
{
        int h, m, s;
        elm_clock_time_get(Evas_Object_val(v_obj), &h, &m, &s);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(h));
        Store_field(v, 1, Val_int(m));
        Store_field(v, 2, Val_int(s));
        return v;
}

