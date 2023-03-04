/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "joining/instance.hpp"

namespace dci::module::ppn::connectivity
{
    class Joining
        : public api::Joining<>::Opposite
        , public host::module::ServiceBase<Joining>
    {
    public:
        Joining();
        ~Joining();

    private:
        void satisfyDemand(const node::link::Id& id, api::demand::SatisfactionHolder<>&& sh);

    private:
        friend class joining::Instance;
        void instanceEmpty(const node::link::Id& id);
        cmt::Future<Tuple<node::link::Remote<>, transport::Address, real64>> fetchRdbRecord(const node::link::Id& id);
        cmt::Future<node::link::Remote<>> join(const node::link::Id& id, transport::Address&& a);

    private:
        bool                        _started{};
        rdb::Query<>                _rdbQuery;
        node::feature::Service<>    _nodeSrv;
        api::demand::Registry<>     _demandRegistry;

        struct CmpById
        {
            using is_transparent = void;
            bool operator()(const joining::Instance& a, const joining::Instance& b) const;
            bool operator()(const joining::Instance& a, const node::link::Id& b) const;
            bool operator()(const node::link::Id& a, const joining::Instance& b) const;
        };

        std::set<joining::Instance, CmpById>    _instances;
    };
}
