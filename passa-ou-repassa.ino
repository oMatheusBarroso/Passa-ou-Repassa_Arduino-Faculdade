//Arduino Uno pins
int presenter = 2;
int player1 = 3;
int player2 = 4;
int led_player1 = 5;
int led_player2 = 6;

//Variáveis de estado dos botões
int state_presenter, state_player1, state_player2;

bool block_player1, block_player2;

void setup()
{
  //Buttons
  pinMode(presenter, INPUT);
  pinMode(player1, INPUT);
  pinMode(player2, INPUT);
  
  //LEDs
  pinMode(led_player1, OUTPUT);
  pinMode(led_player2, OUTPUT);
}

void loop()
{
  state_presenter = digitalRead(presenter);
  block_player1 = false;
  block_player2 = false;
  
  while(state_presenter == HIGH){
  	state_presenter = digitalRead(presenter);
    state_player1 = digitalRead(player1);
    state_player2 = digitalRead(player2);
    
    if(block_player1 == false && state_player1 == HIGH && state_player2 == LOW){
      digitalWrite(led_player1,HIGH);
      block_player2 = true;
    }
    else if(block_player2 == false && state_player1 == LOW && state_player2 == HIGH){
      digitalWrite(led_player2,HIGH);
      block_player1 = true;
    }
  }
  
  if(state_presenter == LOW){
    digitalWrite(led_player1,LOW);
    digitalWrite(led_player2,LOW);
  }
}
