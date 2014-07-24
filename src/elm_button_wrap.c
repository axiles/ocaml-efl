#include "include.h"

PREFIX value ml_elm_button_add(value v_parent)
{
        Evas_Object* button = elm_button_add((Evas_Object*) v_parent);
        if(button == NULL) caml_failwith("elm_button_add");
        return (value) button;
}

/*PREFIX value ml_elm_button_autorepeat_gap_timeout_get(value v_button)
{
        return copy_double(elm_button_autorepeat_gap_timeout_get(
                (Evas_Object*) v_button));
}

PREFIX value ml_elm_button_autorepeat_gap_timeout_set(value v_button, value v_t)
{
        elm_button_autorepeat_gap_timeout_set((Evas_Object*) v_button,
                Double_val(v_t));
        return Val_unit;
}*/

/*PREFIX value ml_elm_button_autorepeat_get(value v_button)
{
        return Val_Eina_Bool(elm_button_autorepeat_get(
                (Evas_Object*) v_button));
}*/

/*PREFIX value ml_elm_button_autorepeat_initial_timeout_get(value v_button)
{
        return copy_double(elm_button_autorepeat_initial_timeout_get(
                (Evas_Object*) v_button));
}

PREFIX value ml_elm_button_autorepeat_initial_timeout_set(
        value v_button, value v_t)
{
        elm_button_autorepeat_initial_timeout_set((Evas_Object*) v_button,
                Double_val(v_t));
        return Val_unit;
}*/

/*PREFIX value ml_elm_button_autorepeat_set(value v_button, value v_flag)
{
        elm_button_autorepeat_set((Evas_Object*) v_button,
                Eina_Bool_val(v_flag));
        return Val_unit;
}*/

