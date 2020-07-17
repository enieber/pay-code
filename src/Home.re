open Async;
open Serbet.Endpoint;

[@decco]
type body_out = {message: string};

let endpoint =
  Serbet.endpoint({
    verb: GET,
    path: "/",
    handler: (_req) => {
      let response = {message: "Bom dia" }
      response 
        -> body_out_encode
        -> OkJson 
        -> async;
    },
  });





