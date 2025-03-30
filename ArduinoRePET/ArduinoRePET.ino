#include <U8g2lib.h>
#include <PID_v1.h>


const int DISPLAY_ROTATION = U8G2_R2;

// Init display object
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2( DISPLAY_ROTATION );

const uint8_t ECODECAT[] PROGMEM = {
  0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0xd0, 0x00, 0x00, 0xd8, 0x01, 0x00,
  0xb8, 0x03, 0x00, 0xb8, 0x07, 0x00, 0xbc, 0x0f, 0x00, 0xbc, 0x1f, 0x00,
  0xbc, 0x1f, 0x00, 0x7e, 0x3f, 0x00, 0x7e, 0x3f, 0x38, 0x7e, 0x3f, 0x5e,
  0x7e, 0x3f, 0x6f, 0x7e, 0xbf, 0x77, 0xfe, 0xde, 0x7b, 0xfc, 0xee, 0x7d,
  0xfc, 0xf6, 0x7d, 0xf8, 0xf6, 0x3e, 0xf0, 0x7a, 0x3f, 0xe0, 0xbd, 0x1f,
  0xc0, 0xdd, 0x1f, 0x80, 0xed, 0x0f, 0x00, 0xed, 0x07, 0x00, 0xf4, 0x01
};

const unsigned char TEMP1[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00,
  0x00, 0xe0, 0x7a, 0x00, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0xfc, 0x30,
  0xc0, 0x00, 0x00, 0xfc, 0x19, 0x80, 0x01, 0x00, 0x00, 0x18, 0x82, 0x01,
  0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00,
  0x18, 0x86, 0x01, 0x00, 0xf0, 0x19, 0x86, 0x01, 0x00, 0xf8, 0x19, 0x86,
  0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00,
  0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0xfc, 0x19,
  0x86, 0x01, 0x00, 0xfc, 0x19, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01,
  0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00,
  0x18, 0x86, 0x01, 0x00, 0xf8, 0x19, 0x86, 0x01, 0x00, 0xf0, 0x19, 0x86,
  0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01, 0x00,
  0x00, 0x18, 0x86, 0x01, 0x00, 0x20, 0x18, 0x86, 0x01, 0x00, 0xfe, 0x19,
  0x86, 0x01, 0x00, 0x6c, 0x19, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01,
  0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x1c, 0x86, 0x03, 0x00, 0x00,
  0x0e, 0x06, 0x07, 0x00, 0x00, 0x07, 0x06, 0x06, 0x00, 0x00, 0x83, 0x1f,
  0x0c, 0x00, 0x00, 0xc3, 0x3f, 0x0c, 0x00, 0x80, 0xc1, 0x3f, 0x1c, 0x00,
  0x80, 0xe1, 0x7f, 0x18, 0x00, 0x80, 0xe1, 0x7f, 0x18, 0x00, 0x80, 0xe1,
  0x7f, 0x18, 0x00, 0x80, 0xe1, 0x3f, 0x08, 0x00, 0x00, 0xc3, 0x3f, 0x0c,
  0x00, 0x00, 0x83, 0x1f, 0x0c, 0x00, 0x00, 0x07, 0x02, 0x06, 0x00, 0x00,
  0x06, 0x00, 0x07, 0x00, 0x00, 0x1c, 0x80, 0x03, 0x00, 0x00, 0x38, 0xc0,
  0x01, 0x00, 0x00, 0xf0, 0xfb, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char TEMP2[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00,
  0x00, 0xe0, 0x74, 0x00, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0xfc, 0x30,
  0xc0, 0x00, 0x01, 0xfc, 0x19, 0x80, 0x81, 0x03, 0x00, 0x18, 0x82, 0xc1,
  0x07, 0x00, 0x18, 0x86, 0xe1, 0x0f, 0x00, 0x18, 0x86, 0x71, 0x1b, 0x00,
  0x18, 0x86, 0x39, 0x3b, 0xf0, 0x19, 0x86, 0x8d, 0x31, 0xf8, 0x19, 0x86,
  0x01, 0x01, 0x00, 0x18, 0x86, 0x81, 0x03, 0x00, 0x18, 0x86, 0x01, 0x01,
  0x00, 0x18, 0x86, 0x81, 0x03, 0x00, 0x18, 0x86, 0x01, 0x01, 0xfc, 0x19,
  0x86, 0x81, 0x03, 0xfc, 0x19, 0x86, 0x01, 0x01, 0x00, 0x18, 0x86, 0x81,
  0x03, 0x00, 0x18, 0x86, 0x01, 0x01, 0x00, 0x18, 0x86, 0x81, 0x03, 0x00,
  0x18, 0x86, 0x01, 0x01, 0xf8, 0x19, 0x86, 0x81, 0x03, 0xf0, 0x19, 0x86,
  0x01, 0x01, 0x00, 0x18, 0x86, 0x81, 0x03, 0x00, 0x18, 0x86, 0x01, 0x01,
  0x00, 0x18, 0x86, 0x81, 0x03, 0x10, 0x18, 0x86, 0x01, 0x01, 0xfe, 0x19,
  0x86, 0x01, 0x03, 0x6c, 0x19, 0x86, 0x01, 0x00, 0x00, 0x18, 0x86, 0x01,
  0x00, 0x00, 0x18, 0x86, 0x01, 0x00, 0x00, 0x1c, 0x86, 0x03, 0x00, 0x00,
  0x06, 0x06, 0x07, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x83, 0x0f,
  0x0c, 0x00, 0x00, 0xc3, 0x3f, 0x0c, 0x00, 0x80, 0xc1, 0x3f, 0x0c, 0x00,
  0x80, 0xe1, 0x7f, 0x18, 0x00, 0x80, 0xe1, 0x7f, 0x18, 0x00, 0x80, 0xe1,
  0x7f, 0x18, 0x00, 0x80, 0xe1, 0x3f, 0x08, 0x00, 0x00, 0xc3, 0x3f, 0x0c,
  0x00, 0x00, 0x83, 0x1f, 0x0c, 0x00, 0x00, 0x07, 0x02, 0x0e, 0x00, 0x00,
  0x06, 0x00, 0x06, 0x00, 0x00, 0x1c, 0x80, 0x03, 0x00, 0x00, 0x38, 0xc0,
  0x01, 0x00, 0x00, 0xf0, 0xfb, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

double Temperatura;
int Vo;
float R1 = 1000;  // resistencia fija del divisor de tension
float logR2, R2;
double TEMPERATURA;
double TEMPERATURAPANTALLA;
float c1 = 0, c2 = 0, c3 = 0;
// coeficientes de S-H en pagina:
// http://www.thinksrs.com/downloads/programs/Therm%20Calc/NTCCalibrator/NTCcalculator.htm

int c = 0;
int EN_ANT = LOW;
int ESTAT = 0;
float TEMPERATURAANT = 0;
unsigned long tiempoAnterior = 0;
int contador = 0;
int contador2 = 0;
int tempo = 0;
int conta1 = 0;
int conta2 = 0;

bool firstLoop = true;
double lastTimeUpdated = 0;

double Setpoint;  // will be the desired value
double Input;     //
double Output;    //LED

// PID parameters
double agrKp = 6, agrKi = 0, agrKd = 0;
double conKp = 12, conKi = 0.3, conKd = 0;
double Max = 240;

PID myPID(&Input, &Output, &Setpoint, conKp, conKi, conKd, DIRECT);

const int D0 = 0;  // PWM pin
const int D3 = 3;  // PWM pin

void setup() {
  u8g2.begin();
  u8g2.setDisplayRotation( DISPLAY_ROTATION );

  Serial.begin(9600);
  pinMode(D0, INPUT);

  Setpoint = 220;

  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(D3, Max);
}

void loop() {
  UPDATE_SCREEN();
  THERMISTOR();
  ENABLE();
  PIDCONTROL();
}

void UPDATE_SCREEN() {

  if (firstLoop) {
    show_intro_logo();
    firstLoop = false;
  } else {

    // Update every second
    unsigned long now = millis();
    if( now - lastTimeUpdated > 1000 ) {
      show_status();
      lastTimeUpdated = now;
    }
    
  }
  
}

void ENABLE() {
  int EN = digitalRead(D0);
  if (EN == HIGH && EN_ANT == LOW) {
    c = c + 1;
  }
  EN_ANT = EN;
  if (c % 2 == 0) {
    ESTAT = 0;
  } else {
    ESTAT = 1;
  }
}


void THERMISTOR() {
  Vo = analogRead(A0);                     // lectura de A0
  R2 = R1 * ((1023.0) / (float)Vo - 1.0);  // conversion de tension a resistencia
  logR2 = log(R2);
  // Serial.println(R2);
  if (R2 < 10500) {
    c1 = 1.369358582e-03, c2 = 1.026280639e-04, c3 = 5.585196447e-07;
  } else {
    c1 = -3.532779690e-03, c2 = 8.606773781e-04, c3 = -19.80406727e-07;
  }

  TEMPERATURA = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));  // temperature in Kelvin
  TEMPERATURA = TEMPERATURA - 273.15;                                    // convert Kelvin to Celcius

  // Serial.println(TEMPERATURA);
  if (TEMPERATURA < 0) { 
    TEMPERATURA = 0; 
  }

  if (-2 <= (TEMPERATURA - TEMPERATURAANT) <= 2) {

  } else {
    TEMPERATURA = TEMPERATURAANT;
  }

  TEMPERATURAANT = TEMPERATURA;

  contador = contador + 1;
  if (contador == 5) {
    TEMPERATURAPANTALLA = TEMPERATURA;
    contador = 0;
  }

}



void PIDCONTROL() {

  Input = TEMPERATURA;

  if (ESTAT == 1) {

    contador2 = contador2 + 1;
    if (contador2 == 2) {
      double gap = abs(Setpoint - TEMPERATURA);
      if (gap < 20) {
        myPID.SetTunings(conKp, conKi, conKd);
      } else {
        myPID.SetTunings(agrKp, agrKi, agrKd);
      }
      myPID.Compute();
      contador2 = 0;
    }

    analogWrite(D3, Output);
  }

  if (ESTAT == 0) {
    analogWrite(D3, 0);
  }
}


void show_intro_logo() {

  u8g2.firstPage();

  do {

    u8g2.setFont(u8g2_font_spleen16x32_mu);
    u8g2.setCursor(0, 55);
    u8g2.println("ECODECAT");
    u8g2.drawXBMP(27, 5, 24, 24, ECODECAT);

  } while (u8g2.nextPage());

  delay(1000);

  u8g2.clear();
}

void show_status() {


  u8g2.firstPage();

  do {

    if (TEMPERATURAPANTALLA >= 100) {
      u8g2.setCursor(50, 30);
    } else {
      if (TEMPERATURAPANTALLA < 10) {
        u8g2.setCursor(86, 30);
      } else {
        u8g2.setCursor(68, 30);
      }
    }

    if (TEMPERATURA < 240) {
      u8g2.setFont(u8g2_font_spleen16x32_mu);
      u8g2.println(int(TEMPERATURAPANTALLA));
    } else {
      u8g2.setCursor(50, 30);
      u8g2.setFont(u8g2_font_spleen16x32_mu);
      u8g2.println("MAX!");
    }

    u8g2.setFont(u8g2_font_tinytim_tf);
    u8g2.setCursor(105, 15);
    u8g2.println("O");
    u8g2.setFont(u8g2_font_spleen16x32_mu);
    u8g2.setCursor(112, 30);
    u8g2.println("C");

    u8g2.setCursor(50, 60);
    u8g2.setFont(u8g2_font_spleen16x32_mu);
    u8g2.println(int(Setpoint));
    u8g2.setFont(u8g2_font_tinytim_tf);
    u8g2.setCursor(105, 45);
    u8g2.println("O");
    u8g2.setFont(u8g2_font_spleen16x32_mu);
    u8g2.setCursor(112, 60);
    u8g2.println("C");


    if (ESTAT == 1) {
      if (conta2 < 30) {
        u8g2.drawXBMP(5, -5, 40, 64, TEMP1);
        conta2 = conta2 + 1;
      } else {
        u8g2.drawXBMP(5, -5, 40, 64, TEMP2);
        conta2 = conta2 + 1;
        if (conta2 == 70) {
          conta2 = 0;
        }
      }
    }

  } while (u8g2.nextPage());
}
