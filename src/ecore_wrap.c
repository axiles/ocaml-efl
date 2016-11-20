#include "include.h"

PREFIX void raise_not_X(void)
{
        static value* e = NULL;
        if(e == NULL) e = caml_named_value("Not_X exception");
        caml_raise_constant(*e);
}

PREFIX void raise_not_Wayland(void)
{
        static value* e = NULL;
        if(e == NULL) e = caml_named_value("Not_Wayland exception");
        caml_raise_constant(*e);
}

void ml_Ecore_Cb(void* data)
{
        value* v_fun = data;
        caml_callback(*v_fun, Val_unit);
}

void* ml_Ecore_Data_Cb(void* data)
{
        value* v_fun = data;
        caml_callback(*v_fun, Val_unit);
        return data;
}

void ml_Ecore_Cb_1_free(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = data;
        v_fun = Field(*v_data, 1);
        caml_callback(v_fun, Val_unit);
        ml_remove_value(v_data);
        CAMLreturn0;
}

void ml_Ecore_Cb_free(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = data;
        v_fun = *v_data;
        caml_callback(v_fun, Val_unit);
        ml_remove_value(v_data);
        CAMLreturn0;
}

Eina_Bool ml_Ecore_Task_Cb_free_on_last(void* data)
{
      
        value* v_fun = data;
        Eina_Bool b = Eina_Bool_val(caml_callback(*v_fun, Val_unit));
        if(!b) ml_remove_value(v_fun);
        return b;
}

Eina_Bool ml_Ecore_Event_Handler_Cb(void* data, int type, void* event)
{
        value* v_fun = data;
        value* v_event = event;
        value r = caml_callback2(*v_fun, Val_int(type), *v_event);
        return Bool_val(r);
}

void ml_Ecore_End_Cb_free(void* user_data, void *func_data)
{
        value* v_fun = func_data;
        value* v_user_data = user_data;
        caml_callback(*v_user_data, *v_fun);
        ml_remove_value(v_fun);
        ml_remove_value(v_user_data);
}

PREFIX value ml_ecore_x_window_focus(value v_win CAMLunused)
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
        caml_register_generational_global_root(data);
        Ecore_Timer* timer = ecore_timer_add(Double_val(v_x),
                ml_Ecore_Task_Cb_free_on_last, data);
        if(timer == NULL) {
                ml_remove_value(data);
                caml_failwith("ecore_timer_add");
        }
        return copy_Ecore_Timer(timer);
}

PREFIX value ml_ecore_timer_delay(value v_timer, value v_x)
{
        ecore_timer_delay(Ecore_Timer_val(v_timer), Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_ecore_main_loop_thread_safe_call_async(value v_fun)
{
        value* data = ml_register_value(v_fun);
        ecore_main_loop_thread_safe_call_async(ml_Ecore_Cb_free, data);
        return Val_unit;
}

PREFIX value ml_ecore_main_loop_thread_safe_call_sync(value v_fun)
{
        CAMLparam1(v_fun);
        Eina_Bool is_main_loop = eina_main_loop_is();
        if(!is_main_loop) caml_release_runtime_system();
        ecore_main_loop_thread_safe_call_sync(ml_Ecore_Data_Cb, &v_fun);
        if(!is_main_loop) caml_acquire_runtime_system();
        CAMLreturn(Val_unit);
}

PREFIX value ml_ecore_event_type_new(value v_unit CAMLunused)
{
        return Val_int(ecore_event_type_new());
}

PREFIX value ml_ecore_event_handler_add(value v_type, value v_cb)
{
        value* data = ml_register_value(v_cb);
        Ecore_Event_Handler* handler = ecore_event_handler_add(Int_val(v_type),
                ml_Ecore_Event_Handler_Cb, data);
        if(handler == NULL) caml_failwith("ecore_event_handler_add");
        return copy_Ecore_Event_Handler(handler);
}

PREFIX value ml_ecore_event_handler_del(value v_handler)
{
        value* data =
                ecore_event_handler_del(Ecore_Event_Handler_val(v_handler));
        if (data != NULL) ml_remove_value(data);
        return Val_unit;
}

PREFIX value ml_ecore_event_add(value v_type, value v_ev, value v_func_free)
{
        value* ev = ml_register_value(v_ev);
        value* data_func_free = ml_register_value(v_func_free);
        Ecore_Event* event = ecore_event_add(Int_val(v_type), ev,
                ml_Ecore_End_Cb_free, data_func_free);
        if(event == NULL) caml_failwith("ecore_event_add");
        return copy_Ecore_Event(event);
}

PREFIX value ml_ecore_event_del(value v_event)
{
        ecore_event_del(Ecore_Event_val(v_event));
        return Val_unit;
}

