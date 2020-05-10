/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}
void load_curtanaglobal() {
    property_override("ro.product.model", "Redmi Note 9S");
    property_override("ro.product.product.model", "Redmi Note 9S");
    property_override("ro.product.system.model", "Redmi Note 9S");
    property_override("ro.build.description", "curtana_global-user 10 QKQ1.191215.002 V11.0.7.0.QJWMIXM release-keys");
    property_override("ro.build.fingerprint", "Redmi/curtana_global/curtana:10/QKQ1.191215.002/V11.0.7.0.QJWMIXM:user/release-keys");
    
     // Maintainer props
    property_override("org.evolution.build_donate_url", "https://paypal.me/darvycana");
    property_override("org.evolution.build_maintainer", "Lewis Shqipe");
    property_override("org.evolution.build_support_url", "https://t.me/EvolutionXCortana");
}

void load_curtana() {
    property_override("ro.product.model", "Redmi Note 9 Pro");
    property_override("ro.product.product.model", "Redmi Note 9 Pro");
    property_override("ro.product.system.model", "Redmi Note 9 Pro");
    property_override("ro.build.description", "curtana-user 10 QKQ1.191215.002 V11.0.6.0.QJWINXM release-keys");
    property_override("ro.build.fingerprint", "Redmi/curtana/curtana:10/QKQ1.191215.002/V11.0.6.0.QJWINXM:user/release-keys");
     
     // Maintainer props
    property_override("org.evolution.build_donate_url", "https://paypal.me/darvycana");
    property_override("org.evolution.build_maintainer", "Lewis Shqipe");
    property_override("org.evolution.build_support_url", "https://t.me/EvolutionXCortana");
}

void vendor_load_properties() {
    std::string region = android::base::GetProperty("ro.boot.hwc", "");

    if (region.find("global_two") != std::string::npos) {
        load_curtanaglobal();
    } else {
        load_curtana();
    }
}

