let string_iteri f s =
  for i = 0 to String.length s - 1 do
    f i s.[i]
  done

(* This replace every % by %% *)
let fstring_of_string s =
  let buf = Buffer.create (2 * String.length s) in
  let aux i c =
    if c = '%' then Buffer.add_string buf "%%" else Buffer.add_char buf c in
  string_iteri aux s;
  Buffer.contents buf

module FU : sig
  type t
  val create : unit -> t
  val replace : t -> Evas.obj -> (float -> string) -> unit
  val remove : t -> Evas.obj -> unit
  val find : t -> Evas.obj -> (float -> string) option
end = struct
  module M = Map.Make (struct
    type t = Evas.obj
    let compare : Evas.obj -> Evas.obj -> int = compare
  end)
  type t = (float -> string) M.t ref
  let create () = ref M.empty
  let replace fu obj f = fu := M.add obj f !fu
  let remove fu obj = fu := M.remove obj !fu
  let find fu obj = try Some (M.find obj !fu) with Not_found -> None
end

