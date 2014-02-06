(** Ethumb *)

type thumb_aspect = [`keep_aspect | `ignore_aspect | `crop]

type thumb_fdo_size = [`normal | `large]

type thumb_format = [`fdo | `jpeg | `eet]

type thumb_orientation = [
  | `orient_none
  | `rotate_90_cw
  | `rotate_180
  | `rotate_90_ccw
  | `flip_horizontal
  | `flip_vertical
  | `flip_transpose
  | `flip_transverse
  | `orient_original]

