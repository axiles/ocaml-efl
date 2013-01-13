#include "include.h"

PREFIX void ml_Ecore_Cb_1_free(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = (value*) data;
        v_fun = Field(*v_data, 1);
        caml_callback(v_fun, Val_unit);
        caml_remove_global_root(v_data);
        free(v_data);
        CAMLreturn0;
}

PREFIX void ml_Ecore_Cb_free(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = (value*) data;
        v_fun = *v_data;
        caml_callback(v_fun, Val_unit);
        caml_remove_global_root(v_data);
        free(v_data);
        CAMLreturn0;
}

