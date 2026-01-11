const int ldrPin = A0;      // LDR connected to analog pin A0
const int ledPin = 8;      // LED connected to digital pin 13
int ldrValue = 0;           // Variable to store LDR reading
int threshold = 500;        // Threshold value (adjust based on your lighting)

void setup() 
{
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start serial communication for monitoring
  
  Serial.println("Adjust threshold value if needed");
}

void loop()
 {
  // Read the LDR value (0-1023)
  ldrValue = analogRead(ldrPin);
  
  // Print value to Serial Monitor for calibration
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  // If light level is below threshold (dark), turn LED on
  if (ldrValue < threshold)
   {
    digitalWrite(ledPin, LOW);  // LED on
    Serial.println("Status: LED ON (Dark detected)");
  } 
  else {
    digitalWrite(ledPin, HIGH);   // LED off
    Serial.println("Status: LED OFF (Light detected)");
  }
  
  delay(1000);  // Wait 500ms before next reading
}
