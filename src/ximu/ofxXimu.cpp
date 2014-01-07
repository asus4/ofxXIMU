//
//  ofxXimu.cpp
//  ofxXIMU
//
//  Created by Koki Ibukuro on 2013/12/10.
//
//

#include "ofxXimu.h"

ofxXimu::ofxXimu() {
    
}

ofxXimu::~ofxXimu() {
    serial.close();
}

void ofxXimu::setup(std::string portname) {
    serial.setup(portname, B115200);
}

void ofxXimu::update() {
    ErrorCode e = ERR_NO_ERROR;
    
    while (serial.available()) {
        char c = serial.readByte();
        e = ximuReceiver.processNewChar(c);
        
//        std::cout << c;
    }
    
    if(e != ERR_NO_ERROR) {
        std::cout << "ERROR: " << e << std::endl;
    }
    
    if(ximuReceiver.isBattAndThermGetReady()) {
        BattAndThermStruct battAndThermStruct = ximuReceiver.getBattAndTherm();
        std::cout << "battery = " << battAndThermStruct.battery << ", thermometer = " << battAndThermStruct.thermometer << std::endl;
    }
    
    if(ximuReceiver.isInertialAndMagGetReady()) {
        InertialAndMagStruct inertialAndMagStruct = ximuReceiver.getInertialAndMag();
        std::cout
        << "gyr:[" << inertialAndMagStruct.gyrX << ',' << inertialAndMagStruct.gyrY << ',' << inertialAndMagStruct.gyrZ
        << "] acc:[" << inertialAndMagStruct.accX << ',' << inertialAndMagStruct.accY << ',' << inertialAndMagStruct.accZ
        << "] mag:[" << inertialAndMagStruct.magX << ',' << inertialAndMagStruct.magY << ',' << inertialAndMagStruct.magZ
        << ']' << std::endl;
    }
    
    if(ximuReceiver.isQuaternionGetReady()) {
        QuaternionStruct quaternionStruct = ximuReceiver.getQuaternion();
        armsQuaternion = quaternionStruct;
        Quaternion quaternion = Quaternion(quaternionStruct.w, quaternionStruct.x, quaternionStruct.y, quaternionStruct.z);
        EulerAnglesStruct eulerAnglesStruct = quaternion.getEulerAngles();
        
        std::cout
        << "roll = "
        << eulerAnglesStruct.roll
        << ", pitch = "
        << eulerAnglesStruct.pitch
        << ", yaw = "
        << eulerAnglesStruct.yaw
        << std::endl;
    }
    
}