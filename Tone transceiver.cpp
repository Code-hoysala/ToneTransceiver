#include "ToneTransceiver.h"

ToneTransceiver::ToneTransceiver(uint8_t txPin, uint8_t rxPin) {
    _txPin = txPin;
    _rxPin = rxPin;
    _toneEndTime = 0;
    _isTonePlaying = false;
}

void ToneTransceiver::begin() {
    pinMode(_txPin, OUTPUT);
    pinMode(_rxPin, INPUT);
}

void ToneTransceiver::playTone(uint16_t frequency, uint16_t durationMs) {
    tone(_txPin, frequency);
    _toneEndTime = millis() + durationMs;
    _isTonePlaying = true;
}

void ToneTransceiver::stopTone() {
    noTone(_txPin);
    _isTonePlaying = false;
}

uint16_t ToneTransceiver::readAmplitude(uint16_t sampleWindowMs) {
    // If a tone is playing, check if its timer expired to auto-stop
    if (_isTonePlaying && millis() >= _toneEndTime) {
        stopTone();
    }

    uint32_t startMillis = millis();
    uint16_t signalMax = 0;
    uint16_t signalMin = 1023;

    while (millis() - startMillis < sampleWindowMs) {
        uint16_t sample = analogRead(_rxPin);
        if (sample < 1024) {
            if (sample > signalMax) signalMax = sample;
            else if (sample < signalMin) signalMin = sample;
        }
    }
    
    return (signalMax - signalMin);
}

bool ToneTransceiver::detectFrequencyMatch(uint16_t targetFreq, uint16_t tolerance, uint16_t sampleWindowMs) {
    uint16_t amplitude = readAmplitude(sampleWindowMs);
    // Simple dynamic threshold check for incoming signal activity
    if (amplitude > tolerance) {
        return true;
    }
    return false;
}
