//
// Created by Patrick on 14.12.2016.
//

#ifndef AWAKER_MASTER_AWAKERMESH_H
#define AWAKER_MASTER_AWAKERMESH_H

#include "RF24Mesh/RF24Mesh.h"
#include "RF24/RF24.h"
#include "RF24Network/RF24Network.h"
#include <vector>

RF24 radio(RPI_V2_GPIO_P1_22, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ);
RF24Network network(radio);
RF24Mesh mesh(radio, network);

bool initialized = false;

extern "C" void init(uint8_t channel);

extern "C" void setChannel(uint8_t channel);

extern "C" void updateAndDhcp();

extern "C" bool available();

extern "C" int16_t peekType();

extern "C" int16_t readNext(int16_t *type, int16_t *sender, char *returnArray, const int16_t maxSize);

//std::vector<uint8_t > readMessage();

#endif //AWAKER_MASTER_AWAKERMESH_H
