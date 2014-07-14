#include "include.h"

PREFIX value ml_elm_dayselector_add(value v_parent)
{
        Evas_Object* dayselector = elm_dayselector_add((Evas_Object*) v_parent);
        if(dayselector == NULL) caml_failwith("elm_dayselector_add");
        return (value) dayselector;
}

PREFIX value ml_elm_dayselector_day_selected_set(
        value v_obj, value v_day, value v_flag)
{
        elm_dayselector_day_selected_set((Evas_Object*) v_obj,
                Elm_Dayselector_Day_val(v_day), Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_dayselector_day_selected_get(value v_obj, value v_day)
{
        return Val_bool(elm_dayselector_day_selected_get(
                (Evas_Object*) v_obj, Elm_Dayselector_Day_val(v_day)));
}

PREFIX value ml_elm_dayselector_week_start_set(value v_obj, value v_day)
{
        elm_dayselector_week_start_set((Evas_Object*) v_obj,
                Elm_Dayselector_Day_val(v_day));
        return Val_unit;
}

PREFIX value ml_elm_dayselector_week_start_get(value v_obj)
{
        return Val_Elm_Dayselector_Day(elm_dayselector_week_start_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_dayselector_weekend_start_set(value v_obj, value v_day)
{
        elm_dayselector_weekend_start_set((Evas_Object*) v_obj,
                Elm_Dayselector_Day_val(v_day));
        return Val_unit;
}

PREFIX value ml_elm_dayselector_weekend_start_get(value v_obj)
{
        return Val_Elm_Dayselector_Day(elm_dayselector_weekend_start_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_dayselector_weekend_length_set(value v_obj, value v_x)
{
        elm_dayselector_weekend_length_set((Evas_Object*) v_obj, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_dayselector_weekend_length_get(value v_obj)
{
        return Val_int(elm_dayselector_weekend_length_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_dayselector_weekdays_names_set(value v_obj, value v_a)
{
        const char* a[7];
        if(Wosize_val(v_a) != 7)
                caml_failwith("elm_dayselector_weekdays_names_set");
        int i;
        for(i = 0; i < 7; i++) {
                a[i]= String_val(Field(v_a, i));
        }
        elm_dayselector_weekdays_names_set((Evas_Object*) v_obj, a);
        return Val_unit;
}

PREFIX value ml_elm_dayselector_weekdays_names_get(value v_obj)
{
        return copy_Eina_List_string(elm_dayselector_weekdays_names_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_Elm_Dayselector_Day_of_ptr(value v_ptr)
{
        Elm_Dayselector_Day d = (Elm_Dayselector_Day) v_ptr;
        return Val_Elm_Dayselector_Day(d);
}

