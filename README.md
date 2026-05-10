# LCD-ClimaEsp32-

# LCD Clima ESP32

Projeto desenvolvido com ESP32 utilizando display LCD I2C 20x4 para exibir informações climáticas e horário em tempo real através de APIs online.

---

# Funcionalidades

* Clima em tempo real
* Temperatura atual
* Sensação térmica
* Umidade do ar
* Quantidade de nuvens
* Velocidade do vento
* Direção do vento traduzida
* Pressão atmosférica
* Índice UV
* Relógio em tempo real
* Navegação entre telas usando botão
* Atualização automática dos dados

---

# Tecnologias Utilizadas

* ESP32
* C++
* Arduino Framework
* PlatformIO
* APIs REST
* LCD I2C 20x4
* Wi-Fi
* JSON

---

# Bibliotecas Utilizadas

```cpp
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

---

# Estrutura do Projeto

```text
LCD-ClimaEsp32/
│
├── src/
│   └── main.cpp
│
├── include/
│
├── lib/
│
├── platformio.ini
│
└── README.md
```

---

# Hardware Utilizado

## ESP32

Responsável pela conexão Wi-Fi e processamento dos dados.

## LCD I2C 20x4

Responsável pela exibição das informações climáticas.

Endereço I2C:

```cpp
0x27
```

## Botão

GPIO utilizado:

```cpp
GPIO 0
```

Função:

* trocar telas do display.

---

# APIs Utilizadas

## Clima

https://www.weatherapi.com/

## Hora

https://timeapi.io/

---

# Como Baixar o Projeto

## Opção 1 — Pelo GitHub

Abra o terminal e execute:

```bash
git clone https://github.com/JP-DEV-2302/LCD-ClimaEsp32-.git
```

Depois:

```bash
cd LCD-ClimaEsp32-
```

---

## Opção 2 — Download ZIP

1. Entre no repositório GitHub
2. Clique em:

```text
Code
```

3. Depois:

```text
Download ZIP
```

4. Extraia a pasta.

---

# Como Abrir no VSCode

## 1. Instale o VSCode

https://code.visualstudio.com/

---

## 2. Instale o PlatformIO

https://platformio.org/

Ou:

* Abra VSCode
* Vá em Extensões
* Procure:

```text
PlatformIO IDE
```

* Instale.

---

## 3. Abrir Projeto

No VSCode:

```text
Arquivo → Abrir Pasta
```

Selecione:

```text
LCD-ClimaEsp32-
```

---

# Como Configurar

Abra:

```text
src/main.cpp
```

Altere:

```cpp
const char *WIFI_SSID = "SEU_WIFI";
const char *WIFI_SENHA = "SUA_SENHA";
```

---

# Configurar API

Substitua sua chave aqui:

```cpp
const char *URL_API = "https://api.weatherapi.com/v1/current.json?key=SUA_API_KEY";
```

---

# Como Compilar

No PlatformIO:

## Build

Compila o projeto.

## Upload

Envia para o ESP32.

## Monitor

Abre o monitor serial.

---

# Funcionamento do Sistema

O ESP32:

1. conecta ao Wi-Fi;
2. acessa APIs;
3. recebe dados JSON;
4. processa informações;
5. exibe tudo no LCD.

---

# Sistema de Telas

## Tela 1

* cidade;
* estado;
* hora;
* condição climática.

## Tela 2

* temperatura;
* sensação térmica;
* umidade;
* nuvens.

## Tela 3

* vento;
* direção;
* pressão;
* UV.

---

# Atualização Automática

Os dados são atualizados automaticamente a cada:

```text
30 segundos
```

---

# Tradução da Direção do Vento

O sistema traduz automaticamente:

```text
N  -> Norte
NE -> Nordeste
SW -> Sudoeste
W  -> Oeste
```

---

# Melhorias Futuras

* previsão do tempo;
* gráficos;
* dashboard web;
* aplicativo mobile;
* integração IoT;
* LEDs inteligentes;
* notificações;
* integração com IA.

---

# Autor

Projeto desenvolvido por João Pedro.

---

# Licença

Projeto educacional e experimental.
