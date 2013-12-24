#include "elm_tooltip_wrap.h"

PREFIX Evas_Object* ml_Elm_Tooltip_Item_Content_Cb_0(
        void* data, Evas_Object* obj, Evas_Object* tooltip, void* item)
{
        CAMLparam0Acquire();
        CAMLlocal2(v_fun, v_r);
        value* v_data = (value*) data;
        v_fun = Field(*v_data, 0);
        v_r = caml_callback2(v_fun, (value) obj, (value) tooltip);
        CAMLreturnTRelease(Evas_Object*, (Evas_Object*) v_r);
}

