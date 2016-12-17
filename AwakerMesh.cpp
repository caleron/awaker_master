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

extern "C" unsigned char peekType() {
    RF24NetworkHeader header;
    network.peek(header);
    return header.type;
}

extern "C" uint16_t readNext(unsigned char* type, char *returnArray, const uint16_t maxSize) {
    RF24NetworkHeader header;
    network.peek(header);
    *type = header.type;

    uint16_t bytesRead = network.read(header, returnArray, maxSize);

    return bytesRead;
}

//std::vector<uint8_t> readMessage() {
//    return std::vector<uint8_t >();
//}
