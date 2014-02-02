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

PREFIX inline struct tm Tm_val(value v)
{
        struct tm t;
        t.tm_sec = Int_val(Field(v, 0));
        t.tm_min = Int_val(Field(v, 1));
        t.tm_hour = Int_val(Field(v, 2));
        t.tm_mday = Int_val(Field(v, 3));
        t.tm_mon = Int_val(Field(v, 4));
        t.tm_year = Int_val(Field(v, 5));
        t.tm_wday = Int_val(Field(v, 6));
        t.tm_yday = Int_val(Field(v, 7));
        t.tm_isdst = Bool_val(Field(v, 8));
        return t;
}

PREFIX inline value copy_tm(struct tm t)
{
        value v = caml_alloc(9, 0);
        Store_field(v, 0, Val_int(t.tm_sec));
        Store_field(v, 1, Val_int(t.tm_min));
        Store_field(v, 2, Val_int(t.tm_hour));
        Store_field(v, 3, Val_int(t.tm_mday));
        Store_field(v, 4, Val_int(t.tm_mon));
        Store_field(v, 5, Val_int(t.tm_year));
        Store_field(v, 6, Val_int(t.tm_wday));
        Store_field(v, 7, Val_int(t.tm_yday));
        Store_field(v, 8, Val_bool(t.tm_isdst));
        return v;
}

PREFIX inline Elm_Calendar_Mark_Repeat_Type Elm_Calendar_Mark_Repeat_Type_val(
        value v)
{
        switch(v) {
                case Val_unique: return ELM_CALENDAR_UNIQUE;
                case Val_daily: return ELM_CALENDAR_DAILY;
                case Val_weekly: return ELM_CALENDAR_WEEKLY;
                case Val_monthly: return ELM_CALENDAR_MONTHLY;
                case Val_annually: return ELM_CALENDAR_ANNUALLY;
                case Val_last_day_of_month:
                        return ELM_CALENDAR_LAST_DAY_OF_MONTH;
                default: break;
        }
        caml_failwith("Elm_Calendar_Mark_Repeat_Type_val");
        return ELM_CALENDAR_UNIQUE;
}

PREFIX inline value copy_Eina_List_Elm_Calendar_Mark(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Calendar_Mark* mark;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, mark) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) mark);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX inline Elm_Calendar_Weekday Elm_Calendar_Weekday_val(value v)
{
        switch(v) {
                case Val_sunday: return ELM_DAY_SUNDAY;
                case Val_monday: return ELM_DAY_MONDAY;
                case Val_tuesday: return ELM_DAY_TUESDAY;
                case Val_wednesday: return ELM_DAY_WEDNESDAY;
                case Val_thursday: return ELM_DAY_THURSDAY;
                case Val_friday: return ELM_DAY_FRIDAY;
                case Val_saturday: return ELM_DAY_SATURDAY;
                case Val_last: return ELM_DAY_LAST;
                default: break;
        }
        caml_failwith("Elm_Calendar_Weekday_val");
        return ELM_DAY_SUNDAY;
}

PREFIX inline value Val_Elm_Calendar_Weekday(Elm_Calendar_Weekday d)
{
        switch(d) {
                case ELM_DAY_SUNDAY: return Val_sunday;
                case ELM_DAY_MONDAY: return Val_monday;
                case ELM_DAY_TUESDAY: return Val_tuesday;
                case ELM_DAY_WEDNESDAY: return Val_wednesday;
                case ELM_DAY_THURSDAY: return Val_thursday;
                case ELM_DAY_FRIDAY: return Val_friday;
                case ELM_DAY_SATURDAY: return Val_saturday;
                case ELM_DAY_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Calendar_Weekday");
        return Val_monday;
}

PREFIX inline Elm_Calendar_Selectable Elm_Calendar_Selectable_val(value v)
{
        switch(v) {
                case Val_year: return ELM_CALENDAR_SELECTABLE_YEAR;
                case Val_month: return ELM_CALENDAR_SELECTABLE_MONTH;
                case Val_day: return ELM_CALENDAR_SELECTABLE_DAY;
                default: break;
        }
        caml_failwith("Elm_Calendar_Selectable_val");
        return ELM_CALENDAR_SELECTABLE_YEAR;
}

PREFIX inline Elm_Calendar_Selectable Elm_Calendar_Selectable_val_list(value v)
{
        value v_tmp = v;
        Elm_Calendar_Selectable s = ELM_CALENDAR_SELECTABLE_NONE;
        while(v_tmp != Val_int(0)) {
                s = s | Elm_Calendar_Selectable_val(Field(v_tmp, 0));
                v_tmp = Field(v_tmp, 1);
        }
        return s;
}

PREFIX inline value copy_Elm_Calendar_Selectable(Elm_Calendar_Selectable s)
{
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_bool(s & ELM_CALENDAR_SELECTABLE_YEAR));
        Store_field(v, 1, Val_bool(s & ELM_CALENDAR_SELECTABLE_MONTH));
        Store_field(v, 2, Val_bool(s & ELM_CALENDAR_SELECTABLE_DAY));
        return v;
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

PREFIX value ml_elm_calendar_selectable_set(value v_obj, value v_s)
{
        elm_calendar_selectable_set((Evas_Object*) v_obj,
                Elm_Calendar_Selectable_val_list(v_s));
        return Val_unit;
}

PREFIX value ml_elm_calendar_selectable_get(value v_obj)
{
        return copy_Elm_Calendar_Selectable(elm_calendar_selectable_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_calendar_displayed_time_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_t);
        struct tm t;
        Eina_Bool flag = elm_calendar_displayed_time_get((Evas_Object*) v_obj,
                &t);
        if(flag) {
                v_t = caml_alloc(1, 0);
                Store_field(v_t, 0, copy_tm(t));
        } else v_t = Val_int(0);
        CAMLreturn(v_t);
}

PREFIX value ml_elm_calendar_selected_time_set(value v_obj, value v_t)
{
        struct tm t = Tm_val(v_t);
        elm_calendar_selected_time_set((Evas_Object*) v_obj, &t);
        return Val_unit;
}

PREFIX value ml_elm_calendar_selected_time_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_t);
        struct tm t;
        Eina_Bool flag = elm_calendar_selected_time_get((Evas_Object*) v_obj,
                &t);
        if(flag) {
                v_t = caml_alloc(1, 0);
                Store_field(v_t, 0, copy_tm(t));
        } else v_t = Val_int(0);
        CAMLreturn(v_t);
}

PREFIX value ml_elm_calendar_mark_add(
        value v_obj, value v_m_type, value v_m_time, value v_repeat)
{
        struct tm m_time = Tm_val(v_m_time);
        Elm_Calendar_Mark* m = elm_calendar_mark_add(
                (Evas_Object*) v_obj, String_val(v_m_type), &m_time,
                Elm_Calendar_Mark_Repeat_Type_val(v_repeat));
        if(m == NULL) caml_failwith("elm_calendar_mark_add");
        return (value) m;
}

PREFIX value ml_elm_calendar_mark_del(value v_m)
{
        elm_calendar_mark_del((Elm_Calendar_Mark*) v_m);
        return Val_unit;
}

PREFIX value ml_elm_calendar_marks_clear(value v_obj)
{
        elm_calendar_marks_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_calendar_marks_get(value v_obj)
{
        return copy_Eina_List_Elm_Calendar_Mark(elm_calendar_marks_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_calendar_marks_draw(value v_obj)
{
        elm_calendar_marks_draw((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_calendar_interval_set(value v_obj, value v_x)
{
        elm_calendar_interval_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_calendar_interval_get(value v_obj)
{
        return copy_double(elm_calendar_interval_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_calendar_first_day_of_week_set(value v_obj, value v_d)
{
        elm_calendar_first_day_of_week_set((Evas_Object*) v_obj,
                Elm_Calendar_Weekday_val(v_d));
        return Val_unit;
}

PREFIX value ml_elm_calendar_first_day_of_week_get(value v_obj)
{
        return Val_Elm_Calendar_Weekday(elm_calendar_first_day_of_week_get(
                (Evas_Object*) v_obj));
}

