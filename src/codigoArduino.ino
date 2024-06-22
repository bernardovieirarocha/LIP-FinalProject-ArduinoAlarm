#include <SoftwareSerial.h>

// Definição dos pinos utilizados no projeto
#define b0 2       // Botão 0
#define b1 3       // Botão 1
#define b2 4       // Botão 2
#define b3 5       // Botão 3
#define led 8      // LED indicador
#define pot A0     // Potenciômetro para ajuste de sensibilidade
#define trig 7     // Pino de disparo do sensor ultrassônico
#define echo 6     // Pino de eco do sensor ultrassônico
#define buzzer 13  // Buzzer para alarme sonoro

int senha[4];      // Array para armazenar a senha de desativação do alarme
double sense = 1.0; // Valor inicial da sensibilidade (ajustável via potenciômetro)

void defSen(); // Protótipo da função para definir a senha

// Função setup, executada uma vez ao reiniciar o Arduino
void setup(){
  pinMode(b0, INPUT_PULLUP); // Configura os botões com resistores de pull-up
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(echo, INPUT);      // Configura o pino de eco como entrada
  pinMode(trig, OUTPUT);     // Configura o pino de disparo como saída
  pinMode(led, OUTPUT);      // Configura o LED como saída
  pinMode(buzzer, OUTPUT);   // Configura o buzzer como saída
  Serial.begin(9600);        // Inicia a comunicação serial a 9600 bps
  defSen();                  // Chama função para definir a senha inicial
}

// Função para verificar se todos os botões estão despressionados
bool allDown(){
  return !(digitalRead(b0) == LOW || digitalRead(b1) == LOW || digitalRead(b2) == LOW || digitalRead(b3) == LOW);
}

// Função para identificar qual botão foi pressionado
int butPress(){
  if (digitalRead(b0) == LOW) return 0;
  else if (digitalRead(b1) == LOW) return 1;
  else if (digitalRead(b2) == LOW) return 2;
  else if (digitalRead(b3) == LOW) return 3;
}

// Função para medir a distância usando o sensor ultrassônico
long measure(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  
  return pulseIn(echo, HIGH);
}

// Função para definir a senha de desativação do alarme
void defSen(){
  while(allDown());
  senha[0] = butPress();
  delay(1000);
  while(allDown());
  senha[1] = butPress();
  delay(1000);
  while(allDown());
  senha[2] = butPress();
  delay(1000);
  while(allDown());
  senha[3] = butPress();
}

// Função para verificar a senha digitada e desativar o alarme
bool lockDown(){
  int i = 0;
  while(i < 4){
    while(allDown());
    if(butPress() == senha[i]) i++;
    else i = 0;
    delay(100);
  }
  return true;
}

// Função loop, executada repetidamente
void loop(){
  sense = 14.62 * analogRead(pot); // Ajusta a sensibilidade com base no potenciômetro
  Serial.println(sense);
  Serial.println(measure());
  Serial.println("-----");
  if(measure() < sense){
    tone(buzzer, 1300);  // Ativa o buzzer
    digitalWrite(led, HIGH);  // Acende o LED
    while(!lockDown());  // Aguarda a senha correta para desativar
    noTone(buzzer);      // Desativa o buzzer
    digitalWrite(led, LOW);  // Apaga o LED
  }  
}
