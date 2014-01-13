#include "include.h"

PREFIX void ml_Elm_Transit_Effect_Transition_Cb(
        Elm_Transit_Effect* effect, Elm_Transit* tr, double progress)
{
        CAMLparam0();
        CAMLlocal1(v_progress);
        value* v_fun = (value*) effect;
        v_progress = copy_double(progress);
        caml_callback2(*v_fun, (value) tr, v_progress);
        CAMLreturn0;
}

PREFIX void ml_Elm_Transit_Effect_End_Cb_free_only(
        Elm_Transit_Effect* effect, Elm_Transit* tr)
{
        value* v_fun = (value*) effect;
        caml_remove_global_root(v_fun);
        free(v_fun);
}

PREFIX void ml_Elm_Transit_Del_Cb(void* data, Elm_Transit* tr)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) tr);
        caml_remove_global_root(v_fun);
        free(v_fun);
}

PREFIX inline Elm_Transit_Tween_Mode Elm_Transit_Tween_Mode_val(value v)
{
        switch(v) {
                case Val_linear: return ELM_TRANSIT_TWEEN_MODE_LINEAR;
                case Val_sinusoidal: return ELM_TRANSIT_TWEEN_MODE_SINUSOIDAL;
                case Val_decelerate: return ELM_TRANSIT_TWEEN_MODE_DECELERATE;
                case Val_accelerate: return ELM_TRANSIT_TWEEN_MODE_ACCELERATE;
                default: break;
        }
        caml_failwith("Elm_Transit_Tween_Mode_val");
        return ELM_TRANSIT_TWEEN_MODE_LINEAR;
}

PREFIX inline value Val_Elm_Transit_Tween_Mode(Elm_Transit_Tween_Mode m)
{
        switch(m) {
                case ELM_TRANSIT_TWEEN_MODE_LINEAR: return Val_linear;
                case ELM_TRANSIT_TWEEN_MODE_SINUSOIDAL: return Val_sinusoidal;
                case ELM_TRANSIT_TWEEN_MODE_DECELERATE: return Val_decelerate;
                case ELM_TRANSIT_TWEEN_MODE_ACCELERATE: return Val_accelerate;
                default: break;
        }
        caml_failwith("Val_Elm_Transit_Tween_Mode");
        return Val_linear;
}

PREFIX inline value copy_Eina_List_Elm_Transit(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Transit* obj;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, obj) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) obj);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX inline Elm_Transit_Effect_Flip_Axis Elm_Transit_Effect_Flip_Axis_val(
        value v)
{
        switch(v) {
                case Val_x : return ELM_TRANSIT_EFFECT_FLIP_AXIS_X;
                case Val_y: return ELM_TRANSIT_EFFECT_FLIP_AXIS_Y;
                default: break;
        }
        caml_failwith("Elm_Transit_Effect_Flip_Axis_val");
        return ELM_TRANSIT_EFFECT_FLIP_AXIS_X;
}

PREFIX inline Elm_Transit_Effect_Wipe_Type Elm_Transit_Effect_Wipe_Type_val(
        value v)
{
        switch(v) {
                case Val_hide: return ELM_TRANSIT_EFFECT_WIPE_TYPE_HIDE;
                case Val_show: return ELM_TRANSIT_EFFECT_WIPE_TYPE_SHOW;
                default: break;
        }
        caml_failwith("Elm_Transit_Effect_Wipe_Type_val");
        return ELM_TRANSIT_EFFECT_WIPE_TYPE_HIDE;
}

PREFIX inline Elm_Transit_Effect_Wipe_Dir Elm_Transit_Effect_Wipe_Dir_val(
        value v)
{
        switch(v) {
                case Val_left: return ELM_TRANSIT_EFFECT_WIPE_DIR_LEFT;
                case Val_right: return ELM_TRANSIT_EFFECT_WIPE_DIR_RIGHT;
                case Val_up: return ELM_TRANSIT_EFFECT_WIPE_DIR_UP;
                case Val_down: return ELM_TRANSIT_EFFECT_WIPE_DIR_DOWN;
                default: break;
        }
        caml_failwith("Elm_Transit_Effect_Wipe_Dir_val");
        return ELM_TRANSIT_EFFECT_WIPE_DIR_LEFT;
}

PREFIX value ml_elm_transit_add(value v_unit)
{
        Elm_Transit* tr = elm_transit_add();
        if(tr == NULL) caml_failwith("elm_transit_add");
        return (value) tr;
}

PREFIX value ml_elm_transit_del(value v_tr)
{
        elm_transit_del((Elm_Transit*) v_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_add(value v_tr, value v_fun)
{
        CAMLparam2(v_tr, v_fun);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        elm_transit_effect_add((Elm_Transit*) v_tr,
                ml_Elm_Transit_Effect_Transition_Cb, data,
                ml_Elm_Transit_Effect_End_Cb_free_only);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_transit_object_add(value v_tr, value v_obj)
{
        elm_transit_object_add((Elm_Transit*) v_tr, (Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_transit_object_remove(value v_tr, value v_obj)
{
        elm_transit_object_remove((Elm_Transit*) v_tr, (Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_transit_objects_get(value v_tr)
{
        return copy_Eina_List_Evas_Object(elm_transit_objects_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_objects_final_state_keep_set(
        value v_tr, value v_flag)
{
        elm_transit_objects_final_state_keep_set((Elm_Transit*) v_tr,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_objects_final_state_keep_get(value v_tr)
{
        return Val_bool(elm_transit_objects_final_state_keep_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_event_enabled_set(value v_tr, value v_flag)
{
        elm_transit_event_enabled_set((Elm_Transit*) v_tr, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_event_enabled_get(value v_tr)
{
        return Val_bool(elm_transit_event_enabled_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_del_cb_set(value v_tr, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_transit_del_cb_set((Elm_Transit*) v_tr, ml_Elm_Transit_Del_Cb,
                data);
        return Val_unit;
}

PREFIX value ml_elm_transit_auto_reverse_set(value v_tr, value v_flag)
{
        elm_transit_auto_reverse_set((Elm_Transit*) v_tr, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_auto_reverse_get(value v_tr)
{
        return Val_bool(elm_transit_auto_reverse_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_repeat_times_set(value v_tr, value v_num)
{
        elm_transit_repeat_times_set((Elm_Transit*) v_tr, Int_val(v_num));
        return Val_unit;
}

PREFIX value ml_elm_transit_repeat_times_get(value v_tr)
{
        return Val_int(elm_transit_repeat_times_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_tween_mode_set(value v_tr, value v_mode)
{
        elm_transit_tween_mode_set((Elm_Transit*) v_tr,
                Elm_Transit_Tween_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_transit_tween_mode_get(value v_tr)
{
        return Val_Elm_Transit_Tween_Mode(elm_transit_tween_mode_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_duration_set(value v_tr, value v_x)
{
        elm_transit_duration_set((Elm_Transit*) v_tr, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_transit_duration_get(value v_tr)
{
        return copy_double(elm_transit_duration_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_go(value v_tr)
{
        elm_transit_go((Elm_Transit*) v_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_paused_set(value v_tr, value v_flag)
{
        elm_transit_paused_set((Elm_Transit*) v_tr, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_transit_paused_get(value v_tr)
{
        return Val_bool(elm_transit_paused_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_progress_value_get(value v_tr)
{
        return copy_double(elm_transit_progress_value_get((Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_chain_transit_add(value v_tr, value v_chain_tr)
{
        elm_transit_chain_transit_add((Elm_Transit*) v_tr,
                (Elm_Transit*) v_chain_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_chain_transit_del(value v_tr, value v_chain_tr)
{
        elm_transit_chain_transit_del((Elm_Transit*) v_tr,
                (Elm_Transit*) v_chain_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_chain_transits_get(value v_tr)
{
        return copy_Eina_List_Elm_Transit(elm_transit_chain_transits_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_effect_resizing_add(
        value v_tr, value v_from_w, value v_from_h, value v_to_w, value v_to_h)
{
        elm_transit_effect_resizing_add((Elm_Transit*) v_tr, Int_val(v_from_w),
                Int_val(v_from_h), Int_val(v_to_w), Int_val(v_to_h));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_translation_add(
        value v_tr, value v_from_dx, value v_from_dy, value v_to_dx,
        value v_to_dy)
{
        elm_transit_effect_translation_add((Elm_Transit*) v_tr,
                Int_val(v_from_dx), Int_val(v_from_dy), Int_val(v_to_dx),
                Int_val(v_to_dy));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_zoom_add(
        value v_tr, value v_from, value v_to)
{
        elm_transit_effect_zoom_add((Elm_Transit*) v_tr, Double_val(v_from),
                Double_val(v_to));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_flip_add(
        value v_tr, value v_axis, value v_cw)
{
        elm_transit_effect_flip_add((Elm_Transit*) v_tr,
                Elm_Transit_Effect_Flip_Axis_val(v_axis), Bool_val(v_cw));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_resizable_flip_add(
        value v_tr, value v_axis, value v_cw)
{
        elm_transit_effect_resizable_flip_add((Elm_Transit*) v_tr,
                Elm_Transit_Effect_Flip_Axis_val(v_axis), Bool_val(v_cw));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_wipe_add(
        value v_tr, value v_type, value v_dir)
{
        elm_transit_effect_wipe_add((Elm_Transit*) v_tr,
                Elm_Transit_Effect_Wipe_Type_val(v_type),
                Elm_Transit_Effect_Wipe_Dir_val(v_dir));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_color_add_native(
        value v_tr, value v_from_r, value v_from_g, value v_from_b,
        value v_from_a, value v_to_r, value v_to_g, value v_to_b, value v_to_a)
{
        elm_transit_effect_color_add((Elm_Transit*) v_tr,
                Int_val(v_from_r), Int_val(v_from_g), Int_val(v_from_b),
                Int_val(v_from_a), Int_val(v_to_r), Int_val(v_to_g),
                Int_val(v_to_b), Int_val(v_to_a));
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_color_add_bytecode(value* argv, int argn)
{
        return ml_elm_transit_effect_color_add_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

PREFIX value ml_elm_transit_effect_fade_add(value v_tr)
{
        elm_transit_effect_fade_add((Elm_Transit*) v_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_blend_add(value v_tr)
{
        elm_transit_effect_blend_add((Elm_Transit*) v_tr);
        return Val_unit;
}

PREFIX value ml_elm_transit_effect_rotation_add(
        value v_tr, value v_from, value v_to)
{
        elm_transit_effect_rotation_add((Elm_Transit*) v_tr, Double_val(v_from),
                Double_val(v_to));
        return Val_unit;
}

