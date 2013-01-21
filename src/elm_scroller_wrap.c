#include "include.h"

PREFIX inline Elm_Scroller_Policy Elm_Scroller_Policy_val(value v)
{
        switch(v) {
                case Val_auto: return ELM_SCROLLER_POLICY_AUTO;
                case Val_on: return ELM_SCROLLER_POLICY_ON;
                case Val_off: return ELM_SCROLLER_POLICY_OFF;
        }
        caml_failwith("Elm_Scroller_Policy_val");
        return ELM_SCROLLER_POLICY_AUTO;
}

PREFIX inline Val_Elm_Scroller_Policy(Elm_Scroller_Policy p)
{
        switch(p) {
                case ELM_SCROLLER_POLICY_AUTO: return Val_auto;
                case ELM_SCROLLER_POLICY_ON: return Val_on;
                case ELM_SCROLLER_POLICY_OFF: return Val_off;
        }
        caml_failwith("Val_Elm_Scroller_Policy");
        return Val_auto;
}

