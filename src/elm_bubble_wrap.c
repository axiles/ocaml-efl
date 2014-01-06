#include "include.h"

PREFIX inline Elm_Bubble_Pos Elm_Bubble_Pos_val(value v)
{
        switch(v) {
                case Val_invalid: return ELM_BUBBLE_POS_INVALID;
                case Val_top_left: return ELM_BUBBLE_POS_TOP_LEFT;
                case Val_top_right: return ELM_BUBBLE_POS_TOP_RIGHT;
                case Val_bottom_left: return ELM_BUBBLE_POS_BOTTOM_LEFT;
                case Val_bottom_right: return ELM_BUBBLE_POS_BOTTOM_RIGHT;
                default: break;
        }
        caml_failwith("Elm_Bubble_Pos_val");
        return ELM_BUBBLE_POS_INVALID;
}

PREFIX inline value Val_Elm_Bubble_Pos(Elm_Bubble_Pos p)
{
        switch(p) {
                case ELM_BUBBLE_POS_INVALID: return Val_invalid;
                case ELM_BUBBLE_POS_TOP_LEFT: return Val_top_left;
                case ELM_BUBBLE_POS_TOP_RIGHT: return Val_top_right;
                case ELM_BUBBLE_POS_BOTTOM_LEFT: return Val_bottom_left;
                case ELM_BUBBLE_POS_BOTTOM_RIGHT: return Val_bottom_right;
                default: break;
        }
        caml_failwith("Val_Elm_Bubble_Pos");
        return Val_invalid;
}

PREFIX value ml_elm_bubble_add(Evas_Object* v_parent)
{
        Evas_Object* bubble = elm_bubble_add((Evas_Object*) v_parent);
        if(bubble == NULL) caml_failwith("elm_bubble_add");
        return (value) bubble;
}

