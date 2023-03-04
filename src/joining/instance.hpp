/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"

namespace dci::module::ppn::connectivity
{
    class Joining;
}

namespace dci::module::ppn::connectivity::joining
{
    class Instance
    {
    public:
        Instance(Joining* j, const node::link::Id& id);
        ~Instance();

        const node::link::Id id() const;

        void demand(api::demand::SatisfactionHolder<>&& demand) const;
        void discovered() const;
        void joined(const node::link::Remote<>& r) const;

    private:
        void activate() const;
        void worker() const;

        Joining *                   _j;
        node::link::Id              _id;
        mutable cmt::task::Owner    _taskOwner;

        mutable Map<api::demand::SatisfactionHolder<>, sbs::Owner>  _demands;
        mutable bool                                                _hasAddress{true};
        mutable Map<node::link::Remote<>, sbs::Owner>               _onlines;
    };
}
