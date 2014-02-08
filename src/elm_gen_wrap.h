#ifndef GEN_H
#define GEN_H

PREFIX char* ml_Elm_Gen_Item_Text_Get_Cb(
        void* data, Evas_Object* obj, const char* part);

PREFIX Evas_Object* ml_Elm_Gen_Item_Content_Get_Cb(
        void* data, Evas_Object* obj, const char* part);

PREFIX Eina_Bool ml_Elm_Gen_Item_State_Get_Cb(
        void* data, Evas_Object* obj, const char* part);

PREFIX void ml_Elm_Gen_Item_Del_Cb_free(void* data, Evas_Object* obj);

#endif

