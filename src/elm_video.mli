val player_add : Evas.obj -> Evas.obj

val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> bool

val emotion_get : Evas.obj -> Evas.obj

val play : Evas.obj -> unit

val pause : Evas.obj -> unit

val stop : Evas.obj -> unit

val is_playing_get : Evas.obj -> bool

val is_seekable_get : Evas.obj -> bool

val audio_mute_get : Evas.obj -> bool

val audio_mute_set : Evas.obj -> bool -> unit

val audio_level_get : Evas.obj -> float

val audio_level_set : Evas.obj -> float -> unit

val play_position_get : Evas.obj -> float

val play_position_set : Evas.obj -> float -> unit

val play_length_get : Evas.obj -> float

