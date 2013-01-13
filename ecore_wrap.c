#include "include.h"

PREFIX void ml_Ecore_Cb_1(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = (value*) data;
        v_fun = Field(*v_data, 1);
        caml_callback(v_fun, Val_unit);
        CAMLreturn0;
}

