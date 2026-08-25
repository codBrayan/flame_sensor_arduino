# 🔥 Sistema de Detecção de Chama com Arduino

## 📌 Sobre o projeto

Este projeto consiste no desenvolvimento de um sistema de detecção de chama e acionamento de alarme utilizando um **Arduino Uno**.

O sistema utiliza um sensor de chama para realizar a leitura do ambiente. Quando o valor identificado pelo sensor fica abaixo do limite definido na programação, o Arduino interpreta a situação como uma possível presença de chama e aciona automaticamente o sistema de alarme.

Além da detecção automática, o projeto possui um **botão de acionamento manual**, permitindo ativar ou desativar o alarme diretamente pelo usuário.

## ⚙️ Funcionamento

O sistema funciona da seguinte forma:

1. O sensor realiza a leitura do ambiente.
2. O Arduino Uno recebe o valor do sensor pela entrada analógica **A0**.
3. O programa compara o valor recebido com o limite definido de **400**.
4. Quando o valor do sensor é menor que 400, o sistema identifica uma possível presença de chama.
5. O alarme é ativado automaticamente.
6. O servomotor realiza um movimento de **0° para 90°** e retorna para 0°.
7. O LED e o buzzer são acionados de forma intermitente enquanto o alarme estiver ativo.
8. O botão permite ativar ou desativar o alarme manualmente.

## 🧰 Componentes utilizados

* Arduino Uno
* Sensor de chama
* Servomotor
* Buzzer
* LED
* Botão de acionamento
* Protoboard
* Resistores
* Fios jumper

## 📍 Ligações

| Componente      | Pino do Arduino |
| --------------- | --------------- |
| Sensor de chama | A0              |
| Botão           | D3              |
| LED             | D5              |
| Buzzer          | D8              |
| Servomotor      | D9              |

## 🚨 Detecção de chama

O sensor de chama está conectado à entrada analógica **A0** do Arduino.

O limite utilizado pelo programa é definido pela constante:

```cpp
const int LIMITE_CHAMA = 400;
```

Quando o valor recebido pelo sensor é menor que 400, o sistema ativa o alarme.

```cpp
if (valorA0 < LIMITE_CHAMA && !alarmeAtivo) {
    ativarAlarme();
}
```

Após o acionamento, o sistema permanece em estado de alarme até que o botão seja utilizado para desativá-lo.

## 🔘 Acionamento manual

O botão está conectado ao pino **D3** e permite controlar manualmente o estado do alarme.

Quando o botão é pressionado:

* Se o alarme estiver desligado, ele é ativado.
* Se o alarme estiver ligado, ele é desativado.

Essa função também permite realizar testes do sistema sem a necessidade de detectar uma chama.

## 🔊 Sistema de alarme

O sistema utiliza três dispositivos para realizar o alerta:

### Servomotor

O servomotor está conectado ao pino **D9**. Durante o alarme, ele realiza movimentos entre 0° e 90°.

### LED

O LED está conectado ao pino **D5** e pisca enquanto o alarme está ativo, fornecendo uma indicação visual.

### Buzzer

O buzzer está conectado ao pino **D8** e acompanha o LED, produzindo o alerta sonoro.

## 💻 Código-fonte

O código foi desenvolvido para o **Arduino Uno**, utilizando a linguagem C/C++ e a biblioteca `Servo.h`.

A programação é responsável por:

* realizar a leitura do sensor;
* identificar a presença de chama;
* controlar o estado do alarme;
* realizar a leitura do botão;
* controlar o servomotor;
* controlar o LED;
* controlar o buzzer;
* apresentar informações no Monitor Serial.

O código-fonte completo está disponível neste repositório.

## 🔌 Esquemático

O circuito foi montado utilizando uma protoboard para realizar a conexão entre o Arduino Uno e os componentes.

O esquemático do circuito será disponibilizado neste repositório.

## 📷 Projeto

O protótipo foi desenvolvido utilizando Arduino Uno, sensor de chama, servomotor, buzzer, LED e botão de acionamento.

A imagem da montagem do projeto será adicionada posteriormente.

## 🎥 Demonstração



**

## 🎯 Objetivo

O objetivo do projeto é desenvolver um protótipo capaz de detectar a presença de uma chama e emitir um alerta utilizando sensores, atuadores e programação com Arduino.

O projeto permite aplicar conhecimentos de **eletrônica, programação, sensores, atuadores e automação**.

## 👥 Autores

* Brayan Lima
* Nicólli Gomes

---

**Projeto acadêmico — 2026**
