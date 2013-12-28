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

