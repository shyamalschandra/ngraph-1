/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include <memory>

#include "ngraph/op/util/unary_elementwise_arithmetic.hpp"

namespace ngraph
{
    namespace op
    {
        /// \brief Elementwise inverse sine (arcsin) operation.
        ///
        class Asin : public util::UnaryElementwiseArithmetic
        {
        public:
            /// \brief Constructs an arcsin operation.
            ///
            /// \param arg Node that produces the input tensor.<br>
            /// `[d1, ...]`
            ///
            /// Output `[d1, ...]`
            ///
            Asin(const std::shared_ptr<Node>& arg)
                : UnaryElementwiseArithmetic("Asin", arg)
            {
            }

            virtual std::shared_ptr<Node>
                copy_with_new_args(const NodeVector& new_args) const override
            {
                if (new_args.size() != 1)
                {
                    throw ngraph_error("Incorrect number of new arguments");
                }
                return std::make_shared<Asin>(new_args.at(0));
            }
        };
    }
}
