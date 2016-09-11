#include "include.h"

PREFIX value ml_elm_frame_add(value v_parent)
{
        Evas_Object* frame = elm_frame_add(Evas_Object_val(v_parent));
        if(frame == NULL) caml_failwith("elm_frame_add");
        return copy_Evas_Object(frame);
}

