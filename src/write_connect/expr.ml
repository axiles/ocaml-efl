module Signal = struct
  type ty = string option
  type t = {name : string; ty : ty}
end

type t = {name : string; signals : Signal.t list}

