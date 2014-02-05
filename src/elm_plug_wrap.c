#include "include.h"

PREFIX value ml_elm_plug_add(value v_parent)
{
        Evas_Object* plug = elm_plug_add((Evas_Object*) v_parent);
        if(plug == NULL) caml_failwith("elm_plug_add");
        return (value) plug;
}

PREFIX value ml_elm_plug_connect(
        value v_obj, value v_name, value v_num, value v_sys)
{
        return Val_bool(elm_plug_connect((Evas_Object*) v_obj,
                String_val(v_name), Int_val(v_num), Bool_val(v_sys)));
}

