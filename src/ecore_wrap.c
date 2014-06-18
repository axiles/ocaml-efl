#include "include.h"

inline Ecore_Pos_Map Ecore_Pos_Map_val(value v)
{
        switch(v) {
                case Val_linear: return ECORE_POS_MAP_LINEAR;
                case Val_accelerate: return ECORE_POS_MAP_ACCELERATE;
                case Val_decelerate: return ECORE_POS_MAP_DECELERATE;
                case Val_sinusoidal: return ECORE_POS_MAP_SINUSOIDAL;
                case Val_accelerate_factor:
                        return ECORE_POS_MAP_ACCELERATE_FACTOR;
                case Val_decelerate_factor:
                        return ECORE_POS_MAP_DECELERATE_FACTOR;
                case Val_sinusoidal_factor:
                        return ECORE_POS_MAP_SINUSOIDAL_FACTOR;
                case Val_divisor_interp: return ECORE_POS_MAP_DIVISOR_INTERP;
                case Val_bounce: return ECORE_POS_MAP_BOUNCE;
                case Val_spring: return ECORE_POS_MAP_SPRING;
                case Val_cubic_bezier: return ECORE_POS_MAP_CUBIC_BEZIER;
                default: break;
        }
        caml_failwith("Ecore_Pos_Map_val");
        return ECORE_POS_MAP_LINEAR;
}

inline value Val_Ecore_Pos_Map_val(Ecore_Pos_Map m)
{
        switch(m) {
                case ECORE_POS_MAP_LINEAR: return Val_linear;
                case ECORE_POS_MAP_ACCELERATE: return Val_accelerate;
                case ECORE_POS_MAP_DECELERATE: return Val_decelerate;
                case ECORE_POS_MAP_SINUSOIDAL: return Val_sinusoidal;
                case ECORE_POS_MAP_ACCELERATE_FACTOR:
                        return Val_accelerate_factor;
                case ECORE_POS_MAP_DECELERATE_FACTOR:
                        return Val_decelerate_factor;
                case ECORE_POS_MAP_SINUSOIDAL_FACTOR:
                        return Val_sinusoidal_factor;
                case ECORE_POS_MAP_DIVISOR_INTERP: return Val_divisor_interp;
                case ECORE_POS_MAP_BOUNCE: return Val_bounce;
                case ECORE_POS_MAP_SPRING: return Val_spring;
                case ECORE_POS_MAP_CUBIC_BEZIER: return Val_cubic_bezier;
        }
        caml_failwith("Val_Ecore_Pos_Map");
        return Val_linear;
}

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

void* ml_Ecore_Cb(void* data)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, Val_unit);
        return data;
}

void ml_Ecore_Cb_1_free(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = (value*) data;
        v_fun = Field(*v_data, 1);
        caml_callback(v_fun, Val_unit);
        ml_remove_value(v_data);
        CAMLreturn0;
}

void ml_Ecore_Cb_free(void* data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_data = (value*) data;
        v_fun = *v_data;
        caml_callback(v_fun, Val_unit);
        ml_remove_value(v_data);
        CAMLreturn0;
}

Eina_Bool ml_Ecore_Task_Cb_free_on_last(void* data)
{
      
        value* v_fun = (value*) data;
        Eina_Bool b = Eina_Bool_val(caml_callback(*v_fun, Val_unit));
        if(!b) ml_remove_value(v_fun);
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
        caml_register_generational_global_root(data);
        Ecore_Timer* timer = ecore_timer_add(Double_val(v_x),
                ml_Ecore_Task_Cb_free_on_last, data);
        if(timer == NULL) {
                ml_remove_value(data);
                caml_failwith("ecore_timer_add");
        }
        return (value) v_fun;
}

PREFIX value ml_ecore_main_loop_thread_safe_call_sync(value v_fun)
{
        CAMLparam1(v_fun);
        Eina_Bool is_main_loop = eina_main_loop_is();
        if(!is_main_loop) caml_release_runtime_system();
        ecore_main_loop_thread_safe_call_sync(ml_Ecore_Cb, &v_fun);
        if(!is_main_loop) caml_acquire_runtime_system();
        CAMLreturn(Val_unit);
}


