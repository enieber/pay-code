open Async;

type user = {
  id: int,
  email: string,
};

let saveUserInDatabase = (_user: user) => {
  Ok() |> async;
};

let processUser = user => {
  {...user, id: user.id + 2} |> async;
};

let newUser = () => {
  {id: 1, email: "hey man"} |> async;
};

open Serbet.Endpoint;
[@decco]
type body_in = {name: string};

[@decco]
type body_out = {message: string};

let endpoint =
  Serbet.jsonEndpoint({
    verb: POST,
    path: "/",
    body_in_decode,
    body_out_encode,
    handler: (body, _req) => {
      {message: body.name} |> async;
    },
  });

