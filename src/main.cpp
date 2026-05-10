#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BOTAO 0

LiquidCrystal_I2C lcd(0x27, 20, 4);

const char *WIFI_SSID = "******";
const char *WIFI_SENHA = "*******";

const char *URL_API = "https://api.weatherapi.com/v1/current.json?key=c11009a9d28749e6af4164128261604&q=Sao%20Caetano%20do%20Sul&lang=pt";
const char *URL_HORA = "https://www.timeapi.io/api/Time/current/zone?timeZone=America%2FSao_Paulo";

String cidade, estado, clima, horaStr;
float temp, sensacao;
int umidade, nuvens, pressao;
float vento, uv;
String direcao;

// Controle telas
int telaAtual = 0;
unsigned long ultimoClique = 0;
bool ultimoEstadoBotao = HIGH;

// =========================
// FUNÇÃO DE TRADUÇÃO
String traduzirDirecao(String dir)
{
  if (dir == "N") return "Norte";
  if (dir == "NNE") return "N-Nordeste";
  if (dir == "NE") return "Nordeste";
  if (dir == "ENE") return "E-Nordeste";

  if (dir == "E") return "Leste";
  if (dir == "ESE") return "E-Sudeste";
  if (dir == "SE") return "Sudeste";
  if (dir == "SSE") return "S-Sudeste";

  if (dir == "S") return "Sul";
  if (dir == "SSW") return "S-Sudoeste";
  if (dir == "SW") return "Sudoeste";
  if (dir == "WSW") return "O-Sudoeste";

  if (dir == "W") return "Oeste";
  if (dir == "WNW") return "O-Noroeste";
  if (dir == "NW") return "Noroeste";
  if (dir == "NNW") return "N-Noroeste";

  return dir;
}

// =========================

void conectarWiFi()
{
  WiFi.begin(WIFI_SSID, WIFI_SENHA);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");
}

void obterHora()
{
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;

  http.begin(client, URL_HORA);
  int httpCode = http.GET();

  if (httpCode == 200)
  {
    String resp = http.getString();
    JsonDocument doc;
    deserializeJson(doc, resp);

    int h = doc["hour"];
    int m = doc["minute"];

    horaStr = (h < 10 ? "0" : "") + String(h) + ":" +
              (m < 10 ? "0" : "") + String(m);
  }

  http.end();
}

void obterClima()
{
  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;

  http.begin(client, URL_API);
  int httpCode = http.GET();

  if (httpCode == 200)
  {
    String resp = http.getString();
    JsonDocument doc;
    deserializeJson(doc, resp);

    cidade = doc["location"]["name"].as<String>();
    estado = doc["location"]["region"].as<String>();

    clima = doc["current"]["condition"]["text"].as<String>();

    temp = doc["current"]["temp_c"];
    sensacao = doc["current"]["feelslike_c"];
    umidade = doc["current"]["humidity"];
    nuvens = doc["current"]["cloud"];

    vento = doc["current"]["wind_kph"];
    
    // AQUI A TRADUÇÃO ACONTECE
    direcao = traduzirDirecao(doc["current"]["wind_dir"].as<String>());

    pressao = doc["current"]["pressure_mb"];
    uv = doc["current"]["uv"];
  }

  http.end();
}

void mostrarTela()
{
  lcd.clear();

  switch (telaAtual)
  {
  case 0:
    lcd.setCursor(0, 0);
    lcd.print(cidade);

    lcd.setCursor(0, 1);
    lcd.print(estado);

    lcd.setCursor(0, 2);
    lcd.print(horaStr);

    lcd.setCursor(0, 3);
    lcd.print(clima);
    break;

  case 1:
    lcd.setCursor(0, 0);
    lcd.printf("Temp: %.1f C", temp);

    lcd.setCursor(0, 1);
    lcd.printf("Sens: %.1f C", sensacao);

    lcd.setCursor(0, 2);
    lcd.printf("Umidade: %d%%", umidade);

    lcd.setCursor(0, 3);
    lcd.printf("Nuvens: %d%%", nuvens);
    break;

  case 2:
    lcd.setCursor(0, 0);
    lcd.printf("Vento: %.1f km/h", vento);

    lcd.setCursor(0, 1);
    lcd.print("Dir: " + direcao);

    lcd.setCursor(0, 2);
    lcd.printf("Pressao: %d mb", pressao);

    lcd.setCursor(0, 3);
    lcd.printf("UV: %.1f", uv);
    break;
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(BOTAO, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  conectarWiFi();

  obterHora();
  obterClima();

  mostrarTela();
}

void loop()
{
  bool estadoBotao = digitalRead(BOTAO);

  if (ultimoEstadoBotao == HIGH && estadoBotao == LOW)
  {
    telaAtual++;
    if (telaAtual > 2)
      telaAtual = 0;

    mostrarTela();
    ultimoClique = millis();
    delay(200);
  }

  ultimoEstadoBotao = estadoBotao;

  // Timeout 5s
  if (millis() - ultimoClique > 5000 && telaAtual != 0)
  {
    telaAtual = 0;
    mostrarTela();
  }

  // Atualiza dados a cada 30s
  static unsigned long tempoAtualizacao = 0;
  if (millis() - tempoAtualizacao > 30000)
  {
    obterHora();
    obterClima();
    mostrarTela();
    tempoAtualizacao = millis();
  }
}