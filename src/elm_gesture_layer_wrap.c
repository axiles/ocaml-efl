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

