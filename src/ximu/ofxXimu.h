//
//  ofxXimu.h
//  ofxXIMU
//
//  Created by Koki Ibukuro on 2013/12/10.
//
//

#ifndef __ofxXIMU__ofxXimu__
#define __ofxXIMU__ofxXimu__

#include <iostream>
#include "XimuReceiver.h"
#include "Quaternion.h"
#include "ofSerial.h"

class ofxXimu {
public:
    ofxXimu();
    virtual ~ofxXimu();
    
    void setup(std::string portname);
    void update();
    
    QuaternionStruct armsQuaternion;
protected:
    XimuReceiver ximuReceiver;
    ofSerial serial;
};

#endif /* defined(__ofxXIMU__ofxXimu__) */
