#include "include.h"

PREFIX value ml_elm_fileselector_add(value v_parent)
{
        Evas_Object* obj = elm_fileselector_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_fileselector");
        return (value) obj;
}

PREFIX value ml_elm_fileselector_is_save_set(value v_obj, value v_flag)
{
        elm_fileselector_is_save_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}
