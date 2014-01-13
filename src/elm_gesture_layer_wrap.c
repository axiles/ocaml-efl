#include "include.h"

PREFIX inline Elm_Gesture_Type Elm_Gesture_Type_val(value v)
{
        switch(v) {
                case Val_n_taps: return ELM_GESTURE_N_TAPS;
                case Val_n_long_taps: return ELM_GESTURE_N_LONG_TAPS;
                case Val_n_double_taps: return ELM_GESTURE_N_DOUBLE_TAPS;
                case Val_n_triple_taps: return ELM_GESTURE_N_TRIPLE_TAPS;
                case Val_momentum: return ELM_GESTURE_MOMENTUM;
                case Val_n_lines: return ELM_GESTURE_N_LINES;
                case Val_n_flicks: return ELM_GESTURE_N_FLICKS;
                case Val_zoom: return ELM_GESTURE_ZOOM;
                case Val_rotate: return ELM_GESTURE_ROTATE;
                default: break;
        }
        caml_failwith("Elm_Gsture_Type_val");
        return ELM_GESTURE_N_TAPS;
}

PREFIX inline Elm_Gesture_State Elm_Gesture_State_val(value v)
{
        switch(v) {
                case Val_undefined: return ELM_GESTURE_STATE_UNDEFINED;
                case Val_start: return ELM_GESTURE_STATE_START;
                case Val_move: return ELM_GESTURE_STATE_MOVE;
                case Val_end: return ELM_GESTURE_STATE_END;
                case Val_abort: return ELM_GESTURE_STATE_ABORT;
                default: break;
        }
        caml_failwith("Elm_Gesture_State_val");
        return ELM_GESTURE_STATE_UNDEFINED;
}

PREFIX Evas_Event_Flags ml_Elm_Gesture_Event_Cb(void* data, void* event_info)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) event_info);
        return EVAS_EVENT_FLAG_ON_HOLD;
}

