#!/bin/sh
cleos wallet unlock --password PW5JgstpdkHrkppcGCm1EQjfWhuBLTon9r8R9Cx22Bsmozq8zoP69
cleos create account eosio $1 EOS6NcSE6nCsHEztXaqyX2G3oGqhjDNkhqQYCfpRBsLoPNSRnHh3F
cleos push action table.code addser "["$1",$2]" -p $1
cleos get table table.code table.code users
