/**
 * Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
 * http://soramitsu.co.jp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IROHA_GET_ACCOUNT_TRANSACTIONS_H
#define IROHA_GET_ACCOUNT_TRANSACTIONS_H

#include "backend/protobuf/common_objects/trivial_proto.hpp"
#include "interfaces/queries/get_account_transactions.hpp"
#include "queries.pb.h"

namespace shared_model {
  namespace proto {
    class GetAccountTransactions final
        : public CopyableProto<interface::GetAccountTransactions,
                               iroha::protocol::Query,
                               GetAccountTransactions> {
     public:
      template <typename QueryType>
      explicit GetAccountTransactions(QueryType &&query);

      GetAccountTransactions(const GetAccountTransactions &o);

      GetAccountTransactions(GetAccountTransactions &&o) noexcept;

      const interface::types::AccountIdType &accountId() const override;

      std::unique_ptr<interface::TxPaginationMeta> paginationMeta()
          const override;

     private:
      // ------------------------------| fields |-------------------------------

      const iroha::protocol::GetAccountTransactions &account_transactions_;
    };

  }  // namespace proto
}  // namespace shared_model

#endif  // IROHA_GET_ACCOUNT_TRANSACTIONS_H
