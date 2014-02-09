#ifndef EVAS_H
#define EVAS_H

#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Smart_Cb_1_free(
        void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Object_Box_Layout_0(
        Evas_Object* obj, Evas_Object_Box_Data* priv, void* user_data);

PREFIX inline value copy_Evas_Event_Info(
        Evas_Callback_Type type, void* event_info);

PREFIX inline Evas_Load_Error Evas_Load_Error_val(value v);
PREFIX inline value Val_Evas_Load_Error(Evas_Load_Error e);

/* Register a value that will be removed when the object is deleted.
 * The content of the returned pointer must not be directly assigned
 * (it has been registered by caml_register_generational_global_root() */
PREFIX inline value* ml_Evas_Object_register_value(Evas_Object* obj, value v);

PREFIX inline void ml_Evas_Object_gc_value(Evas_Object* obj, value* data);

PREFIX void ml_Evas_Smart_Cb_on_del(
        void* data, Evas_Object* obj, void* event_info);
PREFIX void ml_Evas_Smart_Cb_on_del_data(
        void* data, Evas_Object* obj, void* event_info);

#endif

