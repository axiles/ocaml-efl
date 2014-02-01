#include "include.h"

PREFIX inline Elm_Calendar_Select_Mode Elm_Calendar_Select_Mode_val(value v_m)
{
        switch(v_m) {
                case Val_default: return ELM_CALENDAR_SELECT_MODE_DEFAULT;
                case Val_always: return ELM_CALENDAR_SELECT_MODE_ALWAYS;
                case Val_none: return ELM_CALENDAR_SELECT_MODE_NONE;
                case Val_ondemand: return ELM_CALENDAR_SELECT_MODE_ONDEMAND;
		default: break;
        }
        caml_failwith("Elm_Calendar_Select_Mode_val");
        return ELM_CALENDAR_SELECT_MODE_DEFAULT;
}

PREFIX inline value Val_Elm_Calendar_Select_Mode(Elm_Calendar_Select_Mode m)
{
        switch(m) {
                case ELM_CALENDAR_SELECT_MODE_DEFAULT: return Val_default;
                case ELM_CALENDAR_SELECT_MODE_ALWAYS: return Val_always;
                case ELM_CALENDAR_SELECT_MODE_NONE: return Val_none;
                case ELM_CALENDAR_SELECT_MODE_ONDEMAND: return Val_ondemand;
        }
        caml_failwith("Val_Elm_Calendar_Select_Mode");
        return Val_default;
}

PREFIX value ml_elm_calendar_add(value v_parent)
{
        Evas_Object* calendar = elm_calendar_add((Evas_Object*) v_parent);
        if(calendar == NULL) caml_failwith("elm_calendar_add");
        return (value) calendar;
}

PREFIX value ml_elm_calendar_weekdays_names_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_a);
        const char** a = elm_calendar_weekdays_names_get((Evas_Object*) v_obj);
        v_a = caml_alloc(7, 0);
        int i;
        for(i = 0; i < 7; i++) {
                Store_field(v_a, i, copy_string(a[i]));
        }
        CAMLreturn(v_a);
}

PREFIX value ml_elm_calendar_weekdays_names_set(value v_obj, value v_a)
{
        const char* a[7];
        if(Wosize_val(v_a) != 7)
                caml_failwith("elm_calendar_weekdays_names_set");
        int i;
        for(i = 0; i < 7; i++) {
                a[i]= String_val(Field(v_a, i));
        }
        elm_calendar_weekdays_names_set((Evas_Object*) v_obj, a);
        return Val_unit;
}

PREFIX value ml_elm_calendar_min_max_year_set(
        value v_obj, value v_min, value v_max)
{
        elm_calendar_min_max_year_set((Evas_Object*) v_obj, Int_val(v_min),
                Int_val(v_max));
        return Val_unit;
}

PREFIX value ml_elm_calendar_min_max_year_get(value v_obj)
{
        int min, max;
        elm_calendar_min_max_year_get((Evas_Object*) v_obj, &min, &max);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(min));
        Store_field(v_r, 1, Val_int(max));
        return v_r;
}

PREFIX value ml_elm_calendar_select_mode_set(value v_obj, value v_mode)
{
        elm_calendar_select_mode_set((Evas_Object*) v_obj,
                Elm_Calendar_Select_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_calendar_select_mode_get(value v_obj)
{
        return Val_Elm_Calendar_Select_Mode(elm_calendar_select_mode_get(
                (Evas_Object*) v_obj));
}

