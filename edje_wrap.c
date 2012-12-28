#include "include.h"

PREFIX void ml_Edje_Signal_Cb(
        void* data, Evas_Object* obj, const char* emission, const char* source)
{
        CAMLparam0();
        CAMLlocal2(v_emission, v_source);
        value* v_fun = (value*) data;
        v_emission = copy_string(emission);
        v_source = copy_string(source);
        caml_callback3(*v_fun, (value) obj, v_emission, v_source);
        CAMLreturn0;
}

