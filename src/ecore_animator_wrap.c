#include "include.h"

int mycaml_list_length(value v_list)
{
        value v_tmp = v_list;
        int len = 0;
        while(v_tmp != Val_int(0)) {
                len++;
                v_tmp = Field(v_tmp, 1);
        }
        return len;
}

PREFIX value ml_ecore_animator_pos_map_list(value v_pos, value v_pos_map,
        value v_list)
{
        int size = mycaml_list_length(v_list);
        double v[size];
        int i;
        value v_tmp_list = v_list;
        for(i = 0; i < size; i++) {
                v[i] = Double_val(Field(v_tmp_list, 0));
                v_tmp_list = Field(v_tmp_list, 1);
        }
        return copy_double(ecore_animator_pos_map_n(Double_val(v_pos),
                Ecore_Pos_Map_val(v_pos_map), size, v));
}

PREFIX value ml_ecore_animator_custom_source_tick_begin_callback_set(
        value v_fun)
{
        static value* prev = NULL;
        if(prev != NULL) ml_remove_value(prev);
        prev = ml_register_value(v_fun);
        ecore_animator_custom_source_tick_begin_callback_set(ml_Ecore_Cb, prev);
        return Val_unit;
}

PREFIX value ml_ecore_animator_custom_source_tick_end_callback_set(
        value v_fun)
{
        static value* prev = NULL;
        if(prev != NULL) ml_remove_value(prev);
        prev = ml_register_value(v_fun);
        ecore_animator_custom_source_tick_end_callback_set(ml_Ecore_Cb, prev);
        return Val_unit;
}

PREFIX value ml_ecore_animator_add(value v_fun)
{
        value* data = ml_register_value(v_fun);
        Ecore_Animator* anim =
                ecore_animator_add(ml_Ecore_Task_Cb_free_on_last, data);
        if(anim == NULL) {
                ml_remove_value(data);
                caml_failwith("ecore_animator_add");
        }
        return Val_Ecore_Animator(anim);
}

PREFIX value ml_ecore_animator_del(value v_anim)
{
        value* data = ecore_animator_del(Ecore_Animator_val(v_anim));
        ml_remove_value(data);
        return Val_unit;
}

