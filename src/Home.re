open Async;
open Serbet;
open Serbet.Endpoint;

[@decco]
type body_out = {message: string};

let endpoint =
  Serbet.jsonEndpoint({
    verb: GET,
    path: "/json",
    body_out_encode,
    handler: (_req) => {
      {message: "Bom dia" } |> async;
    },
  });





