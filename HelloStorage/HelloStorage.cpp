#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;
using std::string;
class HelloStorage : public eosio::contract {
public:
  using contract::contract;

  /// @abi action
  void addser(const name username, const uint64_t tokens) {
    require_auth(username);
    print("Hello, ",name(username));
    addEntry(username,tokens);
  }

  // /// @abi action
  // void a_table(const name username, const uint64_t tokens) {
  //
  // }

private:
  /// @abi table users i64
  struct users {
    uint64_t username;
    uint64_t tokens;
    uint64_t primary_key() const { return username; }

    EOSLIB_SERIALIZE(users, (username)(tokens));
  };

  /// @abi table dateRecord i64
  struct dateRecord {
    uint64_t username;
    uint64_t guessPrice;
    uint64_t staked;
    uint64_t timestamp;
    uint64_t primary_key() const { return timestamp; }
    EOSLIB_SERIALIZE(dateRecord, (username)(guessPrice)(staked)(timestamp));
  };

  /// @abi table dateTable i64
  struct dateTable {
    uint64_t dateNormalized;
    dateRecord record;
    uint64_t primary_key() const { return dateNormalized; }
    EOSLIB_SERIALIZE(dateTable, (dateNormalized)(record));
  };


  typedef multi_index<N(users), users> helloIndex;

  void addEntry(const name username, const uint64_t tokens) {
    helloIndex entries(_self,_self);
    auto iterator = entries.find(username);
    eosio_assert(iterator == entries.end(), "Name already exists");
    entries.emplace(username, [&](auto& logEntry)
        {
          logEntry.username = username;
          logEntry.tokens = tokens;
        });
  }

  void addRecordToTable(dateRecord addRecordToTable){

  }
};


EOSIO_ABI(HelloStorage,(addser));
//EOSIO_ABI(HelloStorage,(a_table));
//EOSIO_ABI(HelloStorage,(addTable));
//EOSIO_ABI(HelloStorage,(addRecordToTable));
