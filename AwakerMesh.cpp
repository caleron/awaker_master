//
// Created by Patrick on 14.12.2016.
//

#include "AwakerMesh.h"

extern bool initialized;

extern "C" void init(uint8_t channel) {
    mesh.setNodeID(0);
    mesh.begin(channel);
    initialized = true;
}

extern "C" void setChannel(uint8_t channel) {
    mesh.setChannel(channel);
}

extern "C" void updateAndDhcp() {
    mesh.update();
    mesh.DHCP();
}

extern "C" bool available() {
    return network.available();
}

extern "C" int16_t peekType() {
    RF24NetworkHeader header;
    network.peek(header);
    return static_cast<int16_t > (header.type);
}

extern "C" int16_t readNext(int16_t *type, int16_t *sender, char *returnArray, const int16_t maxSize) {
    RF24NetworkHeader header;
    network.peek(header);

    *type = static_cast<int16_t > (header.type);
    *sender = mesh.getNodeID(header.from_node);

    uint16_t bytesRead = network.read(header, returnArray, static_cast<uint16_t > (maxSize));

    return static_cast<int16_t > (bytesRead);
}

//std::vector<uint8_t> readMessage() {
//    return std::vector<uint8_t >();
//}
