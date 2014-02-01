#include "include.h"

PREFIX value ml_elm_player_add(value v_parent)
{
        Evas_Object* player = elm_player_add((Evas_Object*) v_parent);
        if(player == NULL) caml_failwith("elm_player_add");
        return (value) player;
}

PREFIX value ml_elm_video_add(value v_parent)
{
        Evas_Object* video = elm_video_add((Evas_Object*) v_parent);
        if(video == NULL) caml_failwith("elm_video_add");
        return (value) video;
}

