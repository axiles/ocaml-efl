#include "include.h"

PREFIX void raise_not_X()
{
        static value* e = NULL;
        if(e == NULL) e = caml_named_value("Not_X exception");
        caml_raise_constant(*e);
}

PREFIX void raise_not_Wayland()
{
        static value* e = NULL;
        if(e == NULL) e = caml_named_value("Not_Wayland exception");
        caml_raise_constant(*e);
}

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

PREFIX value ml_ecore_x_window_focus(value v_win)
{
#ifdef HAVE_ELEMENTARY_X
        ecore_x_window_focus(Int_val(v_win));
#else
        raise_not_X();
#endif
        return Val_unit;
}

