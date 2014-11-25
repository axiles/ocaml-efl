#ifndef ELM_H
#define ELM_H

#include "include.h"

/* Focus */

/* Colors */

inline value copy_Elm_Color_Class(Elm_Color_Class* c);
inline value copy_Eina_List_Elm_Color_Class(const Eina_List* list);

inline value copy_Elm_Color_Overlay(Elm_Color_Overlay* o);
inline value copy_Eina_List_Elm_Color_Overlay(const Eina_List* list);

/* Tooltips */

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

inline Elm_Glob_Match_Flags Elm_Glob_Match_Flags_val_list(value v);

#endif
