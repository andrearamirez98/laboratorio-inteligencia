#include <Servo.h>
#include <LiquidCrystal.h>
#define Pecho 11
#define Ptrig 12
long duracion, distancia;
int ledrojo = 9;
int ledverde = 8;
// Declaramos la variable para controlar el servo
Servo servoMotor;
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
void setup()
{
  // Iniciamos el monitor serie para mostrar el resultado
  lcd.begin(16, 2);
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(13);
  servoMotor.write(0);
  //ultrasonico
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
}
void loop()
{
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion / 2) / 29;
  Serial.print(distancia);
  Serial.println("cm");
  if ((distancia > 10) or (distancia < 0))
  {
    digitalWrite(ledrojo, HIGH);
    digitalWrite(ledverde, LOW);
    // Esperamos 1 segundo
    lcd.clear();
    lcd.print("   Bienvenidos  ");
    lcd.setCursor(0, 1);
    lcd.print("   Conductores  ");
    delay(1000);
    servoMotor.write(0);
  }
  else
  {
    // Desplazamos a la posición 180º
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledrojo, LOW);
    lcd.clear();
    lcd.print("    Porfavor    ");
    lcd.setCursor(0, 1);
    lcd.print("      Siga      ");
    // Esperamos 1 segundo
    servoMotor.write(120);
    delay(1000);
  }
}
