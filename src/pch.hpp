/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <dci/host.hpp>
#include <dci/logger.hpp>
#include <dci/poll/timer.hpp>
#include <dci/config.hpp>
#include "ppn/connectivity/joining.hpp"

namespace dci::module::ppn::connectivity
{
    using namespace dci;

    namespace transport = idl::ppn::transport;
    namespace node      = idl::ppn::node;
    namespace rdb       = idl::ppn::node::rdb;
    namespace api       = idl::ppn::connectivity;
}
