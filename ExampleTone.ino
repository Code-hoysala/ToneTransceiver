#include <ToneTransceiver.h>

// TX Pin connected to a piezo buzzer/speaker (Digital PWM pin)
// RX Pin connected to a sound/mic sensor module (Analog pin A0)
const int TX_SPEAKER_PIN = 9;
const int RX_MIC_PIN = A0;

ToneTransceiver transceiver(TX_SPEAKER_PIN, RX_MIC_PIN);

void setup() {
    Serial.begin(9600);
    transceiver.begin();
    
    // Transmit an initial out tone at 1000Hz for 500ms
    transceiver.playTone(1000, 500);
}

void loop() {
    // Continuously monitor incoming audio levels (in) while managing output (out)
    uint16_t incomingAmplitude = transceiver.readAmplitude(50); // 50ms sample window
    
    Serial.print("Incoming Audio Amplitude: ");
    Serial.println(incomingAmplitude);

    // Example logic: if loud sound detected in, respond with an out tone
    if (incomingAmplitude > 400) {
        Serial.println("Sound detected! Transmitting response tone...");
        transceiver.playTone(1500, 300); // 1500Hz for 300ms out
    }
}
