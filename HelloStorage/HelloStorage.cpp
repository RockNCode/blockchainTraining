#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class HelloStorage : public eosio::contract {
public:
  using contract::contract;

  /// @abi action
  void hello(name user) {
    require_auth(user);
    print("Hello, ",name(user));
  }

};

EOSIO_ABI(HelloStorage,(hello));
