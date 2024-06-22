# LIP-FinalProject-ArduinoAlarm
Este repositório contém todos os arquivos necessários para construir e operar um dispositivo de alarme controlado por Arduino. O sistema usa um sensor ultrassônico para detectar a presença de pessoas ou objetos e ativa um buzzer se algo for detectado dentro de uma distância pré-definida. O alarme pode ser desativado através de uma senha inserida usando botões.
## Funcionalidades
* Detecção de Presença: Utiliza um sensor ultrassônico para detectar movimentos.
* Ativação de Alarme: Um buzzer e um LED são ativados ao alertar a presença.
* Desativação de Alarme: Uma senha, inserida através de botões, é necessária para desativar o alarme.
## Esquema de Montagem
O esquema de montagem (.BRD) detalhado pode ser encontrado no diretório schematics junto com a imagem da estrutura, fornecendo uma visão clara de como todos os componentes são interconectados.
![estruturaMontagem](https://github.com/bernardovieirarocha/LIP-FinalProject-ArduinoAlarm/assets/64905090/a425c1b7-a289-4de7-936a-970de135bf8f)
## Código
O diretório src contém todo o código-fonte utilizado no projeto. 
## Configuração e Uso
1. Montagem: Siga o esquema no diretório schematics para conectar todos os componentes no breadboard e ao Arduino.
2. Carregamento do Código: Abra o arquivo codigoArduino.ino no Arduino IDE, conecte seu Arduino ao computador e faça o upload do código.
3. Operação: Ligue o Arduino e defina a senha inicial usando os botões conforme definido no código.
4. Teste: Movimente-se na frente do sensor para testar a detecção e tente desativar o alarme usando a senha correta.
## Relatório do Projeto
Todas as informações sobre o projeto com o detalhamento sobre todas as etapas de desenvolvimento, incluindo a documentação se encontra no arquivo pdf `relatorioProjeto.pdf`
## Vídeo Demonstrativo
https://github.com/bernardovieirarocha/LIP-FinalProject-ArduinoAlarm/assets/64905090/7ca0309b-da7f-4593-bfe5-d719d9a4b715

