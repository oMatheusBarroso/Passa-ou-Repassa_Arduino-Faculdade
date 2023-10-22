//Arduino Uno pins
int presenter = 2;
int player1 = 3;
int player2 = 4;
int led_player1 = 5;
int led_player2 = 6;

//Variáveis de estado dos botões
int state_presenter, state_player1, state_player2;
//IMPORTANTE: Nessa configuração, o estado de ativação do botão e o sinal percebido são invertidos
//   Quando ATIVADO, sinal LOW(0)
//   Quando DESATIVADO, sinal HIGH(1)

//Variáveis de estado de bloqueio dos jogadores
bool block_player1, block_player2;

void setup()
{
  //Configuração dos pinos como entrada ou saída
  
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
  //Confere o estado do botão do apresentador
  state_presenter = digitalRead(presenter);

  //Desbloqueia ambos os jogadores
  block_player1 = false;
  block_player2 = false;

  //Executa o código enquanto o botão do apresentador estiver desativado (HIGH)
  while(state_presenter == HIGH){
    //Confere o estado de todos os botões
  	state_presenter = digitalRead(presenter);
    state_player1 = digitalRead(player1);
    state_player2 = digitalRead(player2);

    //Acende a luz do jogador 1 e bloqueia o jogador 2
    //Condições:
    //  Jogador 1 não bloqueado
    //  Botão do jogador 1 ativado (LOW)
    //  Botão do jogador 2 desativado (HIGH)
    if(block_player1 == false && state_player1 == LOW && state_player2 == HIGH){
      digitalWrite(led_player1,HIGH);
      block_player2 = true;
    }

    //Acende a luz do jogador 2 e bloqueia o jogador 1
    //Condições: 
    //  Jogador 2 não bloqueado
    //  Botão do jogador 2 ativado (LOW)
    //  Botão do jogador 1 desativado (HIGH)
    else if(block_player2 == false && state_player1 == HIGH && state_player2 == LOW){
      digitalWrite(led_player2,HIGH);
      block_player1 = true;
    }
  }

  //Reseta o jogo, apagando todos os LEDs caso o botão do apresentador esteja ativado (LOW)
  if(state_presenter == LOW){
    digitalWrite(led_player1,LOW);
    digitalWrite(led_player2,LOW);
  }
}
