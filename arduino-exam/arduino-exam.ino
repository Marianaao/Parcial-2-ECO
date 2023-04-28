const int POTEN_PIN = A1;
const int PHOTO_PIN = A3;

const int btn_A_PIN = 2;
const int btn_B_PIN = 3;

int btn_A_value = 0;
int btn_B_value = 0;

int previous_btn_A_value = 0;
int previous_btn_B_value = 0;

int myLEDs[2] = {5, 6};

int actuatorValue = 0;
int previousValue = 0;

/*___________________________________________

1) Set the mode for each Pin.
_____________________________________________ */ 
  


void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial para imprimir información en la consola
  pinMode(btn_A_PIN, INPUT_PULLUP); // Establecer el pin del botón como entrada con resistencia pull-up interna activada
}

void loop() {
  btn_A_value = digitalRead(btn_A_PIN); // Leer el estado del botón

  if (btn_A_value == LOW) { // Si el botón está presionado (estado bajo)
    Serial.println("El botón está presionado"); // Imprimir un mensaje en la consola
    // Aquí puedes agregar cualquier acción adicional que desees realizar cuando se presione el botón
  }

  delay(50); // Esperar un momento antes de leer el estado del botón nuevamente
}

  
  /*___________________________________________

2) Read the value of each pin below
_____________________________________________ */ 

  
    
  if (previousValue != actuatorValue) {
    sendSerialMessage(actuatorValue, btn_A_value, btn_B_value);
    previousValue = actuatorValue;
  }

  if (previous_btn_A_value != btn_A_value) {
    sendSerialMessage(actuatorValue, btn_A_value, btn_B_value);
    previous_btn_A_value = btn_A_value;
  }

    if (previous_btn_B_value != btn_B_value) {
    sendSerialMessage(actuatorValue, btn_A_value, btn_B_value);
    previous_btn_B_value = btn_B_value;
  }

  delay(100);
}

/*___________________________________________

3) Print the value of the actuator and the value of each button.

Example: 
Serial.print(value);
Serial.print(' ');
Serial.println();
_____________________________________________ */ 

void sendSerialMessage(int actuatorValue, int btn_A_value, int btn_B_value) {

  
}

/*___________________________________________

4) Receive the messages sended by the Game.
S is for scoring: If you score a point, both leds should turn on and off
L is for loosing: If you loose, both leds should turn on
_____________________________________________ */ 

void receivingData() {
  char inByte = Serial.read();



  switch(inByte){
    case 'S':
    
      break;
    case 'L':

      break;
  }
  Serial.flush();
}
