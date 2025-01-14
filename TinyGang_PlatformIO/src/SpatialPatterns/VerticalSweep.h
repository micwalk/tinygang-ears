#ifndef __VERTICALSWEEP__H__
#define __VERTICALSWEEP__H__


#include "SpatialPattern.h"

class VerticalSweep final : public SpatialPattern { 

	public:

	byte m_hue = 0;
	VerticalSweep(byte hue){
		m_hue = hue;
	}

	CRGB paintSpatialLed(unsigned ledIndex, const LedContext& context, const LedPosition& position, unsigned long deltaMicros, float remaining, CRGB previous, int primaryHue) {
        
        float relVertPos = (position.position.y + 100) / 200;
        
        float scanLinePos = remaining;
        
		//maybe just sin?

		byte bright = cubicwave8(5 * 255 * (abs(relVertPos - scanLinePos)));
		//byte bright = FalloffSin(abs(relVertPos - scanLinePos), 0, 50);
		
		return CHSV(m_hue, 255, bright);

        // // trace
		// if (abs(scanLinePos - relVertPos) < .1
        //     || abs(scanLinePos - relVertPos) < .6 && abs(scanLinePos - relVertPos) >= .4
        //     || abs(scanLinePos - relVertPos) > .9) {
		// 	return CHSV(m_hue, 255, 255);
		// }
		
		// return CHSV(220, 200, 128); // pink
		// fade
		return previous.nscale8(192);
        
	}
};

#endif  //!__VERTICALSWEEP__H__