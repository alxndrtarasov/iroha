/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_TRANSACTION_SEQUENCE_FACTORY_HPP
#define IROHA_TRANSACTION_SEQUENCE_FACTORY_HPP

#include "interfaces/iroha_internal/transaction_sequence.hpp"

#include "common/result.hpp"
#include "validators/default_validator.hpp"

namespace shared_model {
  namespace interface {

    /**
     * Provides a method that creates a transaction sequence from a collection
     * of transactions
     */
    class TransactionSequenceFactory {
     public:
      /**
       * Creator of transaction sequence
       * @param transactions collection of transactions
       * @param validator validator of the collections
       * @return Result containing transaction sequence if validation
       * successful and string message containing error otherwise
       */
      template <typename TransactionValidator,
                typename FieldValidator = validation::FieldValidator>
      static iroha::expected::Result<TransactionSequence, std::string>
      createTransactionSequence(
          const types::SharedTxsCollectionType &transactions,
          const validation::TransactionsCollectionValidator<
              TransactionValidator> &validator,
          const FieldValidator &field_validator = FieldValidator());
    };

  }  // namespace interface
}  // namespace shared_model

#endif  // IROHA_TRANSACTION_SEQUENCE_FACTORY_HPP
