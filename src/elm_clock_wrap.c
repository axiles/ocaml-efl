#include "include.h"

PREFIX inline Elm_Clock_Edit_Mode Elm_Clock_Edit_Mode_val(value v)
{
        switch(v) {
                case Val_default: return ELM_CLOCK_EDIT_DEFAULT;
                case Val_hour_decimal: return ELM_CLOCK_EDIT_HOUR_DECIMAL;
                case Val_hour_unit: return ELM_CLOCK_EDIT_HOUR_UNIT;
                case Val_min_decimal: return ELM_CLOCK_EDIT_MIN_DECIMAL;
                case Val_min_unit: return ELM_CLOCK_EDIT_MIN_UNIT;
                case Val_sec_decimal: return ELM_CLOCK_EDIT_SEC_DECIMAL;
                case Val_sec_unit: return ELM_CLOCK_EDIT_SEC_UNIT;
                case Val_all: return ELM_CLOCK_EDIT_ALL;
        }
        caml_failwith("Elm_Clock_Edit_Mode_val");
        return ELM_CLOCK_EDIT_DEFAULT;
}

PREFIX inline Elm_Clock_Edit_Mode Elm_Clock_Edit_Mode_val_list(value v)
{
        value v_tmp = v;
        Elm_Clock_Edit_Mode m = ELM_CLOCK_EDIT_DEFAULT;
        while(v_tmp != Val_int(0)) {
                m = m | Elm_Clock_Edit_Mode_val(Field(v_tmp, 0));
                v_tmp = Field(v_tmp, 1);
        }
        return m;
}

PREFIX inline value copy_Elm_Clock_Edit_Mode(Elm_Clock_Edit_Mode m)
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
        Evas_Object* obj = elm_clock_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_clock_add");
        return (value) obj;
}

PREFIX value ml_elm_clock_time_set(value v_obj, value v_h, value v_m, value v_s)
{
        elm_clock_time_set((Evas_Object*) v_obj, Int_val(v_h), Int_val(v_m),
                Int_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_clock_time_get(value v_obj)
{
        int h, m, s;
        elm_clock_time_get((Evas_Object*) v_obj, &h, &m, &s);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_int(h));
        Store_field(v, 1, Val_int(m));
        Store_field(v, 2, Val_int(s));
        return v;
}

PREFIX value ml_elm_clock_edit_set(value v_obj, value v_flag)
{
        elm_clock_edit_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_clock_edit_get(value v_obj)
{
        return Val_bool(elm_clock_edit_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_clock_edit_mode_set(value v_obj, value v_m)
{
        elm_clock_edit_mode_set((Evas_Object*) v_obj,
                Elm_Clock_Edit_Mode_val_list(v_m));
        return Val_unit;
}

PREFIX value ml_elm_clock_edit_mode_get(value v_obj)
{
        return copy_Elm_Clock_Edit_Mode(elm_clock_edit_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_clock_show_am_pm_set(value v_obj, value v_flag)
{
        elm_clock_show_am_pm_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_clock_show_am_pm_get(value v_obj)
{
        return Val_bool(elm_clock_show_am_pm_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_clock_show_seconds_set(value v_obj, value v_flag)
{
        elm_clock_show_seconds_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_clock_show_seconds_get(value v_obj)
{
        return Val_bool(elm_clock_show_seconds_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_clock_first_interval_set(value v_obj, value v_x)
{
        elm_clock_first_interval_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_clock_first_interval_get(value v_obj)
{
        return copy_double(elm_clock_first_interval_get((Evas_Object*) v_obj));
}

