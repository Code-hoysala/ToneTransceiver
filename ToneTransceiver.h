#ifndef TONE_TRANSCEIVER_H
#define TONE_TRANSCEIVER_H

#include <Arduino.h>

class ToneTransceiver {
public:
    ToneTransceiver(uint8_t txPin, uint8_t rxPin);
    
    void begin();
    
    // --- TX (Out) Functions ---
    void playTone(uint16_t frequency, uint16_t durationMs);
    void stopTone();
    
    // --- RX (In) Functions ---
    // Non-blocking peak audio level and basic frequency estimation
    uint16_t readAmplitude(uint16_t sampleWindowMs);
    bool detectFrequencyMatch(uint16_t targetFreq, uint16_t tolerance, uint16_t sampleWindowMs);

private:
    uint8_t _txPin;
    uint8_t _rxPin;
    uint32_t _toneEndTime;
    bool _isTonePlaying;
};

#endif
