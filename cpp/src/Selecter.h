//
//  Selecter.h
//  psychetouch
//
//  Created by Etienne on 2/1/17.
//  Copyright © 2017 Etienne. All rights reserved.
//

#ifndef SELECTER_H
#define SELECTER_H

#include "myColorRGB.h"
#include "myImage.h"
#include "myPoint.h"

#include <stack>

class Selecter {
    
public:
    static void separateBW(myImage *mim, float threshold, vector<myPoint> *black, vector<myPoint> *white);
};


#endif /* Selecter_h */
