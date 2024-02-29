 int pinReleAbrir = 11; 
 int pinReleCerrar = 12; 
 int pinPulsador = 10; 
 int Delay = 20;
      bool estadoAnteriorPulsador = 0;
 
 unsigned long tiempoApagado = 7000; 

  unsigned long tiempoUltimoCambio = 0;

 int RELE_ENCENDIDO = LOW; 

void setup() {
                
  pinMode(pinReleAbrir, OUTPUT);
  pinMode(pinReleCerrar, OUTPUT);
  pinMode(pinPulsador, INPUT_PULLUP);
  
}

void loop() {
   
   
  if (digitalRead(pinPulsador) == LOW && millis() - tiempoUltimoCambio >= Delay) {
    
  if (digitalRead(pinPulsador) != estadoAnteriorPulsador) {
      abrirOcerrarVentana(); 
      tiempoUltimoCambio = millis(); 
 
    }
    } 
    
   if (millis() - tiempoUltimoCambio >= tiempoApagado){
  digitalWrite(pinReleAbrir, RELE_ENCENDIDO);
  digitalWrite(pinReleCerrar, RELE_ENCENDIDO);
}
}
 void abrirOcerrarVentana() {
 
  if (digitalRead(pinReleAbrir) == RELE_ENCENDIDO) {
   
    digitalWrite(pinReleAbrir, !RELE_ENCENDIDO);
    digitalWrite(pinReleCerrar, RELE_ENCENDIDO); 
  } else {
    
    digitalWrite(pinReleAbrir, RELE_ENCENDIDO); 
    digitalWrite(pinReleCerrar, !RELE_ENCENDIDO); 
  }
 }
