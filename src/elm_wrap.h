#ifndef ELM_H
#define ELM_H

#include "include.h"

/* Focus */

inline Elm_Focus_Autoscroll_Mode Elm_Focus_Autoscroll_Mode_val(value v);
inline value Val_Elm_Focus_Autoscroll_Mode(Elm_Focus_Autoscroll_Mode m);

inline Elm_Focus_Direction Elm_Focus_Direction_val(value v);
inline value Val_Elm_Focus_Direction(Elm_Focus_Direction d);

/* Tooltips */

inline Elm_Tooltip_Orient Elm_Tooltip_Orient_val(value v);
inline value Val_Elm_Tooltip_Orient(Elm_Tooltip_Orient o);

/* Other */

inline Eina_Bool ml_Elm_Event_Cb(
        void* data, Evas_Object* obj, Evas_Object* src, Evas_Callback_Type type,
        void* event_info);

inline Elm_Wrap_Type Elm_Wrap_Type_val(value v);
inline value Val_Elm_Wrap_Type(Elm_Wrap_Type t);

inline Elm_Icon_Type Elm_Icon_Type_val(value v);
inline value Val_Elm_Icon_Type(Elm_Icon_Type t);

inline Elm_Text_Format Elm_Text_Format_val(value v);
inline value Val_Elm_Text_Format(Elm_Text_Format f);

inline Elm_Input_Panel_Layout Input_Panel_Layout_val(value v);
inline value Val_Elm_Input_Panel_Layout(Elm_Input_Panel_Layout l);

inline Elm_Autocapital_Type Elm_Autocapital_Type_val(value v);
inline value Val_Elm_Autocapital_Type(Elm_Autocapital_Type t);

inline Elm_Input_Panel_Lang Elm_Input_Panel_Lang_val(value v);
inline value Val_Elm_Input_Panel_Lang(Elm_Input_Panel_Lang l);

inline Elm_Input_Panel_Return_Key_Type
        Elm_Input_Panel_Return_Key_Type_val(value v);
inline value Val_Elm_Input_Panel_Return_Key_Type(
        Elm_Input_Panel_Return_Key_Type t);

inline Elm_Cnp_Mode Elm_Cnp_Mode_val(value v);
inline value Val_Elm_Cnp_Mode(Elm_Cnp_Mode m);

#endif
