// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#ifndef ETH_PHY_TYPE
#define ETH_PHY_TYPE        ETH_PHY_LAN8720
#define ETH_PHY_ADDR         0
#define ETH_PHY_MDC         -1
#define ETH_PHY_MDIO        -1
#define ETH_PHY_POWER       -1
#define ETH_CLK_MODE        ETH_CLOCK_GPIO0_IN
#endif

#ifndef CONFIG_ETH_USE_ESP32_EMAC
#define CONFIG_ETH_USE_ESP32_EMAC 1
#endif

#include <Arduino.h>
#include <ETH.h>
#include <stdint.h>

#define PINMAPPING_FILENAME "/pin_mapping.json"
#define PINMAPPING_LED_COUNT 2

#define MAPPING_NAME_STRLEN 31

struct PinMapping_t {
    char name[MAPPING_NAME_STRLEN + 1];
    int8_t nrf24_miso;
    int8_t nrf24_mosi;
    int8_t nrf24_clk;
    int8_t nrf24_irq;
    int8_t nrf24_en;
    int8_t nrf24_cs;

    int8_t cmt_clk;
    int8_t cmt_cs;
    int8_t cmt_fcs;
    int8_t cmt_gpio2;
    int8_t cmt_gpio3;
    int8_t cmt_sdio;

    int8_t eth_phy_addr;
    bool eth_enabled;
    int eth_power;
    int eth_mdc;
    int eth_mdio;
    eth_phy_type_t eth_type;
    eth_clock_mode_t eth_clk_mode;
    uint8_t display_type;
    uint8_t display_data;
    uint8_t display_clk;
    uint8_t display_cs;
    uint8_t display_reset;
    int8_t led[PINMAPPING_LED_COUNT];
};

class PinMappingClass {
public:
    PinMappingClass();
    bool init(const String& deviceMapping);
    PinMapping_t& get();

    bool isValidNrf24Config() const;
    bool isValidCmt2300Config() const;
    bool isValidEthConfig() const;

private:
    PinMapping_t _pinMapping;
};

extern PinMappingClass PinMapping;
