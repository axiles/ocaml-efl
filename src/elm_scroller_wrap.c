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
        value v_obj, value v_w, value v_h, value v_v)
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

