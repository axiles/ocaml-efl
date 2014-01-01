#include "include.h"

PREFIX inline Elm_Scroller_Policy Elm_Scroller_Policy_val(value v)
{
        switch(v) {
                case Val_auto: return ELM_SCROLLER_POLICY_AUTO;
                case Val_on: return ELM_SCROLLER_POLICY_ON;
                case Val_off: return ELM_SCROLLER_POLICY_OFF;
	        default: break;
        }
        caml_failwith("Elm_Scroller_Policy_val");
        return ELM_SCROLLER_POLICY_AUTO;
}

PREFIX inline value Val_Elm_Scroller_Policy(Elm_Scroller_Policy p)
{
        switch(p) {
                case ELM_SCROLLER_POLICY_AUTO: return Val_auto;
                case ELM_SCROLLER_POLICY_ON: return Val_on;
                case ELM_SCROLLER_POLICY_OFF: return Val_off;
		default: break;
        }
        caml_failwith("Val_Elm_Scroller_Policy");
        return Val_auto;
}

PREFIX inline Elm_Scroller_Single_Direction
Elm_Scroller_Single_Direction_val(value v)
{
        switch(v) {
                case Val_none: return ELM_SCROLLER_SINGLE_DIRECTION_NONE;
                case Val_soft: return ELM_SCROLLER_SINGLE_DIRECTION_SOFT;
                case Val_hard: return ELM_SCROLLER_SINGLE_DIRECTION_HARD;
                case Val_last: return ELM_SCROLLER_SINGLE_DIRECTION_LAST;
                default: break;
        }
        caml_failwith("Elm_Scroller_Single_Direction_val");
        return ELM_SCROLLER_SINGLE_DIRECTION_NONE;
}

PREFIX inline value Val_Elm_Scroller_Single_Direction(
        Elm_Scroller_Single_Direction sd)
{
        switch(sd) {
                case ELM_SCROLLER_SINGLE_DIRECTION_NONE: return Val_none;
                case ELM_SCROLLER_SINGLE_DIRECTION_SOFT: return Val_soft;
                case ELM_SCROLLER_SINGLE_DIRECTION_HARD: return Val_hard;
                case ELM_SCROLLER_SINGLE_DIRECTION_LAST: return Val_last;
                default: break;
        }
        caml_failwith("Val_Elm_Scroller_Single_Direction");
        return Val_none;
}

PREFIX inline Elm_Scroller_Movement_Block Elm_Scroller_Movement_Block_val(
        value v)
{
        switch(v) {
                case Val_no_block: return ELM_SCROLLER_MOVEMENT_NO_BLOCK;
                case Val_block_vertical:
                        return ELM_SCROLLER_MOVEMENT_BLOCK_VERTICAL;
                case Val_block_horizontal:
                        return ELM_SCROLLER_MOVEMENT_BLOCK_HORIZONTAL;
                case Val_block_vertical_horizontal:
                        return ELM_SCROLLER_MOVEMENT_BLOCK_VERTICAL |
                                ELM_SCROLLER_MOVEMENT_BLOCK_HORIZONTAL;
                default: break;
        }
        caml_failwith("Elm_Scroller_Movement_Block_val");
        return ELM_SCROLLER_MOVEMENT_NO_BLOCK;
}

PREFIX inline value Val_Elm_Scroller_Movement_Block(
        Elm_Scroller_Movement_Block mb)
{
        if(mb == ELM_SCROLLER_MOVEMENT_NO_BLOCK) return Val_no_block;
        int bv = mb & ELM_SCROLLER_MOVEMENT_BLOCK_VERTICAL;
        int bh = mb & ELM_SCROLLER_MOVEMENT_BLOCK_HORIZONTAL;
        if(bv && bh) return Val_block_vertical_horizontal;
        if(bv) return Val_block_vertical;
        if(bh) return Val_block_horizontal;
        caml_failwith("Val_Elm_Scroller_Movement_Block");
        return Val_no_block;
}

PREFIX value ml_elm_scroller_add(value v_parent)
{
        Evas_Object* obj = elm_scroller_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_scroller_add");
        return (value) obj;
}

PREFIX value ml_elm_scroller_content_min_limit(
        value v_obj, value v_w, value v_h)
{
        elm_scroller_content_min_limit((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_scroller_region_show(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        elm_scroller_region_show((Evas_Object*) v_obj, Int_val(v_x),
                Int_val(v_y), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_scroller_policy_set(value v_obj, value v_h, value v_v)
{
        elm_scroller_policy_set((Evas_Object*) v_obj,
                Elm_Scroller_Policy_val(v_h), Elm_Scroller_Policy_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_scroller_policy_get(value v_obj)
{
        Elm_Scroller_Policy ph, pv;
        elm_scroller_policy_get((Evas_Object*) v_obj, &ph, &pv);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Elm_Scroller_Policy(ph));
        Store_field(v, 1, Val_Elm_Scroller_Policy(pv));
        return v;
}

PREFIX value ml_elm_scroller_single_direction_set(value v_obj, value v_sd)
{
        elm_scroller_single_direction_set((Evas_Object*) v_obj,
                Elm_Scroller_Single_Direction_val(v_sd));
        return Val_unit;
}

PREFIX value ml_elm_scroller_single_direction_get(value v_obj)
{
        return Val_Elm_Scroller_Single_Direction(
                elm_scroller_single_direction_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_scroller_region_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        elm_scroller_region_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_elm_scroller_child_size_get(value v_obj, value v_w, value v_h)
{
        Evas_Coord w, h;
        elm_scroller_child_size_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_elm_scroller_page_snap_set(value v_obj, value v_ph, value v_pv)
{
        elm_scroller_page_snap_set((Evas_Object*) v_obj, Bool_val(v_ph),
                Bool_val(v_pv));
        return Val_unit;
}

PREFIX value ml_elm_scroller_page_snap_get(value v_obj)
{
        Eina_Bool ph, pv;
        elm_scroller_page_snap_get((Evas_Object*) v_obj, &ph, &pv);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_bool(ph));
        Store_field(v_r, 1, Val_bool(pv));
        return v_r;
}

PREFIX value ml_elm_scroller_bounce_set(value v_obj, value v_h, value v_v)
{
        elm_scroller_bounce_set((Evas_Object*) v_obj, Eina_Bool_val(v_h),
                Eina_Bool_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_scroller_bounce_get(value v_obj)
{
        Eina_Bool h_bounce, v_bounce;
        elm_scroller_bounce_get((Evas_Object*) v_obj, &h_bounce, &v_bounce);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Eina_Bool(h_bounce));
        Store_field(v, 1, Val_Eina_Bool(v_bounce));
        return v;
}

PREFIX value ml_elm_scroller_page_relative_set(
        value v_obj, value v_h, value v_v)
{
        elm_scroller_page_relative_set((Evas_Object*) v_obj,
                Double_val(v_h), Double_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_scroller_page_relative_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double h, v;
        elm_scroller_page_relative_get((Evas_Object*) v_obj, &h, &v);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(h));
        Store_field(v_r, 1, copy_double(v));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_scroller_page_size_set(value v_obj, value v_h, value v_v)
{
        elm_scroller_page_size_set((Evas_Object*) v_obj, Int_val(v_h),
                Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_scroller_page_size_get(value v_obj)
{
        Evas_Coord h, v;
        elm_scroller_page_size_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

PREFIX value ml_elm_scroller_page_scroll_limit_set(
        value v_obj, value v_lph, value v_lpv)
{
        elm_scroller_page_scroll_limit_set((Evas_Object*) v_obj,
                Int_val(v_lph), Int_val(v_lpv));
        return Val_unit;
}

PREFIX value ml_elm_scroller_page_scroll_limit_get(value v_obj)
{
        Evas_Coord lph, lpv;
        elm_scroller_page_scroll_limit_get((Evas_Object*) v_obj, &lph, &lpv);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(lph));
        Store_field(v_r, 1, Val_int(lpv));
        return v_r;
}

PREFIX value ml_elm_scroller_current_page_get(value v_obj)
{
        Evas_Coord h, v;
        elm_scroller_current_page_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

PREFIX value ml_elm_scroller_last_page_get(value v_obj)
{
        Evas_Coord h, v;
        elm_scroller_last_page_get((Evas_Object*) v_obj, &h, &v);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(h));
        Store_field(v_r, 1, Val_int(v));
        return v_r;
}

PREFIX value ml_elm_scroller_page_show(value v_obj, value v_h, value v_v)
{
        elm_scroller_page_show((Evas_Object*) v_obj, Int_val(v_h),
                Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_scroller_page_bring_in(value v_obj, value v_h, value v_v)
{
        elm_scroller_page_bring_in((Evas_Object*) v_obj, Int_val(v_h),
                Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_scroller_region_bring_in(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        elm_scroller_region_bring_in((Evas_Object*) v_obj, Int_val(v_x),
                Int_val(v_y), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_scroller_propagate_events_set(value v_obj, value v_flag)
{
        elm_scroller_propagate_events_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_scroller_propagate_events_get(value v_obj)
{
        return Val_bool(elm_scroller_propagate_events_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_scroller_gravity_set(
        value v_obj, value v_x, value v_y)
{
        elm_scroller_gravity_set((Evas_Object*) v_obj,
                Double_val(v_x), Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_elm_scroller_gravity_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double x, y;
        elm_scroller_gravity_get((Evas_Object*) v_obj, &x, &y);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(x));
        Store_field(v_r, 1, copy_double(y));
        CAMLreturn(v_r);
}

