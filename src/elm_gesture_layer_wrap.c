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

PREFIX value ml_Elm_Gesture_Taps_Info_of_ptr(value v_ptr)
{
        Elm_Gesture_Taps_Info* info = (Elm_Gesture_Taps_Info*) v_ptr;
        value v_info = caml_alloc(3, 0);
        Store_field(v_info, 0, Val_int(info->y));
        Store_field(v_info, 1, Val_int(info->n));
        Store_field(v_info, 2, Val_int(info->timestamp));
        return v_info;
}

PREFIX value ml_Elm_Gesture_Momentum_Info_of_ptr(value v_ptr)
{
        Elm_Gesture_Momentum_Info* info = (Elm_Gesture_Momentum_Info*) v_ptr;
        value v_info = caml_alloc(9, 0);
        Store_field(v_info, 0, Val_int(info->x1));
        Store_field(v_info, 1, Val_int(info->y1));
        Store_field(v_info, 2, Val_int(info->x2));
        Store_field(v_info, 3, Val_int(info->y2));
        Store_field(v_info, 4, Val_int(info->tx));
        Store_field(v_info, 5, Val_int(info->ty));
        Store_field(v_info, 6, Val_int(info->mx));
        Store_field(v_info, 7, Val_int(info->my));
        Store_field(v_info, 8, Val_int(info->n));
        return v_info;
}

PREFIX value ml_Elm_Gesture_Line_Info_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_info);
        Elm_Gesture_Line_Info* info = (Elm_Gesture_Line_Info*) v_ptr;
        v_info = caml_alloc(2, 0);
        Elm_Gesture_Momentum_Info* momentum = &(info->momentum);
        Store_field(v_info, 0,
                ml_Elm_Gesture_Momentum_Info_of_ptr((value) momentum));
        Store_field(v_info, 1, copy_double(info->angle));
        CAMLreturn(v_info);
}

PREFIX value ml_Elm_Gesture_Zoom_Info_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_info);
        Elm_Gesture_Zoom_Info* info = (Elm_Gesture_Zoom_Info*) v_ptr;
        v_info = caml_alloc(4, 0);
        Store_field(v_info, 0, Val_int(info->y));
        Store_field(v_info, 1, Val_int(info->radius));
        Store_field(v_info, 2, copy_double(info->zoom));
        Store_field(v_info, 3, copy_double(info->momentum));
        CAMLreturn(v_info);
}

PREFIX value ml_Elm_Gesture_Rotate_Info_of_ptr(value v_ptr)
{
        CAMLparam1(v_ptr);
        CAMLlocal1(v_info);
        Elm_Gesture_Rotate_Info* info = (Elm_Gesture_Rotate_Info*) v_ptr;
        v_info = caml_alloc(5, 0);
        Store_field(v_info, 0, Val_int(info->y));
        Store_field(v_info, 1, Val_int(info->radius));
        Store_field(v_info, 2, copy_double(info->base_angle));
        Store_field(v_info, 3, copy_double(info->angle));
        Store_field(v_info, 4, copy_double(info->momentum));
        CAMLreturn(v_info);
}

PREFIX Evas_Event_Flags ml_Elm_Gesture_Event_Cb(void* data, void* event_info)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) event_info);
        return EVAS_EVENT_FLAG_ON_HOLD;
}

PREFIX value ml_elm_gesture_layer_line_min_length_set(value v_obj, value v_x)
{
        elm_gesture_layer_line_min_length_set((Evas_Object*) v_obj,
                Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_line_min_length_get(value v_obj)
{
        return Val_int(elm_gesture_layer_line_min_length_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_zoom_distance_tolerance_set(value v_obj,
        value v_x)
{
        elm_gesture_layer_zoom_distance_tolerance_set((Evas_Object*) v_obj,
                Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_distance_tolerance_get(value v_obj)
{
        return Val_int(elm_gesture_layer_zoom_distance_tolerance_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_line_distance_tolerance_set(value v_obj,
        value v_x)
{
        elm_gesture_layer_line_distance_tolerance_set((Evas_Object*) v_obj,
                Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_line_distance_tolerance_get(value v_obj)
{
        return Val_int(elm_gesture_layer_line_distance_tolerance_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_line_angular_tolerance_set(
        value v_obj, value v_x)
{
        elm_gesture_layer_line_angular_tolerance_set((Evas_Object*) v_obj,
                Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_line_angular_tolerance_get(value v_obj)
{
        return copy_double(elm_gesture_layer_line_angular_tolerance_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_zoom_wheel_factor_set(
        value v_obj, value v_x)
{
        elm_gesture_layer_zoom_wheel_factor_set((Evas_Object*) v_obj,
                Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_wheel_factor_get(value v_obj)
{
        return copy_double(elm_gesture_layer_zoom_wheel_factor_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_zoom_finger_factor_set(
        value v_obj, value v_x)
{
        elm_gesture_layer_zoom_finger_factor_set((Evas_Object*) v_obj,
                Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_finger_factor_get(value v_obj)
{
        return copy_double(elm_gesture_layer_zoom_finger_factor_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_rotate_angular_tolerance_set(
        value v_obj, value v_x)
{
        elm_gesture_layer_rotate_angular_tolerance_set((Evas_Object*) v_obj,
                Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_rotate_angular_tolerance_get(value v_obj)
{
        return copy_double(elm_gesture_layer_rotate_angular_tolerance_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_flick_time_limit_ms_set(
        value v_obj, value v_x)
{
        elm_gesture_layer_flick_time_limit_ms_set((Evas_Object*) v_obj,
                Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_flick_time_limit_ms_get(value v_obj)
{
        return Val_int(elm_gesture_layer_flick_time_limit_ms_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_long_tap_start_timeout_set(
        value v_obj, value v_x)
{
        elm_gesture_layer_long_tap_start_timeout_set((Evas_Object*) v_obj,
                Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_long_tap_start_timeout_get(value v_obj)
{
        return copy_double(elm_gesture_layer_long_tap_start_timeout_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_continues_enable_set(
        value v_obj, value v_flag)
{
        elm_gesture_layer_continues_enable_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_continues_enable_get(value v_obj)
{
        return Val_bool(elm_gesture_layer_continues_enable_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_cb_set(
        value v_obj, value v_type, value v_state, value v_cb)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_cb;
        caml_register_global_root(data);
        elm_gesture_layer_cb_set((Evas_Object*) v_obj,
                Elm_Gesture_Type_val(v_type), Elm_Gesture_State_val(v_state),
                ml_Elm_Gesture_Event_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_hold_events_get(value v_obj)
{
        return Val_bool(elm_gesture_layer_hold_events_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_hold_events_set(value v_obj, value v_flag)
{
        elm_gesture_layer_hold_events_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_step_set(value v_obj, value v_step)
{
        elm_gesture_layer_zoom_step_set((Evas_Object*) v_obj,
                Double_val(v_step));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_zoom_step_get(value v_obj)
{
        return copy_double(elm_gesture_layer_zoom_step_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_rotate_step_set(value v_obj, value v_step)
{
        elm_gesture_layer_rotate_step_set((Evas_Object*) v_obj,
                Double_val(v_step));
        return Val_unit;
}

PREFIX value ml_elm_gesture_layer_rotate_step_get(value v_obj)
{
        return copy_double(elm_gesture_layer_rotate_step_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_attach(value v_obj, value v_target)
{
        return Val_bool(elm_gesture_layer_attach((Evas_Object*) v_obj,
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gesture_layer_add(value v_parent)
{
        Evas_Object* obj = elm_gesture_layer_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_gesture_layer_add");
        return (value) obj;
}

