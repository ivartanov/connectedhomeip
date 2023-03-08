/**
 *
 *    Copyright (c) 2023 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <lib/core/CHIPError.h>
#include <lib/core/TLV.h>

namespace chip {
namespace scenes {

static constexpr uint8_t kInvalidPosition     = 0xff;
static constexpr uint8_t kMaxClusterPerScenes = CHIP_CONFIG_SCENES_MAX_CLUSTERS_PER_SCENES;
static constexpr uint8_t kMaxFieldsPerCluster = CHIP_CONFIG_SCENES_MAX_EXTENSION_FIELDSET_SIZE_PER_CLUSTER;

class ExtensionFieldSets
{
public:
    ExtensionFieldSets(){};
    virtual ~ExtensionFieldSets() = default;

    virtual CHIP_ERROR Serialize(TLV::TLVWriter & writer) const = 0;
    virtual CHIP_ERROR Deserialize(TLV::TLVReader & reader)     = 0;
    virtual void Clear()                                        = 0;
    virtual bool IsEmpty() const                                = 0;
    virtual uint8_t GetFieldNum() const                         = 0;
};
} // namespace scenes
} // namespace chip