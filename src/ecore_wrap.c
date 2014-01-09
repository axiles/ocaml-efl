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

PREFIX void* ml_Ecore_Cb(void* data)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, Val_unit);
        return data;
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

PREFIX Eina_Bool ml_Ecore_Task_Cb(void* data)
{
      
        value* v_fun = (value*) data;
        Eina_Bool b = Eina_Bool_val(caml_callback(*v_fun, Val_unit));
      
        return b;
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

PREFIX value ml_ecore_timer_add(value v_x, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        Ecore_Timer* timer = ecore_timer_add(Double_val(v_x), ml_Ecore_Task_Cb,
                data);
        if(timer == NULL) {
                caml_remove_global_root(data);
                free(data);
                caml_failwith("ecore_timer_add");
        }
        return (value) v_fun;
}

PREFIX value ml_ecore_main_loop_thread_safe_call_sync(value v_fun)
{
        CAMLparam1(v_fun);
        caml_release_runtime_system();
        ecore_main_loop_thread_safe_call_sync(ml_Ecore_Cb, &v_fun);
        caml_acquire_runtime_system();
        CAMLreturn(Val_unit);
}


