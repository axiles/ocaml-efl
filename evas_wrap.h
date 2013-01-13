#ifndef EVAS_H
#define EVAS_H

#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Object_Box_Layout(
        Evas_Object* obj, Evas_Object_Box_Data* priv, void* user_data);

#endif

